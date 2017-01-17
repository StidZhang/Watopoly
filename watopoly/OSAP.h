#ifndef WATOPOLY_OSAP_H
#define WATOPOLY_OSAP_H
 
#include "Nonproperty.h"
#include "Player.h"

class OSAP: public Nonproperty {
public:
	OSAP(std::string name, int cellIndex, GameBoard *g);
    void doEvent(Player *p) override;
    ~OSAP();
};
 
 
#endif
