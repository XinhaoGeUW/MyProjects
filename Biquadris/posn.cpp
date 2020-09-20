#include <cstddef>
#include "posn.h"

using namespace std;

Posn::Posn(int r, int c) : r{r}, c{c} {}

bool Posn::operator==(const Posn &rhs) const {
  if ((r == rhs.r) && (c == rhs.c)) {
    return true;
  } else {
    return false;
  }
}

void Posn::setR(const int row)  {
  r = row;
}

void Posn::setC(const int col) {
  c = col;
}