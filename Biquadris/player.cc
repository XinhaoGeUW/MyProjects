#include "player.h"
#include "Board.h"
#include "game.h"
#include "Command.h"
#include "block.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "blind.h"
#include "specheavy.h"
#include "specCommand.h"
#include "lowerlevel.h"
#include "tblock.h"
#include "sblock.h"
#include "iblock.h"
#include "oblock.h"
#include "jblock.h"
#include "lblock.h"
#include "zblock.h"

using namespace std;

Player::Player(int id, Game *game, string file, int ID, bool textOnly): 
  theBoard {new Board(textOnly)}, playerId {id}, theGame {game}, 
current_Command {new lowerlevel}, current_block {nullptr}, next_block{'\0'},
level {new Level0{file}}, currentlevel {0}, desire_input {file}, ID {ID}
{theBoard->init(currentlevel);} 

Player::~Player() {
  delete level;
  delete current_Command;
  delete theBoard; 
}

string Player::displayline(int i) {
  string output = "";
  int height = theBoard->getHeight();
  string row = theBoard->displayline(i);
  if (current_Command->displaychar() == '?' &&
      (i > 3 && i <= height - 6)) 
  { 
    current_block->set_blind(true);
    theBoard->blind();
    int len = row.length();
    for (int j = 0; j < len; j++) {
      if (j > 1 && j < 9) 
        output += "?";
        else
          output += row[j];
    }
  }
  else output = row;
  return output;
}

void Player::setBoard(Board *b) {
  theBoard = b;
}

Board *Player::getBoard() {
  return theBoard;
}

void Player::levelup() {
  currentlevel++;
  if (currentlevel > 5) currentlevel = 5;
  else {
    delete level;
    if (currentlevel == 1) level = new Level1();
    else if (currentlevel == 2) level = new Level2();
    else if (currentlevel == 3) level = new Level3();
    else if (currentlevel == 4) level = new Level4();
  }
  theBoard->display_level(currentlevel);
  theBoard->setlevel(currentlevel);
}

void Player::leveldown() {
  currentlevel--;
  if (currentlevel < 0) currentlevel = 0;
  else {
    delete level;
    if (currentlevel == 0) level = new Level0(desire_input);
    else if (currentlevel == 1) level = new Level1();
    else if (currentlevel == 2) level = new Level2();
    else if (currentlevel == 3) level = new Level3();
    else if (currentlevel == 4) level = new Level4();
  }
  theBoard->display_level(currentlevel);
  theBoard->setlevel(currentlevel);
}

void Player::createnext() {
  next_block = level->createnext(ID);
}

void Player::setCommand(string s, char b) {
  if (s == "force") {
    force(b);
  }
  else if (s == "blind") {
    current_Command = new Blind(current_Command);
  }
  else if (s == "heavy") {
    current_Command = new SpecHeavy(current_Command);
  }
}

void Player::afterEffect(int playerId, string Command, char b) {
  theGame->alter_survivor(playerId, Command, b);
}

Block *Player::getCurrBlock() {
  return current_block;
}

void createBlock(Board *theBoard, int currentlevel, Block **current_block, char *next_block, char block, Game* theGame, Player* p) {
  if (block == 'T')
    *current_block = new TBlock(theBoard, currentlevel);
    else if (block == 'O')
      *current_block = new OBlock(theBoard, currentlevel);
      else if (block == 'I')
        *current_block = new IBlock(theBoard, currentlevel);
        else if (block == 'S')
          *current_block = new SBlock(theBoard, currentlevel);
          else if (block == 'J')
            *current_block = new JBlock(theBoard, currentlevel);
            else if (block == 'L')
              *current_block = new LBlock(theBoard, currentlevel);
              else if (block == 'Z')
                *current_block = new ZBlock(theBoard, currentlevel);
                
                (*current_block)->paint_block();
                theBoard->more_Block(**current_block);
                
                if (!((*current_block)->onBoard())) {
    theGame->outLoser(p);
  }
}

void Player::setNextBlockShape(char b) {
  next_block = b;
}

void Player::endTurn() {
  theBoard->eliminate_next(next_block);
  char block;
  if (desire_input != "" && (currentlevel == 0 || currentlevel == 3 || currentlevel == 4)) {
    if (!f.is_open()) {
      f.open(desire_input);
    }

    if (next_block == '\0')
      f >> next_block;

    block = next_block;
    f >> next_block;
    
    if (f.eof()) {
      f.clear();
      f.seekg(0, ios::beg);
      f >> next_block;
    }

    createBlock(theBoard, currentlevel, &current_block, &next_block, block, theGame, this);
  }
  else {
    if (next_block == '\0') block = level->createnext(ID);
    else {
      block = next_block;
    }

    createBlock(theBoard, currentlevel, &current_block, &next_block, block, theGame, this);
    next_block = level->createnext(ID);
  }
  if (current_Command->displaychar() == '?') {
    theBoard->unblind();
  }
  delete current_Command;
  current_Command = level->createCommand();
  theBoard->display_next(next_block);
}

int Player::getID() {
  return playerId; 
}

int Player::getLevel() {
  return currentlevel;
}

int Player::getScore() {
  return theBoard->getscore();
}

char Player::getNextBlockShape() {
  return next_block;
}

void Player::set_input(std::string s) {
  desire_input = s;
}

int Player::right() {
    return current_Command->right(current_block);
}

int Player::left() {
    return current_Command->left(current_block);
}

int Player::down() {
    return current_Command->down(current_block);
}

void Player::drop() {
    current_Command->drop(current_block);
    level->num_move(theBoard);
}

int Player::clockwise() {
  return current_Command->clockwise(current_block);
}

int Player::counter() {
  return current_Command->counter(current_block);
}

void Player::force(char new_cell) {
  current_block->unpaint_block();
  if (new_cell == 'I') {
    current_block->removeFromBoard();
    delete current_block;
    current_block = new IBlock(theBoard, currentlevel);
  }
  else if (new_cell == 'J') {
    current_block->removeFromBoard();
    delete current_block;
    current_block = new JBlock(theBoard, currentlevel);
  }
  else if (new_cell == 'L') {
    current_block->removeFromBoard();
    delete current_block;
    current_block = new LBlock(theBoard, currentlevel);
  }
  else if (new_cell == 'O') {
    current_block->removeFromBoard();
    delete current_block;
    current_block = new OBlock(theBoard, currentlevel);
  }
  else if (new_cell == 'S') {
    current_block->removeFromBoard();
    delete current_block;
    current_block = new SBlock(theBoard, currentlevel);
  }
  else if (new_cell == 'T') {
    current_block->removeFromBoard();
    delete current_block;
    current_block = new TBlock(theBoard, currentlevel);
  }
  else if (new_cell == 'Z') {
    current_block->removeFromBoard();
    delete current_block;
    current_block = new ZBlock(theBoard, currentlevel);
  }
  else return;
  
  current_block->paint_block();

  if (!(current_block->onBoard())) {
  theGame->outLoser(this);
                }
}
