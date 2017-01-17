#include "Player.h"
#include "Nonproperty.h"
#include <string>
#include <iostream>

using namespace std;

Nonproperty::Nonproperty(string name, int cellIndex, GameBoard *g)
: Cell{name, cellIndex, g}{}

Nonproperty::~Nonproperty(){}
