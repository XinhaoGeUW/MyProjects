#ifndef _SPECHEAVY_H
#define _SPECHEAVY_H

#include "specCommand.h"

class SpecHeavy: public SpecCommand {
    public:
        SpecHeavy(Command *);
        int right(Block *) override;
        int left(Block *) override;
};

#endif
