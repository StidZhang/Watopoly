#ifndef WATOPOLY_NEEDLESHALL_H
#define WATOPOLY_NEEDLESHALL_H
  
#include "Nonproperty.h"
#include "Player.h"
  
class NeedlesHall: public Nonproperty {
public:
    NeedlesHall(std::string name, int cellIndex, GameBoard *g);
    void doEvent(Player *p) override;
    ~NeedlesHall();
};
  
  
#endif
