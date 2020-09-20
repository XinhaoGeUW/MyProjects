////////////////////////
  #include <string>
  #include "block.h"
  
  using namespace std;

Block::Block(Board *b, char c, int lev) : which_cell{0}, theBoard{b}, shape{c}, cell_left{0},
ini_lev{lev}, cell_success {false}, blinded{false} {}

Block::~Block() {
}

void Block::removeFromBoard() {
  for (int i = 0; i < cells.size(); i++) {
    cells[i]->set_shape(' ');
    cells[i]->set_block(nullptr);
  }
}

void Block::set_cell_left(int i) {
  cell_left = i;
}

int Block::get_cell_left() {
  return cell_left;
}

void Block::set_cell(int i, Cell *cell) {
  cells[i] = cell;
}

bool Block::onBoard() { return cell_success; }

bool Block::right() {
  int col1,row1,col2,row2,col3,row3,col4,row4;
  int width = theBoard->getWidth();
  vector<Cell *> oldcells = cells;
  col1 = cells[0]->getCol();
  row1 = cells[0]->getRow();
  col2 = cells[1]->getCol();
  row2 = cells[1]->getRow();
  col3 = cells[2]->getCol();
  row3 = cells[2]->getRow();
  col4 = cells[3]->getCol();
  row4 = cells[3]->getRow();
  
  if (((col1+1 == col2 && row1 == row2) || (col1+1 == col3 && row1 == row3) || (col1+1 == col4 && row1 == row4) ||
       (col1+1 < width && theBoard->shapeAt(col1+1, row1) == ' ')) &&
      ((col2+1 == col1 && row1 == row2) || (col2+1 == col3 && row3 == row2) || (col2+1 == col4 && row4 == row2) ||
       (col2+1 < width && theBoard->shapeAt(col2+1, row2) == ' ')) &&
      ((col3+1 == col2 && row3 == row2) || (col3+1 == col1 && row1 == row3) || (col3+1 == col4 && row3 == row4) ||
       (col3+1 < width && theBoard->shapeAt(col3+1, row3) == ' ')) &&
      ((col4+1 == col2 && row4 == row2) || (col4+1 == col3 && row4 == row3) || (col4+1 == col1 && row1 == row4) ||
       (col4+1 < width && theBoard->shapeAt(col4+1, row4) == ' '))) {
    for(int i = 0; i < cells.size(); i++) {
      cells[i]->set_shape(' ');
      cells[i]->set_block(nullptr);
    }
    cells[0] = theBoard->get_cell(col1+1, row1);
    cells[1] = theBoard->get_cell(col2+1, row2);
    cells[2] = theBoard->get_cell(col3+1, row3);
    cells[3] = theBoard->get_cell(col4+1, row4);
    for(int i = 0; i < cells.size(); i++) {
      cells[i]->set_shape(shape);
      cells[i]->set_block(this);
    }
    return true;
  }
  return false;
}

bool Block::left() {
  int col1,row1,col2,row2,col3,row3,col4,row4;
  
  vector<Cell *> oldcells = cells;
  col1 = cells[0]->getCol();
  row1 = cells[0]->getRow();
  col2 = cells[1]->getCol();
  row2 = cells[1]->getRow();
  col3 = cells[2]->getCol();
  row3 = cells[2]->getRow();
  col4 = cells[3]->getCol();
  row4 = cells[3]->getRow();
  
  if (((col1-1 == col2 && row1 == row2) || (col1-1 == col3 && row1 == row3) || (col1-1 == col4 && row1 == row4) ||
       (col1-1 >= 0 && theBoard->shapeAt(col1-1, row1) == ' ')) &&
      ((col2-1 == col1 && row1 == row2) || (col2-1 == col3 && row3 == row2) || (col2-1 == col4 && row4 == row2) ||
       (col2-1 >= 0 && theBoard->shapeAt(col2-1, row2) == ' ')) &&
      ((col3-1 == col2 && row3 == row2) || (col3-1 == col1 && row1 == row3) || (col3-1 == col4 && row3 == row4) ||
       (col3-1 >= 0 && theBoard->shapeAt(col3-1, row3) == ' ')) &&
      ((col4-1 == col2 && row4 == row2) || (col4-1 == col3 && row4 == row3) || (col4-1 == col1 && row1 == row4) ||
       (col4-1 >= 0 && theBoard->shapeAt(col4-1, row4) == ' '))) {
    for(int i = 0; i < cells.size(); i++) {
      cells[i]->set_shape(' ');
      cells[i]->set_block(nullptr);
    }
    cells[0] = theBoard->get_cell(col1-1, row1);
    cells[1] = theBoard->get_cell(col2-1, row2);
    cells[2] = theBoard->get_cell(col3-1, row3);
    cells[3] = theBoard->get_cell(col4-1, row4);
    for(int i = 0; i < cells.size(); i++) {
      cells[i]->set_shape(shape);
      cells[i]->set_block(this);
    }
    return true;
  }
  return false;
}


bool Block::down() {
  int col1,row1,col2,row2,col3,row3,col4,row4;
  int height = theBoard->getHeight();
  
  vector<Cell *> oldcells = cells;
  col1 = cells[0]->getCol();
  row1 = cells[0]->getRow();
  col2 = cells[1]->getCol();
  row2 = cells[1]->getRow();
  col3 = cells[2]->getCol();
  row3 = cells[2]->getRow();
  col4 = cells[3]->getCol();
  row4 = cells[3]->getRow();
  
  if (((row1+1 == row2 && col1 == col2) || (row1+1 == row3 && col1 == col3) || (row1+1 == row4 && col1 == col4) ||
       (row1+1 < height && theBoard->shapeAt(col1, row1+1) == ' ')) &&
      ((row2+1 == row1 && col2 == col1) || (row2+1 == row3 && col2 == col3) || (row2+1 == row4 && col2 == col4) ||
       (row2+1 < height && theBoard->shapeAt(col2, row2+1) == ' ')) &&
      ((row3+1 == row2 && col3 == col2) || (row3+1 == row1 && col3 == col1) || (row3+1 == row4 && col3 == col4) ||
       (row3+1 < height && theBoard->shapeAt(col3, row3+1) == ' ')) &&
      ((row4+1 == row2 && col4 == col2) || (row4+1 == row3 && col4 == col3) || (row4+1 == row1 && col4 == col1) ||
       (row4+1 < height && theBoard->shapeAt(col4, row4+1) == ' '))) {
    
    for(int i = 0; i < cells.size(); i++) {
      cells[i]->set_shape(' ');
      cells[i]->set_block(nullptr);
    }
    cells[0] = theBoard->get_cell(col1, row1+1);
    cells[1] = theBoard->get_cell(col2, row2+1);
    cells[2] = theBoard->get_cell(col3, row3+1);
    cells[3] = theBoard->get_cell(col4, row4+1);
    for(int i = 0; i < cells.size(); i++) {
      cells[i]->set_shape(shape);
      cells[i]->set_block(this);
    }
    return true;
  }
  return false;
}

void Block::drop() {
  while (down());
}

int Block::get_ini_lev() {
  return ini_lev;
}

void Block::paint_block() {
  if (!(blinded)) {
    for(int i = 0; i < cells.size(); i++) {
      cells[i]->paint();
    }
  } else {
    for (int i = 0; i < cells.size(); i++) {
      if (cells[i]->getCol() < 2 || cells[i]->getCol() > 8) {
        cells[i]->paint();
      }
    }
  }
}

void Block::unpaint_block() {
  if (!(blinded)) {
    for(int i = 0; i < cells.size(); i++) {
      cells[i]->unpaint();
    }
  } else {
    for (int i = 0; i < cells.size(); i++) {
      if (cells[i]->getCol() < 2 || cells[i]->getCol() > 8) {
        cells[i]->unpaint();
      }
    }
  }
}

void Block::set_blind(bool b) {
  blinded = b;
}
