#ifndef _LBLOCK_Z_
#define _LBLOCK_Z_

#include <string>
#include <iostream>
#include "block.h"


class ZBlock: public Block {
    public:
      ZBlock(Board *g, int lev);
      ~ZBlock();
      bool clockwise() override;
      bool counter() override;
};

#endif
