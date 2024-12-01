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
    FileWriter output_file;
    output_file.open(filename);
    output_file.WriteFileType();
    output_file.WriteName(universe.getName());
    output_file.WriteRules(universe.getBirthRule(), universe.getSurvivalRule());
    output_file.WriteSize(universe.getSize());
    output_file.WriteField(universe.getField());
    output_file.close();
}