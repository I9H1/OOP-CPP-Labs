#include <algorithm>
#include "Game.h"
#include "FileWriter.h"

using namespace std;

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
    vector<vector<bool>> new_field;
    int size = universe.getSize();
    for (int i = 0; i < size; ++i) {
        vector<bool> row(size, false);
        new_field.push_back(row);
    }
    vector<int> birth = universe.getBirthRule();
    vector<int> survival = universe.getSurvivalRule();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int neighbors = universe.countNeighbors(i, j);
            if (!universe.getField()[i][j] and
                find(birth.begin(), birth.end(), neighbors) != birth.end()) {
                new_field[i][j] = true;
            } else if (universe.getField()[i][j] and
                       find(survival.begin(), survival.end(), neighbors) != survival.end()) {
                new_field[i][j] = true;
            }
        }
    }
    universe.setField(new_field);
}

void Game::dump(string filename) {
    FileWriter output_file(filename);
    vector<string> data;
    output_file.open();
    data.push_back("#Life 1.06");
    data.push_back("#N " + universe.getName());
    vector<int> birth = universe.getBirthRule();
    vector<int> survival = universe.getSurvivalRule();
    string rules = "#R B";
    for (int i = 0; i < birth.size(); ++i) {
        rules += to_string(birth[i]);
    }
    rules += "/S";
    for (int i = 0; i < survival.size(); ++i) {
        rules += to_string(survival[i]);
    }
    data.push_back(rules);
    data.push_back("#S " + to_string(universe.getSize()));
    vector<vector<bool>> field = universe.getField();
    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field.size(); ++j) {
            if (field[i][j]) {
                data.push_back(to_string(i) + " " + to_string(j));
            }
        }
    }
    output_file.write(data);
    output_file.close();
}