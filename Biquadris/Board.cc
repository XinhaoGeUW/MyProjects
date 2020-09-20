#include <string>
#include "Board.h"
#include "block.h"
#include "cmath"

using namespace std;

Board::Board(bool textOnly) : board_view{textOnly ? nullptr : new Xwindow{350, 730}} {}

Board::~Board() {
  delete board_view;
  int BlocksNum = BlocksInBoard.size();
  for (int i = 0; i < BlocksNum; i++) {
    if (BlocksInBoard[i]) {
      delete BlocksInBoard[i];
      BlocksInBoard[i] = nullptr;
    }
  }
}

void Board::init(int l, int w, int h) {
  if (w < 4) w = 4;   
  if (h < 7) h = 7;   
  level = l;
  score = 0;
  top_score = 0;
  not_clean = 0;
  maxCol = w;
  maxRow = h;
  
  if (board_view) {
    board_view->drawLine(9, 89, 341, 89);
    board_view->drawLine(9, 89, 9, 631);
    board_view->drawLine(9, 631, 341, 631);
    board_view->drawLine(341, 89, 341, 631);
    board_view->drawStringFont(10, 20, "Level:", "8x16");
    board_view->drawStringFont(10, 45, "Score:", "8x16");
    board_view->drawStringFont(10, 70, "Highest Score:", "8x16", Xwindow::Brown);
    board_view->drawStringFont(10, 655, "Next Block:", "8x16");
    string score_str = to_string(score);
    string level_str = to_string(level);
    string topPoints_str = to_string(top_score);
    board_view->drawStringFont(60, 20, score_str, "8x16");
    board_view->drawStringFont(60, 45, level_str, "8x16");
    board_view->drawStringFont(125, 70, topPoints_str, "8x16", Xwindow::Brown);
  }
  
  
  for (int i = 0; i < h; i++) {
    vector<Cell> row;
    for (int j = 0; j < w; j++) {
      Cell c {j, i, board_view};
      row.emplace_back(c);
    }
    theBoard.emplace_back(row);
  }
}

bool Board::isRowFull(const int row) {
  bool rowFull = true;
  for (int col = 0; col <= maxCol; ++col) {
    if (theBoard[row][col].get_shape() == ' ') {
      rowFull = false;
      break;
    }
  }
  return rowFull;
}

void Board::clearRow(const int row) {
  for (int a = 0; a < maxCol; ++a) {
    theBoard[row][a].unpaint();
  }
  theBoard[row].clear();
  theBoard.erase(theBoard.begin() + row);
  vector<Cell> newRow;
  for (int q = 0; q < maxCol; ++q) {
    newRow.emplace_back(Cell{q, 0, board_view});
  }
  theBoard.insert(theBoard.begin(), newRow);
  this->update();  
}

int Board::fullRows() {
    int  rowsCleared= 0;
    for (int row = 0; row < maxRow; ++row) {
       bool rowFull = isRowFull(row);
        if (rowFull) {
            ++rowsCleared;
            for (int k = 0; k < maxCol; ++k) {
                if (theBoard[row][k].get_block()) {
                    int num = (theBoard[row][k].get_block())->get_cell_left(); 
                    if (num == 1) {
                        score += pow((theBoard[row][k].get_block())->get_ini_lev() + 1, 2);
                        display_score(score);
                        theBoard[row][k].get_block()->set_cell_left(num - 1);

                    }
                    else {
                        theBoard[row][k].get_block()->set_cell_left(num - 1);
                    }
                }
             }
            clearRow(row);
        }
    }

    if (rowsCleared == 0) {
        ++not_clean;
    } else {
        score += pow(level + rowsCleared, 2);
        display_score(score);
        not_clean = 0;
    }
    if (score > top_score) {
        display_topPoints(score);
        top_score = score;
    }
    return rowsCleared;
}
void Board::update() {
    for (int i = maxRow - 1; i > 0 ; --i) {
        for (int j = 0; j < maxCol; ++j) {
            theBoard[i][j].unpaint();
            theBoard[i][j].setCol(j);
            theBoard[i][j].setRow(i);
            theBoard[i][j].paint();
        }
    }
}
string Board::displayline(int i) {
    string s = "";
    for (int j = 0; j < maxCol; ++j) {
        if (i >= 0 && i < maxRow){
            char c = shapeAt(j, i);
            s += c;
        }
        else s += '-';
    }
    return s;
}

int Board::getHeight() {
    return maxRow;
}

int Board::getWidth() {
    return maxCol;
}

char Board::shapeAt(int x, int y) {
    return theBoard[y][x].get_shape();
}

void Board::setAt(int x, int y, char shape) {
    theBoard[y][x].set_shape(shape);
}

void Board::updatescore(int s) {
    score = s;
}

int Board::getscore() {
    return score;
}

int Board::not_cleanNum() {
    return not_clean;
}

void Board::setlevel(int l) {
    level = l;
}

int Board::getlevel() {
    return level;
}

Cell *Board::get_cell(int x, int y) {
    return &(theBoard[y][x]);
}

int Board::return_top_score() {
    return top_score;
}

void Board::display_score(int s) {
    if (board_view) {
        string score_str = to_string(score);
        string new_score_str = to_string(s);
        board_view->drawStringFont(60, 45, score_str, "8x16", Xwindow::White);
        board_view->drawStringFont(60, 45, new_score_str, "8x16");
    }
}

void Board::display_level(int lev) {
    if (board_view) {
        string level_str = to_string(level);
        string new_level_str = to_string(lev);
        board_view->drawStringFont(60, 20, level_str, "8x16", Xwindow::White);
        board_view->drawStringFont(60, 20, new_level_str, "8x16");
    }
}

void Board::display_topPoints(int hs) {
    if (board_view) {
        string hs_str = to_string(top_score);
        string new_hs_str = to_string(hs);
        board_view->drawStringFont(125, 70, hs_str, "8x16", Xwindow::White);
        board_view->drawStringFont(125, 70, new_hs_str, "8x16", Xwindow::Brown);
    }
}

void Board::display_next(char c) {
    if (board_view) {
        if (c == 'I') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::DarkGreen);
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::DarkGreen);
            board_view->fillRectangle(210, 638, 30, 30, Xwindow::DarkGreen);
            board_view->fillRectangle(240, 638, 30, 30, Xwindow::DarkGreen);
        }
        else if (c == 'L') {
            board_view->fillRectangle(210, 638, 30, 30, Xwindow::Orange);
            board_view->fillRectangle(150, 668, 30, 30, Xwindow::Orange);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::Orange);
            board_view->fillRectangle(210, 668, 30, 30, Xwindow::Orange);
        }
        else if (c == 'Z') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::Cyan);
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::Cyan);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::Cyan);
            board_view->fillRectangle(210, 668, 30, 30, Xwindow::Cyan);
        }
        else if (c == 'S') {
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::Blue);
            board_view->fillRectangle(210, 638, 30, 30, Xwindow::Blue);
            board_view->fillRectangle(150, 668, 30, 30, Xwindow::Blue);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::Blue);
        }
        else if (c == 'O') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::Brown);
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::Brown);
            board_view->fillRectangle(150, 668, 30, 30, Xwindow::Brown);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::Brown);
        }
        else if (c == 'T') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::Yellow);
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::Yellow);
            board_view->fillRectangle(210, 638, 30, 30, Xwindow::Yellow);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::Yellow);
        }
        else if (c == 'J') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::Red);
            board_view->fillRectangle(150, 668, 30, 30, Xwindow::Red);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::Red);
            board_view->fillRectangle(210, 668, 30, 30, Xwindow::Red);
        }
    }
}

void Board::eliminate_next(char c) {
    if (board_view) {
        if (c == 'I') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(210, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(240, 638, 30, 30, Xwindow::White);
        }
        else if (c == 'L') {
            board_view->fillRectangle(210, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(150, 668, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::White);
            board_view->fillRectangle(210, 668, 30, 30, Xwindow::White);
        }
        else if (c == 'Z') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::White);
            board_view->fillRectangle(210, 668, 30, 30, Xwindow::White);
        }
        else if (c == 'S') {
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(210, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(150, 668, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::White);
        }
        else if (c == 'O') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(150, 668, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::White);
        }
        else if (c == 'T') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(210, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::White);
        }
        else if (c == 'J') {
            board_view->fillRectangle(150, 638, 30, 30, Xwindow::White);
            board_view->fillRectangle(150, 668, 30, 30, Xwindow::White);
            board_view->fillRectangle(180, 668, 30, 30, Xwindow::White);
            board_view->fillRectangle(210, 668, 30, 30, Xwindow::White);
        }
    }
}

void Board::blind() {
    if (board_view)
        board_view->fillRectangle(70, 210, 210, 270, Xwindow::Black);
}

void Board::more_Block(Block &b) {
    BlocksInBoard.emplace_back(&b);
}

void Board::unblind() {
    if (board_view) {
        for (int i = 4; i < 13; ++i) {
            for (int j = 2; j < 9; ++j) {
                if (theBoard[i][j].get_shape() == ' ') {
                    theBoard[i][j].unpaint();
                }
                else {
                    theBoard[i][j].paint();
                }
            }
        }
    }
}


void Board::set_topPoints(int s) {
    display_topPoints(s);
    top_score = s;
}
