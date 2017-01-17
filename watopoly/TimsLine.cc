#include "TimsLine.h"
#include "Player.h"
#include "Dice.h"
#include "Nonproperty.h"
#include <iostream>
using namespace std;

TimsLine::TimsLine(std::string name, int cellIndex, GameBoard *g, Dice *d):
Nonproperty{name, cellIndex, g}, d{d}{}

TimsLine::~TimsLine(){}

void TimsLine::doEvent(Player *p){
	// Besides the last turn, how to move if first use Cup
	cout << "You are currently on " << getName() << "." << endl;
	if(p->getIsTimLine()){
		while(p->getNumLineWait() != 3){
                    int diceValue;
			if(p->getNumLineWait() == 3){
                                    cout << "This is the last turn, you have to leave now." << endl;
                                    cout << "You have to pay $50 now." << endl;
                                    cout << "You paid $50." << endl;
                                    cout << "You now move " << diceValue << " steps forward form you last roll." << endl;
                                    g->notifyPosition(10, 10 + diceValue);
                                    p->setPosition(10 + diceValue);
                                    p->setIsTimLine(false);
                                    p->setTimLineWait(0);
                                    g->notifyEvent();
                                if(g->checkBankrupt(50)){
				  	g->bankrupt();
				  } else{
				  	p->changeCash(-50);
					p->setIsTimLine(false);
					p->setTimLineWait(0);
					break;
                                  }
			}
			if(p->getOwnedCups() > 0){
				cout << "You have a Roll Up the Rim Cup, do you want to use it?:(Y/N)" << endl;
				char isUseCup;
				cin >> isUseCup;
				if((isUseCup == 'Y') || (isUseCup == 'y')){
					cout << "Congratulations! You can leave now!" << endl;
					p->setIsTimLine(false);
					p->setTimLineWait(0);
					p->removeCup();
					g->removeCup(); 
					break;
				}
			} else {
                            cout << "The number of turns you have been here: " << p->getNumLineWait() << "." << endl; 
                            cout << "You can choose roll doubles(R) or pay $50(P) to leave:(R/P)" << endl;
                            char temp;
                            cin >> temp;
                            if(temp == 'R'){
                            	d->setValue();
				if(d->getDoubleRoll()){
					cout << "Congratulations! You roll doubles and you can leave now." << endl;
				} else {
                                    diceValue = d->getValue();
                                    cout << "Sorry, you did not roll doubles." << endl;
				}
                            } else if (temp == 'P'){
                                cout << "You paid $50." << endl;
				  if(g->checkBankrupt(50)){
				  	g->bankrupt();
				  } else{
				  	p->changeCash(-50);
				  }
                           } else {
					p->setIsTimLine(false);
					p->setTimLineWait(0);
					break;
                           }
                             p->setTimLineWait(p->getNumLineWait() + 1);
			}
                }
        } else {
		cout << "nothing happens." << endl;
                }
}
