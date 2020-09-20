#ifndef _LEVEL0_H
#define _LEVEL0_H

#include "level.h"

class Level0: public Level {
    std::ifstream blocks;
  public:
    Level0(std::string file);
    char createnext(int ID) override;
    Command *createCommand() override;
    void num_move(Board *) override;
    ~Level0();
};

#endif
