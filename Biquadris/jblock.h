#ifndef _JBLOCK_H_
#define _JBLOCK_H_

#include <string>
#include <iostream>
#include "block.h"


class JBlock: public Block {
    public:
      JBlock(Board *g, int lev);
      ~JBlock();
      
      bool clockwise() override;
      bool counter() override;
};

#endif
