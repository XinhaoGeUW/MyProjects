#ifndef _BLIND_H
#define _BLIND_H

#include "specCommand.h"

class Blind: public SpecCommand {
    public:
        Blind(Command *);
        char displaychar() override;
};

#endif
