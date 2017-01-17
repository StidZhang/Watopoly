#ifndef WATOPOLY_CONTROLLER_H
#define WATOPOLY_CONTROLLER_H

#include <string>
#include <fstream>
class GameBoard;
class Player;
class Display;


class Controller {
    GameBoard *g;
    bool testing = false;

public:
    Controller();
    ~Controller();
    void loadGame(std::string filename);
    void play();
    void saveGame(std::string filename);
    void displayAssets();
    void displayAll();
    void setTesting();
    void init();
};


#endif //WATOPOLY_CONTROLLER_H
