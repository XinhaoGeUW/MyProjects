#ifndef _LEVEL4_H
#define _LEVEL4_H

#include "level.h"

class Level4: public Level {
  public:
    char createnext(int ID);
    Command *createCommand();
    void num_move(Board *);
};

#endif
