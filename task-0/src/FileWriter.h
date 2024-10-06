#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileWriter {
    private:
        string filename;
        ofstream file_ptr;
    public:
        FileWriter(string filename);
        bool open();
        void write_data(vector<string> data);
        void close();
};

