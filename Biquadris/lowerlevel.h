#ifndef _LOWERLEVEL_H
#define _LOWERLEVEL_H

#include "Command.h"

class lowerlevel: public Command {
    public:
        char displaychar() override; 
        int left(Block *) override;
        int right(Block *) override;
        int down(Block *) override;
        void drop(Block *) override;
        int clockwise(Block *) override;
        int counter(Block *) override;
};

#endif
