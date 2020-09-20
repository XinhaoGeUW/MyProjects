#ifndef _LEVEL2_H
#define _LEVEL2_H

#include "level.h"

class Level2: public Level {
  public:
    char createnext(int ID) override;
    Command *createCommand() override;
    void num_move(Board *) override;
};

#endif
