#include "lowerlevel.h"
#include "block.h"


char lowerlevel::displaychar() {return '\0';}

int lowerlevel::left(Block *b) {
  if (b->left()) return 1;
  return 0;
}

int lowerlevel::right(Block *b) {
  if (b->right()) return 1;
  return 0;
}

int lowerlevel::down(Block *b) {
  if (b->down()) return 1;
  return 0;
}

void lowerlevel::drop(Block *b) {b->drop();}

int lowerlevel::clockwise(Block *b) {
  if (b->clockwise()) return 1;
  return 0;
}

int lowerlevel::counter(Block *b) {
  if (b->counter()) return 1;
  return 0;
}
