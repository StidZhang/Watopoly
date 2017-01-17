#ifndef WATOPOLY_PLAYER_H
#define WATOPOLY_PLAYER_H
#include "GameBoard.h"
#include <string>

class Building;
class Cell;

class Player {
    std::string name;
    char symbol;
    int index;
    int position;
    double cash;
    double asset; 
    int ownedResidences;
    int ownedGyms;
    int monopoly[8];
    bool isTimLine;
    int numLineWait;
    int ownedCups;
    bool isBankrupt;

public:
    Building *buildings[28];
    Player(std::string name, char symbol, int index, int position);
    Player(std::string name, char symbol, int ownedCups, double cash, int index, bool isTimLine, int numLineWait, int position);
    ~Player();
    std::string getName();
    char getSymbol();
    int getIndex();
    int getPosition();
    void setPosition(int n);
    double getCash();
    double getAsset();
    void changeAsset(int c);
    int getOwnedResidences();
    bool checkMonopolyImprove(Building *building);
    Building * findBuilding(std::string buildingName);
    void sellBuilding(Building *building);
    void changeOwnedResidences(int n);
    int getOwnedGyms();
    void changeOwnedGyms(int n);
    bool getIsTimLine();
    void setIsTimLine(bool t);
    int getNumLineWait();
    void setTimLineWait(int w);
    int getOwnedCups();
    bool getBankrupt();
    void setBankrupt(bool b);
    void setCups(int n);
    void addCup();
    void removeCup();
    void changeCash(int cash);
    bool checkMonopoly(int block);
    void printAsset();
    void buyBuilding(Building *building);
    void mortgage(Building *building);
    void unmortgage(Building *building);
    void buyImprovement(Building *building);
    void sellImprovement(Building *building);
    void trade(Player *partner, double money, Building *building);
    void trade(Player *partner, Building *building1, Building *building2);
    void trade(Player *partner, Building *building, double money);
};


#endif //WATOPOLY_PLAYER_H
