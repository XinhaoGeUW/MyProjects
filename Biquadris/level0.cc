#include "level0.h"
#include "Command.h"
#include "lowerlevel.h"
using namespace std;

Level0::Level0(string file): blocks {ifstream (file)} {}

char Level0::createnext(int ID) {
  char c;
  blocks >> c;
  return c;
}

Command *Level0::createCommand() {
  Command *a = new lowerlevel();
  return a;
}

void Level0::num_move(Board *) {}

Level0::~Level0() {}
