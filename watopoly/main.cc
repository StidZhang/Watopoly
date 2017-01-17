#include <iostream>
#include <fstream>
#include <string>
#include "GameBoard.h"
#include "Controller.h"

using namespace std;

int main(int argc, char *argv[]) {
    Controller *c = new Controller();
    string filename;
    bool loaded = false;

    if (argc > 1) {
        string argv1 = argv[1];
        if (argv1 == "-testing") {
            c->setTesting();
            if (argc > 2) {
                string argv2 = argv[2];
                if (argv2 == "-load") {
                    string filename = argv[3];
                    c->loadGame(filename);
                    loaded = true;
                }
            }
        } else if (argv1 == "-load") {
            string filename = argv[2];
            c->loadGame(filename);
            loaded = true;
        }
    }
    cout << "Welcome to The Game of Watopoly!" << endl;
    if (!loaded) c->init();
    c->play();
    delete c;
}
