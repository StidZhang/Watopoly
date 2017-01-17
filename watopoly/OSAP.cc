#include "OSAP.h"
#include "Player.h"
#include "Nonproperty.h"
#include <iostream>
using namespace std;

OSAP::OSAP(std::string name, int cellIndex, GameBoard *g)
:Nonproperty{name, cellIndex, g}{}

OSAP::~OSAP(){}

void OSAP::doEvent(Player *p){
	cout << "You are currently on " << getName() << "." << endl;
	cout << "collect $200 from OSAP.";
	p->changeCash(200);
}
