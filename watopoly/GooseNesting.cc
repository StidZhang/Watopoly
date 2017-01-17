#include "Nonproperty.h"
#include "GooseNesting.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

GooseNesting::GooseNesting(std::string name, int cellIndex, GameBoard *g)
:Nonproperty{name, cellIndex, g}{}

GooseNesting::~GooseNesting() {}

void GooseNesting::doEvent(Player *p){
	cout << "You are currently on " << getName() << "." << endl;
	cout << "Attack by a flock of nesting geese!" << endl;
}
