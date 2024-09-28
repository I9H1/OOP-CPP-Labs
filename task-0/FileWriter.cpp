#include "FileWriter.h"

using namespace std;

FileWriter::FileWriter(string p_filename) {
    filename = p_filename;
}

void FileWriter::open() {
    if (!file_ptr.is_open()) {
        file_ptr.open(filename);
    }
}

void FileWriter::write_data(vector<string> data) {
    for(string i : data) {
        file_ptr << i << endl;
    }
}

void FileWriter::close() {
    if (file_ptr.is_open())
        file_ptr.open(filename);
}
