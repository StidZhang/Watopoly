#ifndef WATOPOLY_TIMSLINE_H
#define WATOPOLY_TIMSLINE_H
 
#include "Nonproperty.h"
#include "Player.h"
 
class TimsLine: public Nonproperty {
	Dice *d;
public:
	TimsLine(std::string name, int cellIndex, GameBoard *g, Dice *d);
    void doEvent(Player *p) override;
    ~TimsLine();
};
 
 
#endif
