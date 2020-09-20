#ifndef _CELL_H_
#define _CELL_H_

#include <iostream>
#include "window.h"
#include "posn.h"

class Block;

class Cell {
    Posn posn;
    char shape;
    Block *block;  
    
    Xwindow *c_view;  

public:
    Cell(int x, int y, Xwindow *xwin);
    ~Cell();
    char get_shape();        
    void set_shape(char c); 
    int getRow();           
    void setRow(int i);     
    int getCol();         
    void setCol(int i);    
    Block *get_block();   
    void set_block(Block *bp);  
    void paint();          
    void unpaint();      
};


#endif
