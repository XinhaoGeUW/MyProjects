#ifndef _IBLOCK_H_
#define _IBLOCK_H_

#include <string>
#include <iostream>
#include "block.h"


class IBlock: public Block {
    bool spin(Cell *Lowerleft, int direction);  
    public:
      IBlock(Board *g, int lev);
      ~IBlock();
      bool clockwise() override;
      bool counter() override;
};

#endif
