#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Universe {
private:
    int size;
    string name;
    vector<vector<bool>> field;
    vector<int> birth_rule;
    vector<int> survival_rule;

public:
    Universe(int size, string name, vector<int> birth, vector<int> survival,
             vector<pair<int, int>> alive);
    int countNeighbors(int x, int y);
    void setAlive(int x, int y);
    void setDead(int x, int y);
    void setField(vector<vector<bool>> new_field);
    bool isAlive(int x, int y);
    void printInfo();
    void printField();
    string getName();
    vector<int> getBirthRule();
    vector<int> getSurvivalRule();
    vector<vector<bool>> getField();
    int getSize();
};
