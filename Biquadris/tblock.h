#ifndef _TBLOCK_H_
#define _TBLOCK_H_

#include <string>
#include <iostream>
#include "block.h"


class TBlock: public Block {
    public:
      TBlock(Board *g, int lev);
      ~TBlock();
      bool clockwise() override;
      bool counter() override;
};

#endif
