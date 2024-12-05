#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct UniverseConfig {
    int size;
    string name;
    vector<vector<bool>> field;
    vector<int> birth_rule;
    vector<int> survival_rule;
};

class Universe {
private:
    UniverseConfig config;

public:
    Universe(UniverseConfig config);
    int countNeighbors(int x, int y);
    void setField(vector<vector<bool>> new_field);
    void printInfo();
    void printField();
    string getName();
    vector<int> getBirthRule();
    vector<int> getSurvivalRule();
    vector<vector<bool>> getField();
    int getSize();
};
