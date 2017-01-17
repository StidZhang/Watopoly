#ifndef WATOPOLY_DISPLAY_H
#define WATOPOLY_DISPLAY_H

#include "Cell.h"


class Display {
public:
    Display();
    ~Display();
    void printGameBoard(Cell *board[40]);
};


#endif //WATOPOLY_DISPLAY_H
