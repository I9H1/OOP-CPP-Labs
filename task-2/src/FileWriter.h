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
    FileWriter(string filename);
    void open();
    void write(vector<string> data);
    void close();
};