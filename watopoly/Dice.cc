#include "Dice.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

Dice::Dice(): doubleRoll(false){}

Dice::~Dice(){}

bool Dice::getDoubleRoll(){
	return doubleRoll;
}

void Dice::setValue(){
	srand(time(NULL));
	int d1 = (rand()% 6) + 1;
	int d2 = (rand()% 6) + 1;
	if(d1 == d2){
		doubleRoll = true;
	}
	else {doubleRoll = false;}
	value = d1 + d2;
	cout << "Two dices have rolled and values are : " << d1 << ", " << d2 << "." << endl;
}

int Dice::getValue(){
	return value;
}

void Dice::setDoubleRoll(bool b) {
    doubleRoll = b;
}
