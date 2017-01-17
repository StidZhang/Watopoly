#include <string>
#include <iostream>
#include "Building.h"
#include "GameBoard.h"
#include "AcademicBuilding.h"

using namespace std;

AcademicBuilding::AcademicBuilding(std::string n, int i, GameBoard *g, 
        int c, int ic, int t0, int t1, int t2, int t3, int t4, int t5, int b):
 Building{n, i, g, c}, currentLevel{0}, improvementCost{ic}, block{b}{
    tuition[0] = t0;
    tuition[1] = t1;
    tuition[2] = t2;
    tuition[3] = t3;
    tuition[4] = t4;
    tuition[5] = t5;
}

AcademicBuilding::~AcademicBuilding(){}


int AcademicBuilding::getBlock(){
	return block;
}

int AcademicBuilding::getImprovementCost(){
	return improvementCost;
}

int AcademicBuilding::getTuition(){
	if((owner->checkMonopoly(block)) && (currentLevel == 0)){
		cout << "The monopoly is owned by the owner." << endl;
		return tuition[0] * 2;
	} else {
		cout << "The current improvement level is: " << currentLevel << "." << endl;
		return tuition[currentLevel];
	}
}

int AcademicBuilding::getCurrentLevel(){
	return currentLevel;
}

void AcademicBuilding::doEvent(Player *p){
	cout << "You are currently on " << getName() << "." << endl;
	if(owner == nullptr){
		g->buy(this);
	} else if(getMortgage() == true){
		cout << getName() << " is mortgaged." << endl;
	} else if(owner->getName() == p->getName()){
		cout << getName() << " is owned by you." << endl;
	} else {	
		cout << getName() << " is owned by " << owner->getName() << ".";
		int temp = getTuition();
		cout << "You paid $" << temp << " tuition fee to the owner." << endl;
		if(g->checkBankrupt(temp)){
			g->bankrupt(owner);
		} else {
			p->changeCash(-temp);
			owner->changeCash(temp);
		} 
	}
}


void AcademicBuilding::changeLevel(int level){
	int newLevel = currentLevel + level;
	if(newLevel >= 0 && newLevel <= 5) currentLevel = newLevel;
}

void AcademicBuilding::setImprovements(int i){ // for load
 	if(i == -1){
 		setMortgage(true);
 	} else {
 		currentLevel = i;
 	}
 }
