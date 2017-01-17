#include "SLC.h"
#include "Player.h"
#include "Nonproperty.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

SLC::SLC(std::string name, int cellIndex, GameBoard *g)
:Nonproperty{name, cellIndex, g}{}

SLC::~SLC(){}

void SLC::doEvent(Player *p){
        cout << "You are currently on " << getName() << "." << endl;
	srand(time(NULL));
	int prob = (rand()%100 + 1);
	if(prob == 1){
		if(g->getTotalCups() < 4){
			cout << "Congratuations! You won a Roll up the Rim Cup!" << endl;
			p->addCup();
			g->addCup();
			return;
		}
	}
        cout << "Sorry, you do not earn the Roll Up the Rim Cup.";
        cout << " But you may move to other places here, good luck!" << endl;
	int random = rand()%48 + 1;

	if(random >= 1 && random <= 6){
            g->notifyPosition(p->getPosition(), p->getPosition() - 3);
            p->setPosition(p->getPosition() - 3);
		cout << "You move back 3 steps." << endl;
                g->notifyEvent();
	} else if (random >= 7 && random <= 14){
            g->notifyPosition(p->getPosition(), p->getPosition() - 2);
            p->setPosition(p->getPosition() - 2);
		cout << "You move back 2 steps." << endl;
                g->notifyEvent();
	} else if (random >= 15 && random <= 22){
            g->notifyPosition(p->getPosition(), p->getPosition() - 1);
            p->setPosition(p->getPosition() - 1);
		cout << "You move back 1 step." << endl;
                g->notifyEvent();
	} else if (random >= 23 && random <= 28){
            g->notifyPosition(p->getPosition(), p->getPosition() + 1);
            p->setPosition(p->getPosition() + 1);
		cout << "You move forword 1 step." << endl;
                g->notifyEvent();
	} else if (random >= 29 && random <= 36){
            g->notifyPosition(p->getPosition(), p->getPosition() + 2);
            p->setPosition(p->getPosition() + 2);
		cout << "You move forword 2 steps." << endl;
                g->notifyEvent();
	} else if (random >= 37 && random <= 44){
            g->notifyPosition(p->getPosition(), p->getPosition() + 3);
            p->setPosition(p->getPosition() + 3);
		cout << "You move forword 3 steps." << endl;
                g->notifyEvent();
	} else if (random >= 45 && random <= 46){
		g->notifyPosition(p->getPosition(), 10);
                p->setPosition(10);
                cout << "You move to GO TO TIMS." << endl;
                g->notifyEvent();
	} else {
		g->notifyPosition(p->getPosition(), 0);
                p->setPosition(0);
                cout << "Advance to Collect OSAP." << endl;
                g->notifyEvent();
	}
}
