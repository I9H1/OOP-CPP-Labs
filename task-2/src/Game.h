#pragma once
#include "Universe.h"
#include <iostream>
#include <string>

using namespace std;

class Game {
private:
    Universe universe;
public:
    Game(int size, string name, vector<int> birth, vector<int> survival,
         vector<pair<int, int>> alive) : universe(size, name, birth, survival, alive) {}
    bool is_on;
    void dump(string filename);
    void tick();
    void printHelp();
    void printUniverse();
};
