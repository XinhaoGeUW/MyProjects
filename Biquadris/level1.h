#ifndef _LEVEL1_H
#define _LEVEL1_H

#include "level.h"

class Level1: public Level {
  public:
    Level1();
    char createnext(int ID) override;
    Command *createCommand() override;
    void num_move(Board *) override;
};

#endif
