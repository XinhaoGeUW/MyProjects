#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <vector>

class Player;

class Game {
    std::vector<Player*> players;
    int total_participator;
    Player *currPlayer;
    int final_survivor;
    int top_score;
    bool textOnly;
    int ID;
    int init_num;

    std::string displayLevels() const;
    std::string displayScores() const;
    std::string displayBoards() const;
    std::string displayNexts() const;
    
  public:
    Game(int num, int ID, bool textOnly);
    ~Game();
    
    void newMan(int ID, bool textOnly);                  
    
    bool kill_loser(int id);               
    
    void alter_survivor(int, std::string, char);  

    void nextTurn();		
                                                
    void mark();                                
                                                
    std::string prettydisplay() const;           
                                                
    int final_survivor_func();                       
                                                
    int count_survivor();                        
                                                
    Player *manipulator();                   
                                                
    void Initial_f(int id, std::string file);     

    void outLoser(Player *);             

    void restart();                             

    bool isAlive(Player *);            
    
    void modify_HS();
};

std::ostream &operator<<(std::ostream& out, const Game &game);

#endif
