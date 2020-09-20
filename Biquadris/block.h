#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <string>
#include "Board.h"

class Block {
    protected:
      int which_cell;
      Board *theBoard;                    
      char shape;                        
      int cell_left;                      

      std::vector<Cell *> cells;        
      int ini_lev;                   
      
      bool cell_success;                    
      bool blinded;                    
          
    public:
      Block(Board *b, char c, int lev);
      virtual ~Block();
      
                                         
      virtual bool clockwise() = 0;    
      virtual bool counter() = 0;    
      bool right();                    
      bool left();                     
      bool down();                      
      void drop();                      

      void set_cell_left(int i);         
      int get_cell_left();                
                                         
      void set_cell(int i, Cell *cell); 
      int get_ini_lev();             
      
      void paint_block();               
      void unpaint_block();             
  
      bool onBoard();               

      void removeFromBoard();           

      void set_blind(bool b);                              
};

#endif
