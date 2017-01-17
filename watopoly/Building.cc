#include <string>
#include <iostream>
#include "Building.h"
#include "GameBoard.h"

using namespace std;

Building::Building(string name, int cellIndex, GameBoard *g, int cost)
: Cell{name, cellIndex, g}, cost{cost}, owner{nullptr}, isMortgage(false){}

Building::~Building(){}

int Building::getCost(){
	return cost;
}

Player * Building::getOwner(){
	return owner;
}

void Building::setOwner(Player *p){
	owner = p; // set owner to the player
}

bool Building::getMortgage(){
	return isMortgage;
}

void Building::setMortgage(bool m){
	isMortgage = m;
}
