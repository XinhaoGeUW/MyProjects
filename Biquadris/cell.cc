#include "cell.h"
#include "block.h"

using namespace std;


Cell::Cell(int row, int col, Xwindow *xwin) : posn{Posn(row,col)}, shape{' '}, block{nullptr}, c_view{xwin} {}

Cell::~Cell() {}

char Cell::get_shape() {
  return shape;
}

void Cell::set_shape(char c) {
  shape = c;
}

int Cell::getRow() {
  return posn.c;
}

void Cell::setRow(int i) {
  posn.c = i;
}

int Cell::getCol() {
  return posn.r;
}

void Cell::setCol(int i) {
  posn.r = i;
}

Block *Cell::get_block() {
  return block;
}

void Cell::set_block(Block *bp) {
  block = bp;
}

void Cell::paint() {
  if (c_view) {
    if (shape == 'I') {
      c_view->fillRectangle(10 + posn.r * 30, 90 + posn.c * 30, 30, 30, Xwindow::DarkGreen);
    }
    else if (shape == 'L') {
      c_view->fillRectangle(10 + posn.r * 30, 90 + posn.c * 30, 30, 30, Xwindow::Orange);
    }
    else if (shape == 'Z') {
      c_view->fillRectangle(10 + posn.r * 30, 90 + posn.c * 30, 30, 30, Xwindow::Cyan);
    }
    else if (shape == 'S') {
      c_view->fillRectangle(10 + posn.r * 30, 90 + posn.c * 30, 30, 30, Xwindow::Blue);
    }
    else if (shape == 'O') {
      c_view->fillRectangle(10 + posn.r * 30, 90 + posn.c * 30, 30, 30, Xwindow::Brown);
    }
    else if (shape == 'T') {
      c_view->fillRectangle(10 + posn.r * 30, 90 + posn.c * 30, 30, 30, Xwindow::Yellow);
    }
    else if (shape == 'J') {
      c_view->fillRectangle(10 + posn.r * 30, 90 + posn.c * 30, 30, 30, Xwindow::Red);
    }
    else if (shape == '*') {
      c_view->fillRectangle(10 + posn.r * 30, 90 + posn.c * 30, 30, 30, Xwindow::Brown);
    }
  }
}

void Cell::unpaint() {
  if (c_view) {
    c_view->fillRectangle(10 + posn.r * 30, 90 + posn.c * 30, 30, 30, Xwindow::White);
  }
}
