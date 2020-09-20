#ifndef _SBLOCK_H_
#define _SBLOCK_H_

#include <string>
#include <iostream>
#include "block.h"


class SBlock: public Block {
    public:
      SBlock(Board *g, int lev);
      ~SBlock();
      bool clockwise() override;
      bool counter() override;
};

#endif
