#include "game.h"
#include "player.h"
#include "Board.h"
using namespace std;


Game::Game(int num, int ID, bool textOnly): total_participator {0}, top_score{0},
                                            textOnly{textOnly}, ID{ID}, init_num{num} {
    for (int i=0; i<num; i++) newMan(ID, textOnly);
}

Game::~Game() {
    currPlayer = nullptr;
    while (total_participator) {
        delete players.back();
        players.erase(players.end()-1);
        total_participator--;
    }
}

Player *Game::manipulator() {
    return currPlayer;
}

void Game::nextTurn() {
    bool found = false;

    for (int i = 0; i < total_participator; i++) {
        if (players[i] == currPlayer && i + 1 < total_participator) {
            currPlayer = players[i+1];
            found = true;
            break;
        }
        else if (players[i] == currPlayer && i + 1 == total_participator) {
            currPlayer = players[0];
            found = true;
            break;
        }
    }

    if (!found) {
        Player *p = currPlayer;

        for (int i = 0; i < total_participator; i++) {
            if (players[i]->getID() > currPlayer->getID()) {
                currPlayer = players[i];
                break;
            }
        }

        if (currPlayer == p) {
            currPlayer = players[0];
        }
    }
}

int Game::count_survivor() {
    return total_participator;
}

void Game::newMan(int ID, bool textOnly) {
    Player *p = new Player(++total_participator, this, "", ID, textOnly);
    p->getBoard()->set_topPoints(top_score);
    players.push_back(p);
    if (players.size() == 1) {
        currPlayer = p;
    }
}

bool Game::kill_loser(int id) {
    for (int i=0; i < total_participator; i++) {
        if (id == players[i]->getID()) {
            delete players[i];
            players.erase(players.begin() + i);
            total_participator--;
            return true;
        }
    }
    return false;
}

void Game::alter_survivor(int id, string Command, char block) {
    for (int i=0; i<total_participator; i++) {
        if (id == players[i]->getID()) {
            players[i]->setCommand(Command, block);
            break;
        }
    }
}

void Game::mark() {
    for (int i=0; i<total_participator; i++) {
        players[i]->endTurn();
    }
}

int Game::final_survivor_func() {
    int highestScore = 0;
    Player *winner = nullptr;
    for (int i = 0; i < total_participator; i++) {
        int score = players[i]->getScore();
        if (total_participator == 1 || score > highestScore) {
            winner = players[i];
            highestScore = score;
        }
    }
    return ((winner && (winner->getScore() >= top_score || top_score == 0)) ? winner->getID() : final_survivor);
}

void Game::outLoser(Player *p) {
    for (int i = 0; i < total_participator; i++) {
        if (players[i] == p) {
            cout << "Player " << p->getID() << " is out!" << endl;
            if (p->getScore() >= top_score || top_score == 0) {
                top_score = p->getScore();
                final_survivor = p->getID();
            }

            players.erase(players.begin() + i);
            total_participator--;
        }
    }
}

bool Game::isAlive(Player *p) {
    for (int i = 0; i < total_participator; i++) {
        if (players[i] == p) return true;
    }
    return false;
}

void Game::Initial_f(int id, std::string file) {
    for (int i=0; i<total_participator; i++) {
        if (id == players[i]->getID()) {
            players[i]->set_input(file);
            break;
        }
    }
}

string Game::displayLevels() const {
    string text = "";
    int width;
    for (int i=0; i<total_participator; i++) {
        width = players[i]->getBoard()->getWidth();

        text += "Level:";
        string level = to_string(players[i]->getLevel());
        int numSpaces = width - 6 - level.length();

        for (int j=0; j<numSpaces; j++)
            text += " ";
        text += level;

        if (i+1 != total_participator)
            text += "      ";

        else text += "\n";
    }
    return text;
}

string Game::displayScores() const {
    string text = "";
    int width;
    for (int i=0; i<total_participator; i++) {
        width = players[i]->getBoard()->getWidth();

        text += "Score:";
        string score = to_string(players[i]->getScore());
        int numSpaces = width - 6 - score.length();

        for (int j=0; j<numSpaces; j++)
            text += " ";
        text += score;

        if (i+1 != total_participator) {
            text += "      ";
        }
        else text += "\n";
    }
    return text;
}

string Game::displayBoards() const {
    string text = "";
    int height = players[0]->getBoard()->getHeight();
    for (int i=-1; i<=height; i++) {
        for (int j=-1; j<total_participator-1; j++) {
            string row = players[j+1]->displayline(i);
            text += row;
            if (j+1 != total_participator-1) {
                text += "      ";
            }
            else {
                text += "\n";
            }
        }
    }
    return text;
}

static string displayI(int row) {
    string text = "";
    if (row == 0)
        text += "Next:";
    else if (row == 2)
        text += "IIII";
    return text;
}

static string displayJ(int row) {
    string text = "";
    if (row == 0)
        text += "Next:";
    else if (row == 1)
        text += "J";
    else if (row == 2)
        text += "JJJ";
    return text;
}

static string displayL(int row) {
    string text = "";
    if (row == 0)
        text += "Next:";
    else if (row == 1)
        text += "  L";
    else if (row == 2)
        text += "LLL";
    return text;
}

static string displayO(int row) {
    string text = "";
    if (row == 0)
        text += "Next:";
    else if (row == 1)
        text += "OO";
    else if (row == 2)
        text += "OO";
    return text;
}

static string displayS(int row) {
    string text = "";
    if (row == 0)
        text += "Next:";
    else if (row == 1)
        text += " SS";
    else if (row == 2)
        text += "SS";
    return text;
}

static string displayZ(int row) {
    string text = "";
    if (row == 0)
        text += "Next:";
    else if (row == 1)
        text += "ZZ";
    else if (row == 2)
        text += " ZZ";
    return text;
}

static string displayT(int row) {
    string text = "";
    if (row == 0)
        text += "Next:";
    else if (row == 1)
        text += "TTT";
    else if (row == 2)
        text += " T";
    return text;
}

string Game::displayNexts() const {
    string text = "";
    int width;
    for (int row = 0; row < 3; row++) {
        for (int i=0; i<total_participator; i++) {
            string block;
            width = players[i]->getBoard()->getWidth();
            char blockShape = players[i]->getNextBlockShape();

            if (blockShape == 'I')
                block = displayI(row);
            else if (blockShape == 'J')
                block = displayJ(row);
            else if (blockShape == 'L')
                block = displayL(row);
            else if (blockShape == 'O')
                block = displayO(row);
            else if (blockShape == 'S')
                block = displayS(row);
            else if (blockShape == 'Z')
                block = displayZ(row);
            else if (blockShape == 'T')
                block = displayT(row);

            text += block;
            int numSpaces = width - block.length();

            for (int j=0; j<numSpaces; j++)
                text += " ";

            if (i+1 != total_participator) {
                text += "      ";
            }
            else text += "\n";
        }
    }
    return text;
}

string Game::prettydisplay() const {
    string text = "";
    text += displayLevels();
    text += displayScores();
    text += displayBoards();
    text += displayNexts();
    return text;
}

void Game::restart() {
    for (int i = total_participator - 1; i >= 0; i--) {
        int score = players[i]->getScore();
        if (score > top_score)
            top_score = players[i]->getScore();
        delete players[i];
        players.pop_back();
    }

    total_participator = 0;

    for (int i = 0; i < init_num; i++) {
        newMan(ID, textOnly);
    }
}

void Game::modify_HS() {
    int score = currPlayer->getScore();
    if (score > top_score) {
        top_score = score;
        for (int j=0; j<total_participator; j++)
            players[j]->getBoard()->set_topPoints(top_score);
    }
}

ostream &operator<<(ostream& out, const Game &game) {
    out << game.prettydisplay();
    return out;
}

