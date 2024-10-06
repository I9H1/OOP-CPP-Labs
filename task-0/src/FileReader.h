#pragma once
#include <string>
#include <fstream>

using namespace std;

class FileReader {
    private:
        string filename;
        ifstream file_ptr;
    public:
        FileReader(string p_filename);
        bool open();
        void close();
        bool has_next();
        string get_next();
};
