#ifndef _OBLOCK_H_
#define _OBLOCK_H_

#include <string>
#include <iostream>
#include "block.h"


class OBlock: public Block {
    public:
      OBlock(Board *g, int lev);
      ~OBlock();
      bool clockwise() override;
      bool counter() override;
};

#endif
