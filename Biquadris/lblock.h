#ifndef _LBLOCK_H_
#define _LBLOCK_H_

#include <string>
#include <iostream>
#include "block.h"


class LBlock: public Block {
    public:
      LBlock(Board *g, int lev);
      ~LBlock();
  
      bool clockwise() override;
      bool counter() override;
};

#endif
