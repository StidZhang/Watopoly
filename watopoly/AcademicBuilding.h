#ifndef WATOPOLY_ACADEMICBUILDING_H
#define WATOPOLY_ACADEMICBUILDING_H
 
#include "Building.h"

class Player;

class AcademicBuilding: public Building {
    int improvementCost;
    int tuition[6];
    int block;
    int currentLevel; // get current level of improvements

public:
	AcademicBuilding(std::string n, int i, GameBoard *g, int c, int cl,
		int t0, int t1, int t2, int t3, int t4, int t5, int b);
	// construtor, for name, index, cost, currentLevel, tuitions and block
	~AcademicBuilding();
    int getBlock();
    int getImprovementCost();
    int getTuition();
    int getCurrentLevel() override;
    void doEvent(Player *p) override ;
    void changeLevel(int level); // change the level of improvements
    void setImprovements(int i);
};
 
 
#endif
