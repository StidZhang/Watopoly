#ifndef WATOPOLY_GAMEBOARD_H
#define WATOPOLY_GAMEBOARD_H

#include <string>

class Cell;
class Dice;
class Player;
class Building;
class Display;

class GameBoard {
    Cell *board[40];
    Building *buildings[28];
    Dice *dice;
    bool isWon = false;
    Player *player[8];
    int totalCups;
    Display *textDisplay;
    char playerSymbol[8];

public:
    bool rolled;
    int numPlayers;
    Player *currentPlayer;
    GameBoard();
    ~GameBoard();
    void displayGame();
    Player *getPlayer(int playerIndex);
    Player *getPlayer(std::string playerName);
    Cell *getCell(int cellIndex);
    Building *getBuilding(int buildingIndex);
    Building *getBuilding(std::string buildingName);
    void setPlayer(int playerIndex);
    void notifyEvent();
    int getTotalCups();
    void bankrupt();
    bool isWin();
    bool getIsWon();
    void auction(std::string buildingName);
    void buy(Building *building);
    std::string getWinner();
    void roll();
    void roll(int roll1, int roll2);
    void addCup();
    void removeCup();
    void init();
    void notifyPosition(int preIndex, int postIndex);
    bool checkBankrupt(int owedMoney);
    void bankrupt(Player *other);
    void loadGame(std::string filename);
    void next();
};


#endif //WATOPOLY_GAMEBOARD_H
