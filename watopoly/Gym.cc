#include <string>
#include <iostream>
#include "Building.h"
#include "Dice.h"
#include "GameBoard.h"
#include "Gym.h"
#include "Player.h"

using namespace std;

Gym::Gym(string name, int cellIndex, GameBoard *g, int cost, Dice *d)
: Building{name, cellIndex, g, cost}, d{d} {}

Gym::~Gym(){}

int Gym::calculateFee(){
	d->setValue();
	int diceValue = d->getValue();
	if(owner->getOwnedGyms() == 1) {
		cout << "The owner owns a gym, pay 4 times the sum of the dice." << endl;
		return (diceValue * 4);
	} else {
		cout << "The owner owns two gyms, pay 10 times the sum of the dice." << endl;
		return (diceValue * 10);
	}
}

void Gym::doEvent(Player *p){
	cout << "You are currently on " << getName() << "." << endl;
	if(owner == nullptr){
		g->buy(this);
	} else if(getMortgage()){
		cout << getName() << " is mortgaged." << endl;
	} else if(owner->getName() == p->getName()){
		cout << getName() << " is owned by you.";
	} else {	
		cout << getName() << " is owned by " << owner->getName() << ".";
		int temp = calculateFee();
		cout << "You paid $" << temp << " fee to the gym owner." << endl;
		if(g->checkBankrupt(temp)){
			g->bankrupt(owner);
		} else{
			p->changeCash(-temp);
			owner->changeCash(temp);
		} 
	}
}
