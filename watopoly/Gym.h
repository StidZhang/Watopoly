#ifndef WATOPOLY_GYM_H
#define WATOPOLY_GYM_H
 
#include "Building.h"
 
class Dice;
class Player;
class GameBoard;
 
class Gym: public Building {
    Dice *d;

public:
    Gym(std::string name, int cellIndex, GameBoard *g, int cost, Dice *d);
    void doEvent(Player *p) override;
    int getCurrentLevel() override{return 0;};
    int calculateFee();
    ~Gym();
};
 
 
#endif
