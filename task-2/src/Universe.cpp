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
            if (x + i > 0 and y + i > 0 and x + i < size and y + j < size) {
                result += field[i][j];
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

void Universe::printField() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << field[i][j] << " ";
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
