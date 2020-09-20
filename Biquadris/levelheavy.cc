#include "levelheavy.h"

const int FAIL = 0;
const int SUCCESS = 1;
const int DROP = 2;

LevelHeavy::LevelHeavy(Command *a): SpecCommand{a} {}

int LevelHeavy::left(Block *b) {
  int left = currCom->left(b);
  if (left == FAIL) return FAIL;
  else if (left == DROP) return DROP;
  if (currCom->down(b) == FAIL) return DROP;
  return SUCCESS;
}

int LevelHeavy::right(Block *b) {
  int right = currCom->right(b);
  if (right == FAIL) return FAIL;
  else if (right == DROP) return DROP;
  if (currCom->down(b) == FAIL) return DROP;
  return SUCCESS;
}

int LevelHeavy::clockwise(Block *b) {
  int cl = currCom->clockwise(b);
  if (cl == FAIL) return FAIL;
  else if (cl == DROP) return DROP;
  if (currCom->down(b) == FAIL) return DROP;
  return SUCCESS;
}

int LevelHeavy::counter(Block *b) {
  int cc = currCom->counter(b);
  if (cc == FAIL) return FAIL;
  else if (cc == DROP) return DROP;
  if (currCom->down(b) == FAIL) return DROP;
  return SUCCESS;
}
