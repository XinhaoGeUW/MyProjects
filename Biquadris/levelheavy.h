#ifndef _LEVELHEAVY_H
#define _LEVELHEAVY_H

#include "specCommand.h"

class LevelHeavy: public SpecCommand {
    public:
        LevelHeavy(Command *);
        int left(Block *) override;
        int right(Block *) override;
        int clockwise(Block *) override;
        int counter(Block *) override;
};

#endif
