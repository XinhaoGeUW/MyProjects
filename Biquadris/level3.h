#ifndef _LEVEL3_H
#define _LEVEL3_H

#include "level.h"

class Level3: public Level {
  public:
    Level3();
    char createnext(int ID);
    Command *createCommand();
    void num_move(Board *);
};

#endif
