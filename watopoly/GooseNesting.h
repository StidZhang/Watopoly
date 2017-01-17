#ifndef WATOPOLY_GOOSENESTING_H
#define WATOPOLY_GOOSENESTING_H

#include "Nonproperty.h"
 
class GooseNesting: public Nonproperty {
public:
	GooseNesting(std::string name, int cellIndex, GameBoard *g);
    void doEvent(Player *p) override;
    ~GooseNesting();
};
 
 
#endif
