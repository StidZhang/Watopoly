#include "GameBoard.h"
#include "Dice.h"
#include "Player.h"
#include "Display.h"
#include "Cell.h"
#include "Building.h"
#include "AcademicBuilding.h"
#include "Residence.h"
#include "Gym.h"
#include "Nonproperty.h"
#include "GoToTim.h"
#include "OSAP.h"
#include "GooseNesting.h"
#include "TimsLine.h"
#include "NeedlesHall.h"
#include "SLC.h"
#include "CoopFee.h"
#include "Tuition.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

GameBoard::GameBoard() {
    totalCups = 0;
    dice = new Dice();
    board[0] = new OSAP("COLLECT OSAP", 0, this);
    board[1] = new AcademicBuilding("AL", 1, this, 40, 50, 2, 10, 30, 90, 160, 250, 0);
    board[2] = new SLC("SLC", 2, this);
    board[3] = new AcademicBuilding("ML", 3, this, 60, 50, 4, 20, 60, 180, 320, 450, 0);
    board[4] = new Tuition("TUITION", 4, this);
    board[5] = new Residence("MKV", 5, this, 200);
    board[6] = new AcademicBuilding("ECH", 6, this, 100, 50, 6, 30, 90, 270, 400, 550, 1);
    board[7] = new NeedlesHall("NEEDLES HALL", 7, this);
    board[8] = new AcademicBuilding("PAS", 8, this, 100, 50, 6, 30, 90, 270, 400, 550, 1);
    board[9] = new AcademicBuilding("HH", 9, this, 120, 50, 8, 40, 100, 300, 450, 600, 1);
    board[10] = new TimsLine("DC Tims Line", 10, this, dice);
    board[11] = new AcademicBuilding("RCH", 11, this, 140, 100, 10, 50, 150, 450, 625, 750, 2);
    board[12] = new Gym("PAC", 12, this, 150, dice);
    board[13] = new AcademicBuilding("DWE", 13, this, 140, 100, 10, 50, 150, 450, 625, 750, 2);
    board[14] = new AcademicBuilding("CPH", 14, this, 160, 100, 12, 60, 180, 500, 700, 900, 2);
    board[15] = new Residence("UWP", 15, this, 200);
    board[16] = new AcademicBuilding("LHI", 16, this, 180, 100, 14, 70, 200, 550, 750, 950, 3);
    board[17] = new SLC("SLC", 17, this);
    board[18] = new AcademicBuilding("BMH", 18, this, 180, 100, 14, 70, 200, 550, 750, 950, 3);
    board[19] = new AcademicBuilding("OPT", 19, this, 200, 100, 16, 80, 220, 600, 800, 1000, 3);
    board[20] = new GooseNesting("Goose Nesting", 20, this);
    board[21] = new AcademicBuilding("EV1", 21, this, 220, 150, 18, 90, 250, 700, 875, 1050, 4);
    board[22] = new NeedlesHall("NEEDLES HALL", 22, this);
    board[23] = new AcademicBuilding("EV2", 23, this, 220, 150, 18, 90, 250, 700, 875, 1050, 4);
    board[24] = new AcademicBuilding("EV3", 23, this, 240, 150, 20, 100, 300, 750, 925, 1100, 4);
    board[25] = new Residence("V1", 25, this, 200);
    board[26] = new AcademicBuilding("PHYS", 26, this, 260, 150, 22, 110, 330, 800, 975, 1150, 5);
    board[27] = new AcademicBuilding("B1", 27, this, 260, 150, 22, 110, 330, 800, 975, 1150, 5);
    board[28] = new Gym("CIF", 28, this, 150, dice);
    board[29] = new AcademicBuilding("B2", 29, this, 280, 150, 24, 120, 360, 850, 1025, 1200, 5);
    board[30] = new GoToTim("GO TO TIMS", 30, this);
    board[31] = new AcademicBuilding("EIT", 31, this, 300, 200, 26, 130, 390, 900, 1100, 1275, 6);
    board[32] = new AcademicBuilding("ESC", 32, this, 300, 200, 26, 130, 390, 900, 1100, 1275, 6);
    board[33] = new SLC("SLC", 33, this);
    board[34] = new AcademicBuilding("C2", 34, this, 320, 200, 28, 150, 450, 1000, 1200, 1400, 6);
    board[35] = new Residence("REV", 35, this, 200);
    board[36] = new NeedlesHall("NEEDLES HALL", 36, this);
    board[37] = new AcademicBuilding("MC", 37, this, 350, 200, 35, 175, 500, 1100, 1300, 1500, 7);
    board[38] = new CoopFee("COOP FEE", 38, this);
    board[39] = new AcademicBuilding("DC", 39, this, 400, 200, 50, 200, 600, 1400, 1700, 2000, 7);
    buildings[0] = dynamic_cast<Building *> (board[1]);
    buildings[1] = dynamic_cast<Building *> (board[3]);
    buildings[2] = dynamic_cast<Building *> (board[5]);
    buildings[3] = dynamic_cast<Building *> (board[6]);
    buildings[4] = dynamic_cast<Building *> (board[8]);
    buildings[5] = dynamic_cast<Building *> (board[9]);
    buildings[6] = dynamic_cast<Building *> (board[11]);
    buildings[7] = dynamic_cast<Building *> (board[12]);
    buildings[8] = dynamic_cast<Building *> (board[13]);
    buildings[9] = dynamic_cast<Building *> (board[14]);
    buildings[10] = dynamic_cast<Building *> (board[15]);
    buildings[11] = dynamic_cast<Building *> (board[16]);
    buildings[12] = dynamic_cast<Building *> (board[18]);
    buildings[13] = dynamic_cast<Building *> (board[19]);
    buildings[14] = dynamic_cast<Building *> (board[21]);
    buildings[15] = dynamic_cast<Building *> (board[23]);
    buildings[16] = dynamic_cast<Building *> (board[24]);
    buildings[17] = dynamic_cast<Building *> (board[25]);
    buildings[18] = dynamic_cast<Building *> (board[26]);
    buildings[19] = dynamic_cast<Building *> (board[27]);
    buildings[20] = dynamic_cast<Building *> (board[28]);
    buildings[21] = dynamic_cast<Building *> (board[29]);
    buildings[22] = dynamic_cast<Building *> (board[31]);
    buildings[23] = dynamic_cast<Building *> (board[32]);
    buildings[24] = dynamic_cast<Building *> (board[34]);
    buildings[25] = dynamic_cast<Building *> (board[35]);
    buildings[26] = dynamic_cast<Building *> (board[37]);
    buildings[27] = dynamic_cast<Building *> (board[39]);

    for (int i = 0; i < 8; i++) {
        player[i] = nullptr;
    }
    currentPlayer = player[0];
    textDisplay = new Display();
    /*playerSymbol[0] = 'G';
    playerSymbol[1] = 'B';
    playerSymbol[2] = 'D';
    playerSymbol[3] = 'P';
    playerSymbol[4] = 'S';
    playerSymbol[5] = '$';
    playerSymbol[6] = 'L';
    playerSymbol[7] = 'T';*/
}

void GameBoard::init() {
    cout << "Please enter the number of players. [2, 8]" << endl;
    int tmp;
    while (cin >> tmp) {
        if ((tmp >= 2) && (tmp < 8)) {
            numPlayers = tmp;
            break;
        } else {
            cout << "Sorry, you have to enter a number between 2 and 8." << endl;
        }
    }
    string name;
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Please enter the player" << i + 1 << "'s name." << endl;
        while (cin >> name) {
            while (name == "BANK") {
                cout << "Sorry, you can not choose Bank as your name.";
                cout << "Please choose a different one." << endl;
                cin >> name;
            }
            for (int j = 0; j < i; ++j) {
                if (player[j]->getName() == name) {
                    cout << "Sorry, the name exists. Please enter another name." << endl;
                    cin >> name;
                    break;
                }
            }
            cout << "Please choose your player symbol.(G/B/D/P/S/$/L/T)." << endl;
            char temp;
            while (cin >> temp) {
                if ((temp == 'G') || (temp == 'B') || (temp == 'D') || (temp == 'P') ||
                        (temp == 'S') || (temp == '$') || (temp == 'L') || (temp == 'T')) {
                    bool exist = false;
                    for (int j = 0; j < i; ++j) {
                        if (playerSymbol[j] == temp) {
                            exist = true;
                            break;
                        }
                    }
                    if (!exist) {
                        cout << "Now you have your symbol: " << temp << endl;
                        playerSymbol[i] = temp;
                        break;
                    } else cout << "Sorry, the symbol exists. Please choose another symbol." << endl;
                } else cout << "Symbol not exist. Please enter one of G/B/D/P/S/$/L/T." << endl;
            }
            player[i] = new Player(name, playerSymbol[i], i, 0);
            board[0]->addPlayer(playerSymbol[i]);
            break;
        }
    }
    cout << "Welcome to the game!" << endl;
    currentPlayer = player[0];

}

GameBoard::~GameBoard() {
    for (int i=0; i < 40; i++) {
        delete board[i];
    }
    for (int i=0; i < 28; i++) {
        delete buildings[i];
    }
    for (int i=0; i < 8; i++) {
        delete player[i];
    }
    delete dice;
    delete currentPlayer;
}

void GameBoard::displayGame() {
    textDisplay->printGameBoard(board);
}

Player* GameBoard::getPlayer(int playerIndex) {
    return player[playerIndex];
}

Player* GameBoard::getPlayer(string playerName) {
    for (int i = 0; i < 8; i++) {
        if (player[i]->getName() == playerName) {
            return player[i];
        }
    }
    return nullptr;
}

void GameBoard::setPlayer(int playerIndex) {
    currentPlayer = player[playerIndex];
}

Cell* GameBoard::getCell(int cellIndex) {
    return board[cellIndex];
}

Building* GameBoard::getBuilding(int buildingIndex) {
    return buildings[buildingIndex];
}

Building* GameBoard::getBuilding(string buildingName) {
    for (int i = 0; i < 28; i++) {
        if (buildings[i]->Cell::getName() == buildingName) {
            return buildings[i];
        }
    }
    return nullptr;
}

int GameBoard::getTotalCups() {
    return totalCups;
}

void GameBoard::notifyEvent() {
    board[currentPlayer->getPosition()]->doEvent(currentPlayer);
}

void GameBoard::roll() {
    int times = 1;
    dice->setValue();
    while (dice->getDoubleRoll() && times <= 3) {
        cout << "You have rolled a double. Roll again." << endl;
        dice->setDoubleRoll(false);
        dice->setValue();
        ++times;
    }
    int currentLocation = currentPlayer->getPosition();
    int futureLocation;
    if (times == 3 && dice->getDoubleRoll()) {
        currentPlayer->setPosition(10);
        cout << "You rolled three doubles in a roll, and will be sent to DC Times Line Directly." << endl;
        this->notifyPosition(currentLocation, 10);
    } else {
        int rollResult = dice->getValue();
        if ((rollResult + currentLocation) < 40) {
            futureLocation = rollResult + currentLocation;
        } else if (rollResult + currentLocation == 40) {
            futureLocation = 0;
        } else {
            futureLocation = rollResult + currentLocation - 40;
            currentPlayer->changeCash(200);
        }
        currentPlayer->setPosition(futureLocation);
        this->notifyPosition(currentLocation, futureLocation);
    }
    rolled = true;
    board[futureLocation]->doEvent(currentPlayer);
}

bool GameBoard::isWin() {
    if (numPlayers == 0) {
        cout << "No winner! Game over." << endl;
        return true;
    } else if (numPlayers == 1) {
        bool win[8];
        for (int i = 0; i < 8; ++i) {
            win[i] = true;
            if (player[i] != nullptr) {
                if (player[i]->getCash() < 0) {
                    win[i] = false;
                }
            } else {
                win[i] = false;
            }
        }
        int winnerIndex;
        for (int i = 0; i < 8; ++i) {
            if (win[i] == true) {
                winnerIndex = i;
            }
        }
        cout << "Now only one player left in our game!" << endl;
        cout << "Congratulations! " << player[winnerIndex] << " wins the game!" << endl;
        return true;
    }
    return false;
}

void GameBoard::auction(string buildingName) {
    cout << "Now we start the auction." << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "The building we are going to auction is: ";
    cout << getBuilding(buildingName)->getName() << endl;
    int leftPlayer = numPlayers;
    int highest = 0;
    bool bid[8];
    for (int i = 0; i < 8; i++) {
        bid[i] = true;
        if (player[i] != nullptr) {
            if (player[i]->getCash() < 0) {
                bid[i] = false;
            }
        } else {
            bid[i] = false;
        }
    }
    int winnerIndex;

    for (int i = 0; i < 8; ++i) {
        if (bid[i] == true) {
            winnerIndex = i;
        }
    }
    bool hasWinner = false;
    while (!hasWinner) {
        for (int i = 0; i < 8; ++i) {
            if (bid[i] == true) {
                cout << player[i]->getName() << " turn. The current highest bid is : ";
                cout << highest << ". Do you want to withdraw?:(Y/N)" << endl;
                char temp;
                cin >> temp;
                if (temp == 'Y') {
                    bid[i] = false;
                    --leftPlayer;
                    cout << player[i]->getName() << " withdrawed." << endl;
                } else {
                    cout << "Please enter your raised bid:" << endl;
                    int readBid;
                    cin >> readBid;
                    if (readBid > highest) {
                        if (readBid > player[i]->getCash()) {
                            cout << "Sorry. you don't have enough money." << endl;
                            bid[i] = false;
                            --leftPlayer;
                            cout << player[i]->getName() << " withdrawed." << endl;
                        }
                        highest = readBid;
                        winnerIndex = i;
                        cout << "Now you hold the highest bid." << endl;
                    } else {
                        cout << "Sorry, your bid is less than the highest one." << endl;
                        bid[i] = false;
                        --leftPlayer;
                        cout << player[i]->getName() << " withdrawed." << endl;
                    }
                }
                if (leftPlayer == 1) {
                    hasWinner = true;
                    winnerIndex = i;
                    cout << "Now only one player left in our auction." << endl;
                    cout << player[winnerIndex]->getName() << " wins the auction." << endl;
                    cout << player[winnerIndex]->getName() << " paid " << highest << endl;
                    player[winnerIndex]->changeCash(-highest);
                    player[winnerIndex]->buyBuilding(getBuilding(buildingName));
                    player[winnerIndex]->changeCash(getBuilding(buildingName)->getCost());
                }
                break;
            }
        }
    }
}

void GameBoard::roll(int roll1, int roll2) {
    int times = 1;
    while (roll1 == roll2 && times < 3) {
        cout << "You have rolled a double. Roll again." << endl;
        cout << "Please input your rolling result:" << endl;
        dice->setDoubleRoll(false);
        cin >> roll1;
        cin >> roll2;
        ++times;
    }
    int currentLocation = currentPlayer->getPosition();
    int futureLocation;
    if (times == 3 && roll1 == roll2) {
        currentPlayer->setPosition(10);
        cout << "You rolled three doubles in a roll, and will be sent to DC Times Line Directly." << endl;
        this->notifyPosition(currentLocation, 10);
    } else {
        if ((roll1 + roll2 + currentLocation) < 40) {
            futureLocation = roll1 + roll2 + currentLocation;
        } else if (roll1 + roll2 + currentLocation == 40) {
            futureLocation = 0;
        } else {
            futureLocation = roll1 + roll2 + currentLocation - 40;
            currentPlayer->changeCash(200);
            // Player add $200
        }
        currentPlayer->setPosition(futureLocation);
        this->notifyPosition(currentLocation, futureLocation);
    }
    rolled = true;
    board[futureLocation]->doEvent(currentPlayer);
}

void GameBoard::addCup() {
    ++totalCups;
    currentPlayer->addCup();
}

void GameBoard::removeCup() {
    --totalCups;
    currentPlayer->removeCup();
}

string GameBoard::getWinner() {
    for (int i = 0; i < 8; i++) {
        if (!player[i]->getBankrupt()) {
            return player[i]->getName();
        }
    }
    return "";
}

void GameBoard::notifyPosition(int preIndex, int postIndex) {
    Cell *preCell = getCell(preIndex);
    preCell->removePlayer(currentPlayer->getSymbol());
    Cell *postCell = getCell(postIndex);
    postCell->addPlayer(currentPlayer->getSymbol());
}

bool GameBoard::checkBankrupt(int owedMoney) {
    if (currentPlayer->getCash() >= owedMoney) {
        return false;
    } else if (currentPlayer->getCash() + currentPlayer->getAsset() < owedMoney) {
        return true;
    } else {
        cout << "You do not have enough cash to pay. Thus, \
        you may choose to trade or mortgage your properties." << endl;
        cout << "Please enter your command: " << endl;
        string command;
        while (currentPlayer->getCash() < owedMoney) {
            cin >> command;
            if (command == "trade" || command == "Trade") {
                string pname, give, receive;
                int gMoney, rMoney;
                cin >> pname >> give >> receive;
                Player *p = getPlayer(pname);
                stringstream ss1(give);
                stringstream ss2(receive);
                if (ss1 >> gMoney && !(ss2 >> rMoney)) {
                    Building *b = getBuilding(receive);
                    currentPlayer->trade(p, gMoney, b);
                } else if (!(ss1 >> gMoney) && ss2 >> rMoney) {
                    Building *b2 = getBuilding(give);
                    currentPlayer->trade(p, b2, rMoney);
                } else {
                    Building *bb1 = getBuilding(give);
                    Building *bb2 = getBuilding(receive);
                    currentPlayer->trade(p, bb1, bb2);
                }
            } else if (command == "mortgage" || command == "Mortgage") {
                string bname;
                cin >> bname;
                Building *bd = getBuilding(bname);
                currentPlayer->mortgage(bd);
            }
        }
        return false;
    }
}

void GameBoard::bankrupt() {
    --numPlayers;
    currentPlayer->setBankrupt(true);
    getCell(currentPlayer->getPosition())->removePlayer(currentPlayer->getSymbol());
    currentPlayer->changeCash(-(currentPlayer->getCash() + 1));
    cout << currentPlayer->getName() << " declares bankrupt." << endl;
    cout << numPlayers << " players left." << endl;
    for (int i = 0; i < 28; ++i) {
            if (currentPlayer->buildings[i] != nullptr) {
            AcademicBuilding *ac = dynamic_cast<AcademicBuilding *> (currentPlayer->buildings[i]);
            if (currentPlayer->buildings[i]->getMortgage()) {
                currentPlayer->buildings[i]->setMortgage(false);
            }
            if (ac) {
                ac->setImprovements(0);
            }
            // auction(currentPlayer->buildings[i]->getCellIndex());
            auction(currentPlayer->buildings[i]->getName());
        } else {
            break;
        }
    }
    currentPlayer->setCups(0);
    cout << currentPlayer->getName() << "'s assets have now be auctioned." << endl;
    player[currentPlayer->getIndex()] = nullptr;
    next();
}

void GameBoard::buy(Building *building) {
    cout << endl;
    char read;
    cout << "Do you want to buy " << building->getName() << " for $" << building->getCost() << "?" << endl;
    cout << "(Y/N)" << endl;
    cin >> read;
    if (read == 'Y') {
        if (checkBankrupt(building->getCost())) {
            cout << "Soory. Your can not afford this building this building." << endl;
        } else {
            currentPlayer->buyBuilding(building);
        }
    } else {
        cout << "You choose not to buy this building." << endl;
        
        auction(getCell(currentPlayer->getPosition())->getName());
    }
}

void GameBoard::bankrupt(Player *other) {
    --numPlayers;
    currentPlayer->setBankrupt(true);
    getCell(currentPlayer->getPosition())->removePlayer(currentPlayer->getSymbol());
    int transferedMoney = currentPlayer->getCash();
    currentPlayer->changeCash(-(currentPlayer->getCash() + 1));
    cout << currentPlayer->getName() << " declares bankrupt, and give property to ";
    cout << other->getName() << "." << endl;
    cout << "Money transfered: $" << transferedMoney << "." << endl;
    other->changeCash(transferedMoney);
    int transferedCups = currentPlayer->getOwnedCups();
    cout << "Roll Up the Rim Cups transfered: " << transferedCups << "." << endl;
    currentPlayer->setCups(0);
    other->setCups(transferedCups);
    cout << "Building transfered:" << endl;
    other->changeAsset(currentPlayer->getAsset());
    for (int i = 0; i < 28; ++i) {
        if (currentPlayer->buildings[i] != nullptr) {
            if (currentPlayer->buildings[i]->getMortgage()) {
                cout << currentPlayer->buildings[i]->getName() << " is mortgaged." << endl;
                int chargeFee = 0.1 * currentPlayer->buildings[i]->getCost();
                other->changeCash(-chargeFee);
                cout << "Do you want to unmortgage this building right now?" << endl;
                cout << "Enter (Y/N): ";
                char choice;
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                    other->unmortgage(currentPlayer->buildings[i]);
                    cout << "Player " << other->getName() << "has unmortgaged the building now." << endl;
                } else {
                    other->changeCash(-chargeFee);
                    cout << "Player " << other->getName() << "leave the property unmortgaged and is charged \
                    10 percent of original cost." << endl;
                }
            }
            other->buyBuilding(currentPlayer->buildings[i]);
            int cost = currentPlayer->buildings[i]->getCost();
            other->changeCash(cost);
        }
    }
    cout << currentPlayer->getName() << "'s assets have now be transfered to ";
    cout << other->getName() << endl;
    player[currentPlayer->getIndex()] = nullptr;
    next();
}

bool GameBoard::getIsWon() {
    return isWon;
}

void GameBoard::loadGame(string filename) {
    ifstream file;
    bool hasCurrentPlayer = false;
    file.open(filename);
    file >> numPlayers;


    // reading in players now
    string playerName;
    int timCups = 0;
    char symbol;
    int cash = 0;
    int position = 0;
    int timLine = -1;
    int wait = -1;

    for (int i = 0; i < numPlayers; ++i) {
        file >> playerName;
        file >> symbol;
        file >> timCups;
        file >> cash;
        file >> position;

        // player is in a tims line
        if (position == 10) {
            file >> timLine;
            if (timLine == 1) {
                file >> wait;
            }

        }
        Cell *tempCell = board[position];
        player[i] = new Player(playerName, symbol, timCups, cash, i, timLine, wait, position);
        tempCell->addPlayer(symbol);
        if (!hasCurrentPlayer) {
            currentPlayer = player[i];
            hasCurrentPlayer = true;
        }
        if (file.eof()) {
            cout << "Loading error." << endl;
            cout << "The most common error is incorrect format." << endl;
            return;
        }
    }
    string buildingName;
    string owner;
    int improvements;

    for (int i = 0; i < 28; ++i) {
        file >> buildingName;
        if (file.eof()) {
            cout << "Loading error." << endl;
            cout << "The most common error is incorrect format." << endl;
            return;
        }
        // reads in owner
        file >> owner;
        if (file.eof()) {
            cout << "Loading error." << endl;
            cout << "The most common error is incorrect format." << endl;
            return;
        }

        // reads in improvements
        file >> improvements;
        if (file.eof()) {
            cout << "Loading error." << endl;
            cout << "The most common error is incorrect format." << endl;
            return;
        }
        if (owner == "BANK") {
            continue;
        } else {
            Building *tempBuilding = buildings[i];
            Player *tempPlayer = this->getPlayer(owner);
            tempBuilding->setOwner(tempPlayer);
            tempPlayer->buyBuilding(tempBuilding);
            int tempCash = tempBuilding->getCost();
            AcademicBuilding *ac = dynamic_cast<AcademicBuilding *> (tempBuilding);
            if (improvements == -1) {
                tempBuilding->setMortgage(true);
                tempPlayer->changeAsset(-tempBuilding->getCost());
            }
            if (ac) {
                if (improvements == 0) {

                } else {
                    ac->changeLevel(improvements);
                }
                int tempAsset = (ac->getCurrentLevel() * ac->getImprovementCost());
                tempPlayer->changeAsset(tempAsset);
            }
            tempPlayer->changeCash(tempCash);


        }
    }
}

void GameBoard::next() {
    int temp = currentPlayer->getIndex();
    currentPlayer = nullptr;
    while (currentPlayer == nullptr) {
        if (temp < 7) {
            setPlayer(temp + 1);
            ++temp;
        } else {
            setPlayer(0);
            temp = 0;
        }
    }
    rolled = false;
}
