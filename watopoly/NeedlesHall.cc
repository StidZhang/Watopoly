#include "NeedlesHall.h"
#include "Player.h"
#include "Nonproperty.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

NeedlesHall::NeedlesHall(std::string name, int cellIndex, GameBoard *g)
    :Nonproperty{name, cellIndex, g}{}

NeedlesHall::~NeedlesHall(){}

void NeedlesHall::doEvent(Player *p){
        cout << "You are currently on " << getName() << "." << endl;
	srand(time(NULL));
	int prob = (rand()%100 + 1);
	if(prob == 1){
                if(g->getTotalCups() < 4){
			cout << "Congratulations! You won a Roll Up the Rim Cup!" << endl;
			g->addCup();
                        return;
		} else {
                    cout << "Soory. You won a Cup, but no more Cups are avaliable now." << endl;
                }
	} else {
            cout << "Sorry, you do not earn the Roll Up the Rim Cup.";
            cout << " But you may lose or win money here, good luck!" << endl;
            int random = rand()%36 + 1;
            if(random >= 1 && random <= 2){
                    cout << "You lose $200." << endl;
                        p->changeCash(-200);
            } else if (random >= 3 && random <= 6){
                    cout << "You lose $100." << endl;
                        p->changeCash(-100);
            } else if (random >= 7 && random <= 12){
                    cout << "You lose $50." << endl;
                        p->changeCash(-50);
            } else if (random >= 13 && random <= 24){
                    p->changeCash(25);
                    cout << "You get $25." << endl;
            } else if (random >= 25 && random <= 30){
                    p->changeCash(50);
                    cout << "You get $50." << endl;
            } else if (random >= 31 && random <= 34){
                    p->changeCash(100);
                    cout << "You get $100." << endl;
            } else {
                    p->changeCash(200);
                    cout << "You get $200." << endl;
            }
    }
}
