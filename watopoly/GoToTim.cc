#include "GoToTim.h"
#include "Player.h"
#include "Nonproperty.h"
#include <iostream>
using namespace std;

GoToTim::GoToTim(std::string name, int cellIndex, GameBoard *g)
:Nonproperty{name, cellIndex, g}{}

GoToTim::~GoToTim(){}

void GoToTim::doEvent(Player *p){
	cout << "You are currently on " << getName() << "." << endl;
	g->notifyPosition(30, 10);
        p->setPosition(10);
        p->setIsTimLine(true);
	p->setTimLineWait(0);
        g->notifyEvent();
}
