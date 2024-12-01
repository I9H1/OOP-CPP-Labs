#include "Universe.h"

using namespace std;

Universe::Universe(int size, string name, vector<int> birth, vector<int> survival,
                   vector<pair<int, int>> alive) {
    this->size = size;
    this->name = name;
    for (int i = 0; i < size; ++i) {
        vector<bool> row(size, false);
        this->field.push_back(row);
    }
    this->birth_rule = birth;
    this->survival_rule = survival;
    for (int i = 0; i < alive.size(); ++i) {
        setAlive(alive[i].first, alive[i].second);
    }
}

int Universe::countNeighbors(int x, int y) {
    int result = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            int n_x, n_y;
            if (x + i == -1) n_x = size - 1;
            else if (x + i == size) n_x = 0;
            else n_x = x + i;
            if (y + j == -1) n_y = size - 1;
            else if (y + j == size) n_y = 0;
            else n_y = y + j;
            if (n_x != x or n_y != y) {
                result += field[n_x][n_y];
            }
        }
    }
    return result;
}

bool Universe::isAlive(int x, int y) {
    return field[x][y];
}

void Universe::setAlive(int x, int y) {
    field[x][y] = true;
}

void Universe::setDead(int x, int y) {
    field[x][y] = false;
}

void Universe::setField(vector<vector<bool>> new_field) {
    field = new_field;
    size = new_field.size();
}

void Universe::printField() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (field[i][j]) cout << "* ";
            else cout << ". ";
        }
        cout << endl;
    }
}

void Universe::printInfo() {
    cout << "Name: " << name;
    cout << "\nFor birth: ";
    for (int i = 0; i < birth_rule.size(); ++i) {
        cout << birth_rule[i];
    }
    cout << "\nFor survival: ";
    for (int i = 0; i < survival_rule.size(); ++i) {
        cout << survival_rule[i];
    }
    cout << endl;
}

string Universe::getName() {
    return name;
}

int Universe::getSize() {
    return size;
}

vector<int> Universe::getBirthRule() {
    return birth_rule;
}

vector<int> Universe::getSurvivalRule() {
    return survival_rule;
}

vector<vector<bool>> Universe::getField() {
    return field;
}
