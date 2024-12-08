#pragma once
#include <string>
#include <fstream>

using namespace std;

class FileReader {
protected:
    string filename;
    ifstream file_ptr;

public:
    FileReader(string p_filename);
    bool open(ios_base::openmode mode = ios_base::in);
    void close();
    bool hasNext();
    string getNext();
    void read(char* ptr, size_t size);
};
