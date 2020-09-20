#ifndef _Board_H_
#define _Board_H_

#include <string>
#include <vector>
#include <iostream>
#include "cell.h"
#include "window.h"

class Board {
    std::vector<std::vector<Cell>> theBoard;  
    int maxCol;                               
    int maxRow;                              
    int score;                               
    int not_clean;                
    
    int level;                               
    int top_score;                      
    Xwindow *board_view;                   

    std::vector<Block *> BlocksInBoard;           

public:
    Board(bool textOnly);
    ~Board();
    void init(int l, int w = 11, int h = 18);  
    
    bool isRowFull(const int row);
    void clearRow(const int row);
    void update();
    int fullRows();                          

    std::string displayline(int i);               

    int getHeight();                            
    int getWidth();                             

    char shapeAt(int x, int y);                 
    void setAt(int x, int y, char shape);       
    void updatescore(int s);                   
    int getscore();                             
    int not_cleanNum();                      
    void setlevel(int l);                      
    int getlevel();                            
    Cell *get_cell(int x, int y);             
    int return_top_score();                   
    void set_topPoints(int s);
    void display_score(int s);                 
    void display_level(int lev);               
    void display_topPoints(int hs);         

    void display_next(char c);                 
    void eliminate_next(char c);                   
    void blind();                              
    void unblind();                           
    
    void more_Block(Block &);                     
};


#endif
