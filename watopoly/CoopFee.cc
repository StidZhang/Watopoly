#include "CoopFee.h"
#include "Player.h"
#include "Nonproperty.h"
#include <iostream>
#include <string>
using namespace std;

CoopFee::CoopFee(std::string name, int cellIndex, GameBoard *g)
:Nonproperty{name, cellIndex, g}{}

void CoopFee::doEvent(Player *p){
  cout << "You are currently on " << getName() << "." << endl;
  cout << "You paid $150 for co-op fee." << endl;
  if(g->checkBankrupt(150)){
	g->bankrupt();
	} else{
		p->changeCash(-150);
	} 
}

CoopFee::~CoopFee() {}
