#include <string>
#include <iostream>
#include "tblock.h"

using namespace std;

TBlock::TBlock(Board *g, int lev) : Block{g, 'T', lev} {
   cells = vector<Cell *> {theBoard->get_cell(1,3), theBoard->get_cell(0,2),
    theBoard->get_cell(1,2), theBoard->get_cell(2,2)};
  for (int i = 0; i < cells.size(); i++) {
    if (cells.at(i)->get_shape() == ' ') {
      cells.at(i)->set_shape('T');
      cells[i]->set_block(this);
    } else {
      cell_success = false;
      return;
    }
  }
  cell_left = 4;
  cell_success = true;
}

TBlock::~TBlock() {}


bool TBlock::clockwise() {
  int col = cells[2]->getCol();
  int row = cells[2]->getRow();
  int c_size = cells.size();
  
  if (which_cell == 0 && theBoard->shapeAt(col, row-1) == ' ') {
    cells[3]->set_shape(' ');
    cells[3]->set_block(nullptr);
    cells[3] = theBoard->get_cell(col, row-1);
    cells[3]->set_shape('T');
    cells[3]->set_block(this);
    ++which_cell;
  } else if (which_cell == 1 && col+1 < theBoard->getWidth() &&
             theBoard->shapeAt(col-1, row+1) == ' ' && 
             theBoard->shapeAt(col+1, row+1) == ' ') {
    for (int i = 1; i < c_size; ++i) {
      if (i != 2) {
        cells[i]->set_shape(' ');
        cells[i]->set_block(nullptr);
      }
    }
    cells[1] = theBoard->get_cell(col-1, row+1);
    cells[3] = theBoard->get_cell(col+1, row+1);
    for (int i = 1; i < c_size; ++i) {
      if (i != 2) {
        cells[i]->set_shape(shape);
        cells[i]->set_block(this);
      }
    }
    ++which_cell;
  } else if (which_cell == 2 && theBoard->shapeAt(col-1, row) == ' '
             && theBoard->shapeAt(col-1, row-1) == ' ') {
    for (int i = 0; i < c_size; ++i) {
      if ((i != 1) && (i != 2)) {
        cells[i]->set_shape(' ');
        cells[i]->set_block(nullptr);
      }
    }
    cells[0] = cells[1];
    cells[1] = theBoard->get_cell(col-1, row);
    cells[3] = theBoard->get_cell(col-1, row-1);
    for (int i = 1; i < c_size; ++i) {
      if (i != 2) {
        cells[i]->set_shape(shape);
        cells[i]->set_block(this);
      }
    }
    ++which_cell;
  } else if (which_cell == 3 && col+1 < theBoard->getWidth() &&
             theBoard->shapeAt(col, row+1) == ' ' && 
             theBoard->shapeAt(col+1, row) == ' ') {
    for (int i = 0; i < c_size; ++i) {
      if ((i != 1) && (i != 2)) {
        cells[i]->set_shape(' ');
        cells[i]->set_block(nullptr);
      }
    }
    cells[0] = theBoard->get_cell(col, row+1);
    cells[3] = theBoard->get_cell(col+1, row);
    for (int i = 0; i < c_size; ++i) {
      if ((i != 1) && (i != 2)) {
        cells[i]->set_shape(shape);
        cells[i]->set_block(this);
      }
    }
    which_cell = 0;
  } else return false;
  return true;
}


bool TBlock::counter() {
  int col = cells[2]->getCol();
  int row = cells[2]->getRow();
  int c_size = cells.size();
  
  if (which_cell == 0 && theBoard->shapeAt(col-1, row+1) == ' ' &&
      theBoard->shapeAt(col-1, row-1) == ' ') {
    for (int i = 0; i < c_size; ++i) {
      if ((i != 1) && (i != 2)) {
        cells[i]->set_shape(' ');
        cells[i]->set_block(nullptr);
      }
    }
    cells[0] = theBoard->get_cell(col-1, row+1);
    cells[3] = theBoard->get_cell(col-1, row-1);
    for (int i = 0; i < c_size; ++i) {
      if ((i != 1) && (i != 2)) {
        cells[i]->set_shape(shape);
        cells[i]->set_block(this);
      }
    }
    which_cell = 3;
  }
  else if (which_cell == 1 && col+1 < theBoard->getWidth() &&
           theBoard->shapeAt(col+1, row) == ' ') {
    cells[3]->set_shape(' ');
    cells[3]->set_block(nullptr);
    cells[3] = theBoard->get_cell(col+1, row);
    cells[3]->set_shape('T');
    cells[3]->set_block(this);
    --which_cell;
  } else if (which_cell == 2 && theBoard->shapeAt(col-1, row) == ' ' &&
             theBoard->shapeAt(col, row-1) == ' ') {
    for (int i = 1; i < c_size; ++i) {
      if (i != 2) {
        cells[i]->set_shape(' ');
        cells[i]->set_block(nullptr);
      }
    }
    cells[1] = theBoard->get_cell(col-1, row);
    cells[3] = theBoard->get_cell(col, row-1);
    for (int i = 1; i < c_size; ++i) {
      if (i != 2) {
        cells[i]->set_shape(shape);
        cells[i]->set_block(this);
      }
    }
    --which_cell;
  } else if (which_cell == 3 && col+1 < theBoard->getWidth() &&
             theBoard->shapeAt(col, row+1) == ' ' && 
             theBoard->shapeAt(col+1, row+1) == ' ') {
    for (int i = 1; i < c_size; ++i) {
      if (i != 2) {
        cells[i]->set_shape(' ');
        cells[i]->set_block(nullptr);
      }
    }
    cells[1] = cells[0];
    cells[0] = theBoard->get_cell(col, row+1);
    cells[3] = theBoard->get_cell(col+1, row+1);
    for (int i = 0; i < c_size; ++i) {
      if ((i != 1) && (i != 2)) {
        cells[i]->set_shape(shape);
        cells[i]->set_block(this);
      }
    }
    --which_cell;
  } else return false;
  return true;
}

