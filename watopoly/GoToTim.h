#ifndef WATOPOLY_GOTOTIM_H
#define WATOPOLY_GOTOTIM_H
 
#include "Nonproperty.h"
#include "Player.h"
 
class GoToTim: public Nonproperty {
 public:
 	GoToTim(std::string name, int cellIndex, GameBoard *g);
 	void doEvent(Player *p) override;
 	~GoToTim();
};
 
 
#endif
