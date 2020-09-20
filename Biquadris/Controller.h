#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "game.h"
#include "block.h"
#include <fstream>

struct prev_controller;
class Block;
class Game;

class Controller {
  prev_controller *contr;                     
  Game *currGame;
  std::ifstream file;
  long int ID;
  std::string seq1, seq2;
  int startlev;
  bool textOnly;
  int total_participator;
  int maxLevel;
  

  public:
    Controller(long int ID, std::string seq1, std::string seq2, int startlev, bool textOnly, int, int);
    ~Controller();
    bool exec_inst(std::string s);            

    void mod();                                   
};

#endif
