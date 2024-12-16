#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileWriter {
protected:
    string filename;
    ofstream file_ptr;

public:
    FileWriter(string filename);
    bool open(ios_base::openmode mode = ios_base::out);
    void writeString(string data);
    void write(char* ptr, size_t size);
    void close();
};
