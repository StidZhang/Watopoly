#include <string>
#include <iostream>
#include "Cell.h"
#include "GameBoard.h"

using namespace std;

Cell::Cell(string name, int cellIndex, GameBoard *g) : name{name}, cellIndex{cellIndex}, g{g}
{
    for (int i = 0; i < 8; ++i) {
        players[i] = ' ';
    }
}

Cell::~Cell() {}


void Cell::addPlayer(char player) {
    for (int i = 0; i < 8; ++i) {
        if (players[i] == ' ') {
            players[i] = player;
            break;
        }
    }
}

void Cell::removePlayer(char player) {
    for (int i = 0; i < 8; ++i) {
        if (players[i] == player) {
            players[i] = ' ';
            break;
        }
    }
}

void Cell::printPlayers() {
    for(int i = 0; i < 7; ++i){
        cout << players[i]; 
    }
}

string Cell::getName() {
    return name;
}

int Cell::getCellIndex() {
    return cellIndex;
}
