#ifndef WATOPOLY_BUILDING_H
#define WATOPOLY_BUILDING_H
#include "Cell.h"
#include <string>

class Player;

class Building: public Cell {
    int cost;
    bool isMortgage;
protected:
    Player *owner;
public:
    Building(std::string name, int cellIndex, GameBoard *g, int cost);
    virtual ~Building();
    int getCost();
    virtual int getCurrentLevel() = 0;
    Player * getOwner();
    void setOwner(Player *p);
    bool getMortgage();
    void setMortgage(bool mortgage);
    virtual void doEvent(Player *p) = 0;
};
 
 
#endif
