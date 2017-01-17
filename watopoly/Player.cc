#include "Player.h"
#include "Building.h"
#include "AcademicBuilding.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player(string name, char symbol, int index, int position) :
name(name), symbol(symbol), index(index), position(position) {
    cash = 1500;
    asset = 0;
    ownedResidences = 0;
    ownedGyms = 0;
    isTimLine = false;
    numLineWait = 0;
    ownedCups = 0;
    isBankrupt = false;
    for (int i = 0; i < 28; ++i) {
        buildings[i] = nullptr;
    }
    for (int i = 0; i < 8; ++i) {
        monopoly[i] = 0;
    }
}

Player::Player(std::string name, char symbol, int ownedCups, double cash, int index, bool isTimLine, int numLineWait, int position) :
name{name}, symbol{symbol}, ownedCups{ownedCups}, cash{cash}, index{index}, isTimLine{false}, numLineWait{-1}, position{position}
{
    asset = 0;
    ownedResidences = 0;
    ownedGyms = 0;
    ownedCups = 0;
    isBankrupt = false;
    for (int i = 0; i < 28; ++i) {
        buildings[i] = nullptr;
    }
    for (int i = 0; i < 8; ++i) {
        monopoly[i] = 0;
    }
}

Player::~Player() {
}

string Player::getName() {
    return name;
}

char Player::getSymbol() {
    return symbol;
}

int Player::getIndex() {
    return index;
}

int Player::getPosition() {
    return position;
}

void Player::setPosition(int p) {
    position = p;
}

double Player::getCash() {
    return cash;
}

void Player::changeCash(int c) {
    cash += c;
}

double Player::getAsset() {
    return asset;
}

void Player::changeAsset(int c) {
    asset += c;
}

int Player::getOwnedResidences() {
    return ownedResidences;
}

void Player::changeOwnedResidences(int n) {
    ownedResidences += n;
}

int Player::getOwnedGyms() {
    return ownedGyms;
}

void Player::changeOwnedGyms(int n) {
    ownedGyms += n;
}

bool Player::getIsTimLine() {
    return isTimLine;
}

void Player::setIsTimLine(bool t) {
    isTimLine = t;
}

int Player::getNumLineWait() {
    return numLineWait;
}

void Player::setTimLineWait(int w) {
    numLineWait = w;
}

int Player::getOwnedCups() {
    return ownedCups;
}

void Player::setCups(int n) {
    ownedCups = n;
}

void Player::addCup() {
    ++ownedCups;
}

void Player::removeCup() {
    --ownedCups;
}

Building *Player::findBuilding(string buildingName) {
    Building *bd;
    for (int i = 0; i < 28; ++i) {
        if (buildings[i]->getName() == buildingName) {
            bd = buildings[i];
            break;
        }
    }
    return bd;
}

void Player::buyBuilding(Building *building) {
    if (building->getName() == "PAC" || building->getName() == "CIF") {
        changeOwnedGyms(1);
    } else if (building->getName() == "MKV" || building->getName() == "UWP" \
    	|| building->getName() == "V1" || building->getName() == "REV") {
        changeOwnedResidences(1);
    } else {
        AcademicBuilding *ac = dynamic_cast<AcademicBuilding *>(building);
        ++monopoly[ac->getBlock()];
    }
    int cost = building->getCost();
    cash = cash - cost;
    asset = asset + cost;
    for (int i = 0; i < 28; ++i) {
        if (buildings[i] == nullptr) {
            buildings[i] = building;
            break;
        }
    }
    building->setOwner(this);
    cout << getName() << " become the owner of " << building->getName() << endl;
}

void Player::sellBuilding(Building *building) {
     if (building->getName() == "PAC" || building->getName() == "CIF") {
        changeOwnedGyms(-1);
    } else if (building->getName() == "MKV" || building->getName() == "UWP" \
    	|| building->getName() == "V1" || building->getName() == "REV") {
        changeOwnedResidences(-1);
    } else {
        AcademicBuilding *ac = dynamic_cast<AcademicBuilding *>(building);
        --monopoly[ac->getBlock()];
    }
    changeAsset(-(building->getCost()));
    for (int i = 0; i < 28; ++i) {
        if (buildings[i]->getName() == building->getName()) {
            buildings[i] = nullptr;
            break;
        }
    }
}

bool Player::getBankrupt() {
    return isBankrupt;
}

void Player::buyImprovement(Building *building) {
    AcademicBuilding *ac = dynamic_cast<AcademicBuilding *> (building);
    if (building->getName() == "PAC" || building->getName() == "CIF" || \
		building->getName() == "MKV" || building->getName() == "UWP" || \
		building->getName() == "V1" || building->getName() == "REV") {
        cout << "Failed. Gyms and Residences can not be improved." << endl;
    } else if (checkMonopoly(ac->getBlock()) == false) {
        cout << "Failed. You can not improve this building because you do not own a Monopoly." << endl;
    } else {
        int improveCost = ac->getImprovementCost();
        if (cash < improveCost) {
            cout << "Failed. You do not have enough money to buy improvement for this building." << endl;
        } else {
            if(ac->getCurrentLevel() >= 5){
                cout << "Sorry, the highest level of improvement should be 5. No more improvement." << endl;
                return;
            }
            changeCash(-improveCost);
            asset += improveCost;
            ac->changeLevel(1);
            cout << "You have successfully bought improvement for " << building->getName() << \
			      " and now it is Level " << ac->getCurrentLevel() << "." << endl;
        }
    }
}

void Player::sellImprovement(Building *building) {
    AcademicBuilding *ac = dynamic_cast<AcademicBuilding *> (building);
    if (building->getName() == "PAC" || building->getName() == "CIF" || \
		building->getName() == "MKV" || building->getName() == "UWP" || \
		building->getName() == "V1" || building->getName() == "REV") {
        cout << "Failed. Gyms and Residences have no improvements to sell." << endl;
    } else if (ac->getCurrentLevel() == 0) {
        cout << "Failed. This building has no improvement right now." << endl;
    } else {
        int sellImproveFee = ac->getImprovementCost() / 2;
        changeCash(sellImproveFee);
        asset -= ac->getImprovementCost();
        ac->changeLevel(-1);
        cout << "You have successfully sold improvement for " << building->getName() << \
			      "and now it is Level " << ac->getCurrentLevel() << "." << endl;
    }
}

void Player::mortgage(Building *building) {
    if (building->getOwner()->getName() != name) {
        cout << "Mortgage Failed! You are not the owner of " << building->getName() << endl;
    } else if (building->getMortgage() == true) {
        cout << "Mortgage Failed! This building has already been mortgaged." << endl;
    } else if (building->getName() != "PAC" && building->getName() != "CIF" && building->getName() != "MKV" && building->getName() != "UWP" && building->getName() != "V1" && building->getName() != "REV" && building->getCurrentLevel() != 0) {
        cout << "Mortgage Failed! This building still have improvements. You have to sell improvements first." << endl;
    } else {
        double mortgagedCash = building->getCost()*0.5;
        asset = asset - building->getCost();
        changeCash(mortgagedCash);
        building->setMortgage(true);
        cout << "Mortgage Succeed. You have mortgaged the building " << building->getName() << \
             " and received $" << mortgagedCash << "." << endl;
    }
}

void Player::unmortgage(Building *building) {
    if (building->getOwner()->getName() != name) {
        cout << "Unmortgage Failed! You are not the owner of " << building->getName() << endl;
    } else if (building->getMortgage() == false) {
        cout << "Unmortgage Failed! This building has not been mortgaged yet." << endl;
    } else {
        double unmortgageCost = building->getCost()*0.6;
        if (cash < unmortgageCost) {
            cout << "Unmortgage Failed! You do not have enough money to unmortgage this building." << endl;
        } else {
            changeCash(-unmortgageCost);
            asset = asset + building->getCost();
            building->setMortgage(false);
            cout << "Unmortgage Succeed. You have unmortgaged the building " << building->getName() \
			     << " and used $" << unmortgageCost << "." << endl;
        }
    }
}

bool Player::checkMonopoly(int block) {
    int getMonopoly[8] = {2, 3, 3, 3, 3, 3, 3, 2};
    if (monopoly[block] == getMonopoly[block]) {
        return true;
    } else {
        return false;
    }
}

bool Player::checkMonopolyImprove(Building *building) {
    AcademicBuilding *ac = dynamic_cast<AcademicBuilding *> (building);
    int blocki = ac->getBlock();
    bool result = true;
    for (int i = 0; i < 28; ++i) {
        if (buildings[i] != nullptr) {
            AcademicBuilding *ac2 = dynamic_cast<AcademicBuilding *> (buildings[i]);
            if (ac2) {
                if (ac2->getBlock() == blocki) {
                    if (ac2->getCurrentLevel() != 0) {
                        result = false;
                        break;
                    }
                }
            }
        }
    }
    return result;
}

void Player::trade(Player *partner, double money, Building *building) {
    if (building->getOwner()->getName() != partner->getName()) {
        cout << "Trade failed. " << building->getName() << "doesn't belong to " << partner->getName() << "." << endl;
    } else if (cash < money) {
        cout << "Trade failed. You do not have enough cash for trade." << endl;
    } else if (checkMonopolyImprove(building) == false) {
        cout << "Trade failed. You can not trade for building that has improvements in the monopoly." << endl;
    } else {
        cout << "Player " << partner->getName() << ", do you accept this trade? (accept/reject)" << endl;
        string choice;
        cin >> choice;
        if (choice == "accept") {
            buyBuilding(building);
            changeCash(building->getCost());
            changeCash(-money);
            partner->sellBuilding(building);
            partner->changeCash(money);
            
            cout << "Trade Succeed. You have paid $" << money << " and received property " << building->getName() << "." << endl;
        } else {
            cout << "Trade failed. Player " << partner->getName() << " has rejected your trade." << endl;
        }
    }
}

void Player::trade(Player *partner, Building *building1, Building *building2) {
    AcademicBuilding *ac1 = dynamic_cast<AcademicBuilding *>(building1);
    AcademicBuilding *ac2 = dynamic_cast<AcademicBuilding *>(building2);
    if (building1->getOwner()->getName() != name) {
        cout << "Trade failed. " << building1->getName() << "doesn't belong to you." << endl;
    } else if (building2->getOwner()->getName() != partner->getName()) {
        cout << "Trade failed. " << building2->getName() << "doesn't belong to " << partner->getName() << "." << endl;
    } else if (ac1 && ac2 && (checkMonopolyImprove(ac1) == false || checkMonopolyImprove(ac2) == false)) {
        cout << "Trade failed. You can not trade for building that has improvements in the monopoly." << endl;
    } else {
        cout << "Player " << partner->getName() << ", do you accept this trade? (accept/reject)" << endl;
        string choice;
        cin >> choice;
        if (choice == "accept") {
            buyBuilding(building2);
            changeCash(building2->getCost());
            sellBuilding(building1);
            partner->sellBuilding(building2);
            partner->buyBuilding(building1);
            partner->changeCash(building1->getCost());
            cout << "Trade Succeed. You have exchanged property " << building1->getName() << " and received property " << building2->getName() << "." << endl;
        } else {
            cout << "Trade failed. Player " << partner->getName() << " has rejected your trade." << endl;
        }
    }
}

void Player::trade(Player *partner, Building *building, double money) {
    if (building->getOwner()->getName() != name) {
        cout << "Trade failed. " << building->getName() << "doesn't belong to you." << endl;
    } else if (partner->getCash() < money) {
        cout << "Trade failed. Player " << partner->getName() << "do not have enough cash for trade." << endl;
    } else if (checkMonopolyImprove(building) == false) {
        cout << "Trade failed. You can not trade for building that has improvements in the monopoly." << endl;
    } else {
        cout << "Player " << partner->getName() << ", do you accept this trade? (accept/reject)" << endl;
        string choice;
        cin >> choice;
        if (choice == "accept") {
            sellBuilding(building);
            changeCash(money);
            partner->changeCash(building->getCost());
            partner->buyBuilding(building);
            partner->changeCash(-money);
            cout << "Trade Succeed. You have received $" << money << " and gave property " << building->getName() << "." << endl;
        } else {
            cout << "Trade failed. Player " << partner->getName() << " has rejected your trade." << endl;
        }
    }
}

void Player::setBankrupt(bool b) {
    isBankrupt = b;
}

void Player::printAsset() {
    cout << "Player : " << name << endl;
    cout << "Money Owned : $" << cash << endl;
    cout << "Net Worth: $" << cash + asset << endl;
    cout << "The Number of Tims Cups Owned : " << ownedCups << endl;
    cout << "Properties Owned : ";
    for (int i = 0; i < 28; ++i) {
        if (buildings[i] != nullptr) {
            cout << buildings[i]->getName() << " ";
        }
    }
    cout << endl;
}

