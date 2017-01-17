#ifndef WATOPOLY_COOPFEE_H
#define WATOPOLY_COOPFEE_H
 
#include <string>
#include <iostream>
#include "Nonproperty.h"

class CoopFee: public Nonproperty{
public:
    CoopFee(std::string name, int cellIndex, GameBoard *g);
    void doEvent(Player *p) override;
    ~CoopFee();
};
 
 
#endif
