#ifndef _LEVEL_H
#define _LEVEL_H

#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"

class Command;

class Level {
  public:
    virtual char createnext(int ID) = 0;
    virtual Command *createCommand() = 0;
    virtual void num_move(Board *) = 0;
    virtual ~Level() {};
};

#endif
