#include "Game.h"

void Game::printHelp() {
    cout << "Help:\ndump <filename> - save universe in file\n"
            "tick <n=1> - calculate n iterations and print result\n"
            "exit - stop the game\n";
}

void Game::printUniverse() {
    universe.printInfo();
    universe.printField();
}

void Game::tick() {

}