#include "sblock.h"
using namespace std;

SBlock::SBlock(Board *g, int lvl) : Block{g, 'S', lvl} {
    cells = vector<Cell *> {theBoard->get_cell(1,3), theBoard->get_cell(1,2),
                           theBoard->get_cell(0,3), theBoard->get_cell(2,2)};
   for (int i = 0; i < cells.size(); i++) {
    if (cells.at(i)->get_shape() == ' ') {
      cells.at(i)->set_shape('S');
      cells[i]->set_block(this);
    } else {
      cell_success = false;
      return;
    }
  }
  cell_left = 4;
  cell_success = true;
}

SBlock::~SBlock() {}


bool SBlock::clockwise() {
    int x = cells[1]->getCol();
    int y = cells[1]->getRow();
    int c_size = cells.size();
    
    if ((which_cell == 0 || which_cell == 2) && 
        theBoard->shapeAt(x-1, y) == ' ' &&
        theBoard->shapeAt(x-1, y-1) == ' ') {
        for (int i = 2; i < c_size; ++i) {
            cells[i]->set_shape(' ');
            cells[i]->set_block(nullptr);
            if (i == 2) {
                cells[i] = theBoard->get_cell(x-1, y);
            } else {
                cells[i] = theBoard->get_cell(x-1, y-1);
            }
            cells[i]->set_shape(shape);
            cells[i]->set_block(this);
        }
        ++which_cell;
    } else if ((which_cell == 1 || which_cell == 3) && 
             x+1 < theBoard->getWidth() &&
             theBoard->shapeAt(x-1, y+1) == ' ' &&
             theBoard->shapeAt(x+1, y) == ' ') {
        for (int i = 2; i < c_size; ++i) {
            cells[i]->set_shape(' ');
            cells[i]->set_block(nullptr);
            if (i == 2) {
                cells[i] = theBoard->get_cell(x-1, y+1);
            } else {
                cells[i] = theBoard->get_cell(x+1, y);
            }
            cells[i]->set_shape(shape);
            cells[i]->set_block(this);
        }
             if (which_cell == 1) {
                 ++which_cell;
             }
             else if (which_cell == 3) {
                 which_cell = 0;
             }
    }
    else return false;
    return true;
}

bool SBlock::counter() {
    int x = cells[1]->getCol();
    int y = cells[1]->getRow();
    int c_size = cells.size();
    
    if ((which_cell == 0 || which_cell == 2) && 
        theBoard->shapeAt(x-1, y) == ' ' &&
        theBoard->shapeAt(x-1, y-1) == ' ') {
        for (int i = 2; i < c_size; ++i) {
            cells[i]->set_shape(' ');
            cells[i]->set_block(nullptr);
            if (i == 2) {
                cells[i] = theBoard->get_cell(x-1, y);
            } else {
                cells[i] = theBoard->get_cell(x-1, y-1);
            }
            cells[i]->set_shape(shape);
            cells[i]->set_block(this);
        }
        
        
        if (which_cell == 0) {
            which_cell = 3;
        }
        else if (which_cell == 2) {
            --which_cell;
        }
    }
    else if ((which_cell == 1 || which_cell == 3) && 
             x+1 < theBoard->getWidth() &&
             theBoard->shapeAt(x-1, y+1) == ' ' &&
             theBoard->shapeAt(x+1, y) == ' ') {
             for (int i = 2; i < c_size; ++i) {
            cells[i]->set_shape(' ');
            cells[i]->set_block(nullptr);
            if (i == 2) {
                cells[i] = theBoard->get_cell(x-1, y+1);
            } else {
                cells[i] = theBoard->get_cell(x+1, y);
            }
            cells[i]->set_shape(shape);
            cells[i]->set_block(this);
        }
         --which_cell;
    }
    else return false;
    return true;
}

