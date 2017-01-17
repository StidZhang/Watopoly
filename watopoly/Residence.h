#ifndef WATOPOLY_RESIDENCE_H
#define WATOPOLY_RESIDENCE_H

#include "Building.h"


class Player;

class Residence : public Building {
public:
    Residence(std::string name, int cellIndex, GameBoard *g, int cost);
    int calculateRent();

    int getCurrentLevel() override {
        return 0;
    };
    void doEvent(Player *p) override;
    ~Residence();
};


#endif
