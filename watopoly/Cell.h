#ifndef WATOPOLY_CELL_H
#define WATOPOLY_CELL_H
 
#include "GameBoard.h"
#include "Player.h"
#include <string>
#include <vector>

 
class Cell {
    std::string name;
    char players[8];
    int cellIndex;
protected:
    GameBoard *g;

public:
    Cell(std::string name, int cellIndex, GameBoard *g);
    virtual ~Cell();
    void addPlayer(char);
    void printPlayers();
    void removePlayer(char);
    virtual void doEvent(Player *p) = 0;
    std::string getName();
    int getCellIndex();
};

#endif
