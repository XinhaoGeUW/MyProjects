#include <string>
#include <iostream>
#include "iblock.h"

using namespace std;

IBlock::IBlock(Board *g, int lev) : Block{g, 'I', lev} {
   cells = vector<Cell *> {theBoard->get_cell(0, 3), theBoard->get_cell(1, 3), theBoard->get_cell(2, 3), theBoard->get_cell(3, 3)};
  for (int i = 0; i < cells.size(); i++) {
    if (cells.at(i)->get_shape() == ' ') {
      cells.at(i)->set_shape('I');
      cells[i]->set_block(this);
    } else {
      cell_success = false;
      return;
    }
  }
  cell_left = 4;
  cell_success = true;
}

IBlock::~IBlock() {}


bool IBlock::spin(Cell *Lowerleft, int direction) {
  
  int col = Lowerleft->getCol();
  int row = Lowerleft->getRow();
  
  int col2, col3, col4, row2, row3, row4 = 0;
  
  if (direction == 0 || direction == 2) {
    col2 = col + 1;
    col3 = col + 2;
    col4 = col + 3;
    
    row2 = row;
    row3 = row;
    row4 = row; 
  }
  else if (direction == 1 || direction == 3) {
    row2 = row - 1;
    row3 = row - 2;
    row4 = row - 3;
    
    col2 = col;
    col3 = col;
    col4 = col; 
  }
  
  if (col4 < theBoard->getWidth() && theBoard->shapeAt(col2, row2) == ' ' 
      && theBoard->shapeAt(col3, row3) == ' ' && theBoard->shapeAt(col4, row4) == ' ') {
    for (int i = 1; i < cells.size(); i++) {
      cells[i]->set_block(nullptr);
      cells[i]->set_shape(' ');
    }
    
    cells[1] = theBoard->get_cell(col2, row2);
    cells[2] = theBoard->get_cell(col3, row3);
    cells[3] = theBoard->get_cell(col4, row4);
    for (int i = 1; i < cells.size(); i++) {
      cells[i]->set_shape('I');
      cells[i]->set_block(this);
    }
    return true;
  }
  return false;
}

bool IBlock::clockwise() {
  if (which_cell == 0) {
    ++which_cell;
  }
  else if (which_cell == 1) {
    ++which_cell;
  }
  else if (which_cell == 2) {
    ++which_cell;
  }
  else if (which_cell == 3) {
    which_cell = 0;
  }
  
  return spin(cells[0], which_cell);
}

bool IBlock::counter() {
  if (which_cell == 0) {
    which_cell = 3;
  }
  else if (which_cell == 1) {
    which_cell = 0;
  }
  else if (which_cell == 2) {
    which_cell = 1;
  }
  else if (which_cell == 3) {
    which_cell = 2;
  }
  
  return spin(cells[0], which_cell);
}
