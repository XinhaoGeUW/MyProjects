#ifndef _COMMAND_H
#define _COMMAND_H

class Block;

class Command {
    public:
        virtual char displaychar() = 0;
        virtual int left(Block *) = 0;
        virtual int right(Block *) = 0;
        virtual int down(Block *) = 0;
        virtual void drop(Block *) = 0;
        virtual int clockwise(Block *) = 0;
        virtual int counter(Block *) = 0;
	virtual ~Command() {};
};

#endif
