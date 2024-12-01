#pragma once
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class FileWriter {
private:
    string filename;
    ofstream file_ptr;

public:
    void open(string filename);
    void WriteFileType();
    void WriteName(string name);
    void WriteSize(int size);
    void WriteRules(vector<int> birth, vector<int> survival);
    void WriteField(vector<vector<bool>> field);
    void close();
};