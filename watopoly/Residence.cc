#include <string>
#include <iostream>
#include <cmath> // std::pow
#include "Building.h"
#include "GameBoard.h"
#include "Residence.h"
#include "Player.h"

using namespace std;

Residence::Residence(string name, int cellIndex, GameBoard *g, int cost)
: Building{name, cellIndex, g, cost}{}

Residence::~Residence(){}

int Residence::calculateRent(){
	int ownedRes = owner->getOwnedResidences();
	cout << "The owner owns " << ownedRes << " residence." << endl;
	return (25 * pow(2.0, ownedRes-1)); 
}

void Residence::doEvent(Player *p){
	cout << "You are currently on " << getName() << "." << endl;
	if(owner == nullptr){
		g->buy(this);
	} else if(getMortgage()){
		cout << getName() << " is mortgaged." << endl;
	} else if(owner->getName() == p->getName()){
		cout << getName() << " is owned by you.";
	} else{	
		cout << getName() << " is owned by " << owner->getName() << ".";
		int temp = calculateRent();
		cout << "You paid $" << temp << " rent to the residence owner." << endl;
		if(g->checkBankrupt(temp)){
			g->bankrupt(owner);
		} else{
			p->changeCash(-temp);
			owner->changeCash(temp);
		} 
	}
}
