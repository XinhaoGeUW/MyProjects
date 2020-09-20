#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <iostream>
#include <fstream>

class Board;
class Game;
class Command;
class Block;
class Level;

class Player {
  int score;
  Board *theBoard;
  int playerId;
  Game *theGame;
  Command *current_Command;
  Block *current_block;
  char next_block;
  std::string next_Command;
  Level *level;
  int currentlevel;
  std::string desire_input;
  std::ifstream f;
  int ID;

  public:
    Player(int id, Game *game, 
           std::string file, int ID, bool textOnly); 

    ~Player();
    void setBoard(Board *g);                         

    Board *getBoard();                                

    void levelup();                                 

    void leveldown();                               

    void createnext();                            

    void setCommand(std::string, char);              

    void afterEffect(int, std::string, char);       

    void endTurn();                                 

    int getID();                                   
    int getLevel();                                
    int getScore();                                
    char getNextBlockShape();                      

    void setNextBlockShape(char);                   
    void set_input(std::string);               

    Block *getCurrBlock();                         
    std::string displayline(int);                 
    
    int right();
    int left();
    int down();
    void drop();

    int clockwise();
    int counter();

    void force(char);
};

#endif
