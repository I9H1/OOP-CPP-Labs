#pragma once
#include <fstream>
#include <iostream>

using namespace std;

class FileReader {
private:
    string filename;
    ifstream file_ptr;

public:
    FileReader(string filename);
    string getNext();
    bool hasNext();
    void reset();
    void open();
    void close();
};
