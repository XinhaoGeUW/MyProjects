#include "specheavy.h"

const int FAIL = 0;
const int SUCCESS = 1;
const int DROP = 2;

SpecHeavy::SpecHeavy(Command *a): SpecCommand{a} {}

int SpecHeavy::right(Block *b) {
  int right = currCom->right(b);
  if (right == FAIL) return FAIL;
  if (right == DROP) return DROP;
  if (currCom->down(b) == FAIL) return DROP; 
  if (currCom->down(b) == FAIL) return DROP;
  return SUCCESS;
}

int SpecHeavy::left(Block *b) {
  int left = currCom->left(b);
  if (left == FAIL) return FAIL;
  if (left == DROP) return DROP;
  if (currCom->down(b) == FAIL) return DROP; 
  if (currCom->down(b) == FAIL) return DROP;
  return SUCCESS;
}

