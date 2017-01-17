#include "Controller.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "GameBoard.h"
#include "Player.h"
#include "Building.h"
#include "AcademicBuilding.h"
using namespace std;

Controller::Controller() {
    g = new GameBoard;
}

Controller::~Controller() {
    delete g;
}

void Controller::loadGame(string filename) {
    g->loadGame(filename);
}

void Controller::play() {
    while (!g->isWin()) {
        cout << "What do you want to do, " << g->currentPlayer->getName() << "?" << endl;
        cout << "Enter help to view valid command" << endl;
        string cmd;
        cin >> cmd;
        if (cmd == "roll") {
            if (g->rolled) {
                cout << "You have rolled dice in this term!" << endl;
                continue;
            }
            if (testing) {
                string input;
                getline(cin, input);
                if (input != "") {
                    istringstream iss{input};
                    int die1 = 0;
                    int die2 = 0;
                    iss >> die1;
                    iss >> die2;
                    if ((0 <= die1) && (die1 <= 6) && (0 <= die2) && (die2 <= 6)) {
                        g->roll(die1, die2);
                    } else {
                        g->roll();
                    }
                } else {
                    g->roll();
                }
            } else {
                g->roll();
            }
        } else if (cmd == "next") {
            g->next();
        } else if (cmd == "trade") {
            string target;
            string give;
            string receive;
            cin >> target;
            cin >> give;
            cin >> receive;
            Player *trader = g->getPlayer(target);
            int number1;
            int number2;
            stringstream convertGive(give);
            stringstream convertReceive(receive);
            if (!(convertGive >> number1)) {
                if (!(convertReceive >> number2)) {
                    Building *tempBuilding1 = g->getBuilding(give);
                    Building *tempBuilding2 = g->getBuilding(receive);
                    g->currentPlayer->trade(trader, tempBuilding1, tempBuilding2);
                } else {
                    Building *tempBuilding1 = g->getBuilding(give);
                    g->currentPlayer->trade(trader, tempBuilding1, number2);
                }
            } else {
                Building *tempBuilding2 = g->getBuilding(receive);
                g->currentPlayer->trade(trader, number1, tempBuilding2);
            }

        } else if (cmd == "improve") {
            string buildingName;
            string option;
            cin >> buildingName;
            cin >> option;
            Building *temp = g->getBuilding(buildingName);
            if (option == "buy") {
                g->currentPlayer->buyImprovement(temp);
            } else if (option == "sell") {
                g->currentPlayer->sellImprovement(temp);
            }
        } else if (cmd == "mortgage") {
            string buildingName;
            cin >> buildingName;
            Building *temp = g->getBuilding(buildingName);
            g->currentPlayer->mortgage(temp);
        } else if (cmd == "unmortgage") {
            string buildingName;
            cin >> buildingName;
            Building *temp = g->getBuilding(buildingName);
            g->currentPlayer->unmortgage(temp);
        } else if (cmd == "bankrupt") {
            if (g->checkBankrupt(0)) {
                g->bankrupt();
            } else {
                cout << "You can not declare bankrupt, you still have have cash now. Good luck!." << endl;
            }
        } else if (cmd == "assets") {
            this->displayAssets();
        } else if (cmd == "all") {
            this->displayAll();
        } else if (cmd == "save") {
            string filename;
            cin >> filename;
            this->saveGame(filename);
        } else if (cmd == "quit") {
            break;
        } else if (cmd == "print") {
            g->displayGame();
        } else if (cmd == "help") {
            cout << "roll (used if the player can roll): the player rolls two dice, moves the sum of the two dice and takes" << endl;
            cout << "action on the square they landed on." << endl;
            cout << "next (used if the player cannot roll): give control to the next player." << endl;
            cout << "trade <name> <give> <receive>: offers a trade to name with the current player offering give" << endl;
            cout << "and requesting receive, where give and receive are either amounts of money or a property name." << endl;
            cout << "Responses are accept and reject" << endl;
            cout << "improve <property> buy/sell: attempts to buy or sell an improvement for property." << endl;

        } else if (cmd == "ILOVECS") {
            g->currentPlayer->changeCash(2000);
        } else if (cmd == "ILOVEMATH") {
            g->currentPlayer->changeCash(500);
        } else if (cmd == "ILOVETIMS") {
            if (g->getTotalCups() >= 4) {
                cout << "No more Cups." << endl;
            } else {
                g->addCup();
            }
        } else if (cmd == "IHATECS") {
            g->notifyPosition(30, 10);
            g->currentPlayer->setPosition(10);
            g->currentPlayer->setIsTimLine(true);
            g->currentPlayer->setTimLineWait(0);
            g->notifyEvent();
        } else {
            cout << "Invalid Command!" << endl;
            cout << "Please enter another command:" << endl;
        }
        if (g->getIsWon()) break;
    }
}

void Controller::init() {
    g->init();
}

void Controller::saveGame(string filename) {
    ofstream savedGame;
    savedGame.open(filename);
    savedGame << g->numPlayers << endl;
    for (int i = 0; i < 8; i++) {
        Player *temp = g->getPlayer(i);
        if (temp == nullptr) {
            continue;
        }
        savedGame << temp->getName() << " " << temp->getSymbol() << " ";
        savedGame << temp->getOwnedCups() << " " << temp->getCash() << " ";
        savedGame << temp->getPosition();
        if (temp->getPosition() == 10) {
            if (temp->getIsTimLine()) {
                savedGame << " 1 " << temp->getNumLineWait();
            } else {
                savedGame << " 0";
            }
        }
        savedGame << endl;
    }
    for (int i = 0; i < 28; i++) {
        Building *temp = g->getBuilding(i);
        string buildingName = temp->getName();
        string ownerName;
        int improvementStatus;
        if (!temp->getOwner()) {
            ownerName = "BANK";
        } else {
            ownerName = temp->getOwner()->getName();
        }
        if (temp->getMortgage()) {
            improvementStatus = -1;
        } else {
            improvementStatus = temp->getCurrentLevel();
        }
        savedGame << temp->getName() << " " << ownerName << " " << \
                improvementStatus << endl;
    }
    savedGame.close();
}

void Controller::displayAll() {
    if (g->currentPlayer->getPosition() == 4) {
        cout << "You are paying tuition now! Cannot show assets." << endl;
    } else {
        for (int i = 0; i < 8; i++) {
            Player *temp = g->getPlayer(i);
            if (temp == nullptr) {
                continue;
            }
            temp->printAsset();
        }
    }
}

void Controller::displayAssets() {
    if (g->currentPlayer->getPosition() == 4) {
        cout << "You are paying tuition now! Cannot show assets." << endl;
    } else {
        g->currentPlayer->printAsset();
    }
}

void Controller::setTesting() {
    testing = true;
}
