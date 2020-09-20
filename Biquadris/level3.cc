#include "level3.h"
#include "levelheavy.h"
#include <cstdlib>
#include "lowerlevel.h"
#include <time.h>

Level3::Level3() {}

char Level3::createnext(int ID) {
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

Command *Level3::createCommand() {
    Command *a = new LevelHeavy(new lowerlevel);
    return a;
}

void Level3::num_move(Board *) {}
