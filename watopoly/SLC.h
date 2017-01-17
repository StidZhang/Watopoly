#ifndef WATOPOLY_SLC_H
#define WATOPOLY_SLC_H
  
#include "Nonproperty.h"
#include "Player.h"
  
class SLC: public Nonproperty {
public:
    SLC(std::string name, int cellIndex, GameBoard *g);
    void doEvent(Player *p) override;
    ~SLC();
};
  
  
#endif
