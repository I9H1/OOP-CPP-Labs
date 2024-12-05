#pragma once
#include "Universe.h"
#include "FileReader.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UniverseParser {
private:
    FileReader file;
    bool checkFormat();
    vector<vector<bool>> getField(int size);

public:
    UniverseParser() : file("") {}
    UniverseConfig parse(string filename);
};
