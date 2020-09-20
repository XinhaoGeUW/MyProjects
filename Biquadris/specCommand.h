#ifndef _SPECCOMMAND_H
#define _SPECCOMMAND_H

#include "Command.h"

class SpecCommand: public Command {
    protected:
        Command *currCom;
    public:
        SpecCommand(Command *);
        char displaychar() override; 
        int left(Block *) override;
        int right(Block *) override;
        int down(Block *) override;
        void drop(Block *) override;
        int clockwise(Block *) override;
        int counter(Block *) override;
        virtual ~SpecCommand() = 0;
};

#endif
