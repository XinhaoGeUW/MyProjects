#include "level4.h"
#include "levelheavy.h"
#include <cstdlib>
#include "cell.h"
#include "lowerlevel.h"
#include <iostream>
#include <time.h>

using namespace std;

char Level4::createnext(int ID) {
  char c;
  srand(time(nullptr));
  int n = rand() % 9;
  if (n == 0 || n == 1) c = 'S';   
  if (n == 2 || n == 3) c = 'Z';           
  if (n == 4) c = 'T';              
  if (n == 5) c = 'L';
  if (n == 6) c = 'J';
  if (n == 7) c = 'O';
  if (n == 8) c = 'I';
  return c;
}

Command *Level4::createCommand() {
  Command *c = new LevelHeavy(new lowerlevel);
  return c;
}

void Level4::num_move(Board *g) {
  int count = g->not_cleanNum();
  if (count != 0 && count  % 5 == 0) {
    int center = g->getWidth();
    int height = g->getHeight();
    
    for (int i = 0; i < height; i++) {
      if (g->shapeAt(center, i) == ' ' &&     
          ((g->shapeAt(center, i < height - 1 ? i+1 : i) != ' ' && 
            i+1 < height) ||(i+1 == height))) {
                g->setAt(center, i, '*');
                g->get_cell(center, i)->paint();
                break;
            }
        }
    }
}
