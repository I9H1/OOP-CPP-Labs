#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FileReader {
private:
    string filename;
    ifstream file_ptr;
    bool hasNext();

public:
    FileReader(string filename);
    void open();
    string getName();
    int getSize();
    vector<int> getBirthRule();
    vector<int> getSurvivalRule();
    vector<pair<int, int>> getCoords();
    void close();
};
