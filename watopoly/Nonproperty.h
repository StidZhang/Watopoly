#ifndef WATOPOLY_NONPROPERTY_H
#define WATOPOLY_NONPROPERTY_H
 
#include "Cell.h"
#include <string>
class Player;
 
class Nonproperty: public Cell {
public:
	Nonproperty(std::string name, int cellIndex, GameBoard *g);
    virtual void doEvent(Player *p) = 0;
    ~Nonproperty();
};
 
 
#endif
