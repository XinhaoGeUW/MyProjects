#include "oblock.h"
using namespace std;

OBlock::OBlock(Board *g, int lev) : Block{g, 'O', lev} {
  cells = vector<Cell *> {theBoard->get_cell(0, 3), theBoard->get_cell(1, 3), theBoard->get_cell(0, 2), theBoard->get_cell(1,2)};
  for (int i = 0; i < cells.size(); i++) {
    if (cells.at(i)->get_shape() == ' ') {
      cells.at(i)->set_shape('O');
      cells[i]->set_block(this);
    } else {
      cell_success = false;
      return;
    }
  }
  cell_left = 4;
  cell_success = true;
}

OBlock::~OBlock() {}


bool OBlock::clockwise() {return false;}

bool OBlock::counter() {return false;}

