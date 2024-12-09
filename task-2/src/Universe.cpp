#include "Universe.h"

using namespace std;

Universe::Universe(UniverseConfig config) {
    this->config = config;
}

int Universe::countNeighbors(int x, int y) {
    int result = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            int n_x, n_y;
            if (x + i == -1) n_x = config.size - 1;
            else if (x + i == config.size) n_x = 0;
            else n_x = x + i;
            if (y + j == -1) n_y = config.size - 1;
            else if (y + j == config.size) n_y = 0;
            else n_y = y + j;
            if (n_x != x or n_y != y) {
                result += config.field[n_x][n_y];
            }
        }
    }
    return result;
}

void Universe::setField(vector<vector<bool>> new_field) {
    config.field = new_field;
    config.size = new_field.size();
}

void Universe::printField() {
    for (int i = 0; i < config.size; ++i) {
        for (int j = 0; j < config.size; ++j) {
            if (config.field[i][j]) cout << "* ";
            else cout << ". ";
        }
        cout << endl;
    }
}

void Universe::printInfo() {
    cout << "Name: " << config.name;
    cout << "\nFor birth: ";
    for (int i = 0; i < config.birth_rule.size(); ++i) {
        cout << config.birth_rule[i];
    }
    cout << "\nFor survival: ";
    for (int i = 0; i < config.survival_rule.size(); ++i) {
        cout << config.survival_rule[i];
    }
    cout << endl;
}

string Universe::getName() {
    return config.name;
}

int Universe::getSize() {
    return config.size;
}

vector<int> Universe::getBirthRule() {
    return config.birth_rule;
}

vector<int> Universe::getSurvivalRule() {
    return config.survival_rule;
}

vector<vector<bool>> Universe::getField() {
    return config.field;
}
