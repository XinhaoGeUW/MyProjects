#include "Controller.h"
#include "prev_controller.h"
#include "player.h"

using namespace std;

const int DROP = 2;

void assignSeqFiles(Game *currGame, string seq1, string seq2);
void levelUpEveryone(Game *currGame, int startlev);

Controller::Controller(long int ID, string seq1, string seq2, int startlev, bool textOnly, int total_participator, int maxLevel): contr{new prev_controller{}}, 
currGame{nullptr}, ID{ID}, seq1{seq1}, seq2{seq2}, startlev{startlev}, textOnly{textOnly}, total_participator{total_participator}, maxLevel{maxLevel <= 0 ? 1 : maxLevel} {
  
  if (startlev == 0 && total_participator <= 2) {
    currGame = new Game{total_participator, ID, textOnly};
    assignSeqFiles(currGame, seq1, seq2);
  }
  else {
    currGame = new Game{total_participator, ID, textOnly};
    
    levelUpEveryone(currGame, startlev);
  }
  
  currGame->mark();
  cout << *currGame << endl;
}

void assignSeqFiles(Game *currGame, string seq1, string seq2) {
  if (seq1 != "") currGame->Initial_f(1, seq1);
  else currGame->Initial_f(1, "sequence1.txt");
  if (seq2 != "") currGame->Initial_f(2, seq2);
  else currGame->Initial_f(2, "sequence2.txt");
}

void levelUpEveryone(Game *currGame, int startlev) {
  for (int i = 0; i < currGame->count_survivor(); i++) {
    for (int j = 0; j < startlev; j++) {
      currGame->manipulator()->levelup();
    }
    
    currGame->nextTurn();
  }
}

void handleSpecCommand(Game *currGame, int filledRows) {
  if (filledRows >= 2) {
    string s;
    cout << "You have cleared " << filledRows << " rows. Please choose a special Command (heavy/force/blind):" << endl;
    
    cin >> s;
    while (s != "heavy" && s != "blind" && s != "force") {
      cout << "Not a valid special Command. Please choose one from heavy, blind, or force." << endl;
      cin >> s;
    }
    
    char block = '\0';
    if (s == "force") {
      while (block != 'T' && block != 'O' && block != 'S' && block != 'Z' && block != 'I' && block != 'J' && block != 'L') {
        cout << "Please enter a valid block to force on your opponent:" << endl;
        cin >> block;
      }
    }
    
    int id = -1;
    
    cout << "Please enter the player's id on whom you would like to apply " << s << ": "<<  endl;
    cin >> id;
    while (id < 1 || id > currGame->count_survivor() || id == currGame->manipulator()->getID()) {
      cout << "Please enter a valid id that isn't your own:" << endl;
      cin >> id;
    }
    
    currGame->manipulator()->afterEffect(id, s, block);
  }
}

bool Controller::exec_inst(string s) {
  string arg;
  string commandName;
  
  int filledRows = 0;
  
  if (s == "rename") {
    
    string args;
    string arg;
    vector<string> inst;
    getline(cin, args);
    istringstream argStream{args};
    
    while (argStream >> arg) {
      inst.emplace_back(arg);
    }
    
    commandName = inst.back();
    inst.pop_back(); 
    
    map<string, vector<string> *> previnst = contr->inst; 
    for (auto elem : previnst) {
      for (int i = 0; i < inst.size(); i++) {
        if (elem.first == inst[i]) {
          if (inst.size() == 1 && elem.second->size() == 1) elem.second->pop_back();
          elem.second->emplace_back(commandName);
        }
      }
    }
  }
  if (s == "left" || s == "right" || s == "down") {
    if ((s == "left" && currGame->manipulator()->left() == DROP) ||
        (s == "right" && currGame->manipulator()->right() == DROP) ||
        (s == "down" && currGame->manipulator()->down() == DROP))
    {
      s = "drop";	
    }
    else cout << *currGame << endl;
  }
  if (s == "clockwise" || s == "counterclockwise") {
    Player *p = currGame->manipulator();
    
    if ((s == "clockwise" && p->clockwise() == DROP) ||
        (s == "counterclockwise" && p->counter() == DROP))
      s = "drop";
    cout << *currGame << endl;
  }
  if (s == "drop") {
    currGame->manipulator()->drop();
    currGame->manipulator()->getCurrBlock()->paint_block();
    filledRows = currGame->manipulator()->getBoard()->fullRows();
    currGame->modify_HS();
    currGame->manipulator()->endTurn();
    cout << *currGame << endl;
    
    handleSpecCommand(currGame, filledRows); 
    
    if (currGame->count_survivor() == 0) {
      cout << "Player " << currGame->final_survivor_func() << " has won the game!" << endl;
      delete currGame->manipulator();
      throw 1;
    }
    else {
      Player *p = currGame->manipulator();
      
      currGame->nextTurn();
      if (!currGame->isAlive(p)) delete p;
    }
    return true;
  }
  if (s == "leveldown" || s == "levelup") {
    Player *p = currGame->manipulator();
    
    if (s == "leveldown" && (currGame->count_survivor() <= 2 || p->getLevel() > 1)) 
      p->leveldown();
    else if (currGame->count_survivor() > 2 && s == "leveldown") 
      cout << "Can't access level 0 with more than 2 players in the game!" << endl;
    else {
      if (p->getLevel() < maxLevel)
        p->levelup();
    }
    
    cout << "New level: " << currGame->manipulator()->getLevel() << endl;
    cout << *currGame << endl;
  }
  
  Player *p = currGame->manipulator();
  if (s == "norandom" && (p->getLevel() == 3 || p->getLevel() == 4)) {
    string fileName;
    cin >> fileName;
    
    p->set_input(fileName);
  }
  
  if (s == "random" && (p->getLevel() == 3 || p->getLevel() == 4)) {
    p->set_input("");
  }
  
  if (s == "sequence") {
    string fileName;
    cin >> fileName;
    
    cout << fileName << endl;
    try {
      if (file.is_open()) file.close();
      file.open(fileName);
    } catch (...) {
      cout << "unknown error opening file" << endl;
    } 
  }
  if (s == "restart") {
    currGame->restart();
    if (startlev == 0 && total_participator <= 2) assignSeqFiles(currGame, seq1, seq2);
    else levelUpEveryone(currGame, startlev);
    
    currGame->mark();
    cout << *currGame << endl;
  }
  if (s == "I" || s == "J" || s == "L" || s == "O" ||
      s == "S" || s == "T" || s == "Z") {
    currGame->manipulator()->getBoard()->eliminate_next(currGame->manipulator()->getNextBlockShape());
    currGame->manipulator()->setNextBlockShape(s[0]);
    currGame->manipulator()->getBoard()->display_next(s[0]);
    cout << *currGame << endl;
  }
  return false;
}

void Controller::mod() {
  string s;
  int instMatched = 0;
  string recentCommand;
  int multiplier = 0;
  
  map<string, vector<string> *> inst = contr->inst;
  
  while ((file.is_open() && file >> s) || cin >> s) {
    istringstream checkForInt{s};
    
    checkForInt >> multiplier >> s;
    
    for (auto elem : inst) {
      if (s == elem.first || s == elem.first.substr(0, s.length())) {
        instMatched++;
        recentCommand = elem.first;
      }
    }
    if (instMatched == 1 && recentCommand != "") {
      if (s != "restart" && s != "hint" && s != "norandom" && s != "random") {
        if (multiplier == 0) {
          currGame->manipulator()->getCurrBlock()->unpaint_block();
          exec_inst(recentCommand);
          currGame->manipulator()->getCurrBlock()->paint_block();	
        }
        else {
          if (recentCommand == "drop") {
            for (int i = 0; i < multiplier; i++) {
              currGame->manipulator()->getCurrBlock()->unpaint_block();
              try {
                exec_inst(recentCommand);
              } catch (int n) {
                if (n == 1) throw 2;
              }
              currGame->manipulator()->getCurrBlock()->paint_block();
            }
          }
          else {
            currGame->manipulator()->getCurrBlock()->unpaint_block();
            for (int i = 0; i < multiplier; i++) {
              try {
                if (exec_inst(recentCommand)) break;
              } catch (int n) {
                if (n == 1) throw 2;
              }
            }	
            currGame->manipulator()->getCurrBlock()->paint_block();
          }
        }
      }
      else {
        try {
          exec_inst(recentCommand);
        } catch (int n) {
          if (n == 1) throw 2;
        }
      }
    }
    else {
      vector<string> loc;
      for (auto elem : inst) {
        for (auto alias : *elem.second) {
          if (s == alias) {
            loc.emplace_back(elem.first);
          }
        }
      }

      if (loc.size() == 0) {
        cout << "Please enter a valid command." << endl;
      }
      else {
        if (multiplier == 0) multiplier = 1;
        for (int i = 0; i < multiplier; i++) {
          for (auto str : loc) {
            try {
              if (exec_inst(str)) break;
            } catch (int n) {
              if (n == 1) throw 2;
            }
          }
        }
      }
    }
    instMatched = 0; 
  }
}

Controller::~Controller() {
  auto inst = contr->getinst();

  for (auto it = inst.begin(); it != inst.end(); it++) {
    delete it->second;
  }
  delete contr;
  delete currGame;
}
