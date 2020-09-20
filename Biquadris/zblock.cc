#include "zblock.h"
using namespace std;

ZBlock::ZBlock(Board *g, int lev) : Block{g, 'Z', lev} {
 cells = vector<Cell *> {theBoard->get_cell(0,2), theBoard->get_cell(1,2),
    theBoard->get_cell(1,3), theBoard->get_cell(2,3)};
  for (int i = 0; i < cells.size(); i++) {
    if (cells.at(i)->get_shape() == ' ') {
      cells.at(i)->set_shape('Z');
      cells[i]->set_block(this);
    } else {
      cell_success = false;
      return;
    }
  }
  cell_left = 4;
  cell_success = true;
}

ZBlock::~ZBlock() {}


bool ZBlock::clockwise() {
  int col = cells[1]->getCol();
  int row = cells[1]->getRow();
  int c_size = cells.size();
  
  if ((which_cell == 0 || which_cell == 2) && 
      theBoard->shapeAt(col-1, row+1) == ' ' &&
      theBoard->shapeAt(col, row-1) == ' ') {
    for (int i = 2; i < c_size; ++i) {
      cells[i]->set_shape(' ');
      cells[i]->set_block(nullptr);
      if (i == 2) {
        cells[i] = theBoard->get_cell(col-1, row+1);
      } else {
        cells[i] = theBoard->get_cell(col, row-1);
      }
      cells[i]->set_shape(shape);
      cells[i]->set_block(this);
    }
    ++which_cell;
  } else if ((which_cell == 1 || which_cell == 3) &&
             col+1 < theBoard->getWidth() &&
             theBoard->shapeAt(col, row+1) == ' ' &&
             theBoard->shapeAt(col+1, row+1) == ' ') {
    for (int i = 2; i < c_size; ++i) {
      cells[i]->set_shape(' ');
      cells[i]->set_block(nullptr);
      if (i == 2) {
        cells[i] = theBoard->get_cell(col, row+1);
      } else {
        cells[i] = theBoard->get_cell(col+1, row+1);
      }
      cells[i]->set_shape(shape);
      cells[i]->set_block(this);
    }
    if (which_cell == 1) {
      ++which_cell;
    }
    else if (which_cell == 3) {
      which_cell = 0;
    } else return false;
    return true;
  }
}

bool ZBlock::counter() {
  int col = cells[1]->getCol();
  int row = cells[1]->getRow();
  int c_size = cells.size();
  
  if ((which_cell == 0 || which_cell == 2) && 
      theBoard->shapeAt(col-1, row+1) == ' ' &&
      theBoard->shapeAt(col, row-1) == ' ') {
    for (int i = 2; i < c_size; ++i) {
      cells[i]->set_shape(' ');
      cells[i]->set_block(nullptr);
      if (i == 2) {
        cells[i] = theBoard->get_cell(col-1, row+1);
      } else {
        cells[i] = theBoard->get_cell(col, row-1);
      }
      cells[i]->set_shape(shape);
      cells[i]->set_block(this);
    }
    if (which_cell == 0) {
      which_cell = 3;
    } else if (which_cell == 2) {
      --which_cell;
    }
  } else if ((which_cell == 1 || which_cell == 3) &&
             col+1 < theBoard->getWidth() &&
             theBoard->shapeAt(col, row+1) == ' ' &&
             theBoard->shapeAt(col+1, row+1) == ' ') {
    for (int i = 2; i < c_size; ++i) {
      cells[i]->set_shape(' ');
      cells[i]->set_block(nullptr);
      if (i == 2) {
        cells[i] = theBoard->get_cell(col, row+1);
      } else {
        cells[i] = theBoard->get_cell(col+1, row+1);
      }
      cells[i]->set_shape(shape);
      cells[i]->set_block(this);
    }
    --which_cell;
  } else {
    return false;
  }
  return true;
}
