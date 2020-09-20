#include "level2.h"
#include "lowerlevel.h"
#include <cstdlib>
#include <time.h>

char Level2::createnext(int ID) {
  char c;
  srand(time(nullptr));
  int n = rand() % 7;
  if (n == 0) c = 'S';  
  if (n == 1) c = 'Z';           
  if (n == 2) c = 'T';
  if (n == 3) c = 'L';
  if (n == 4) c = 'J';
  if (n == 5) c = 'O';
  if (n == 6) c = 'I';
  return c;
}

Command *Level2::createCommand() {
  Command *a = new lowerlevel();
  return a;
}

void Level2::num_move(Board *) {}
