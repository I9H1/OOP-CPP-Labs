#pragma once
#include "Universe.h"
#include <iostream>
#include <string>

using namespace std;

class Game {
private:
    Universe universe;
public:
    Game(UniverseConfig config) : universe(config) {}
    bool is_on;
    void dump(string filename);
    void tick();
    void printHelp();
    void printUniverse();
};
