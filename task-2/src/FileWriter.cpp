#include <iostream>
#include "FileWriter.h"

FileWriter::FileWriter(string p_filename) {
    filename = p_filename;
}

void FileWriter::open() {
    if (!file_ptr.is_open()) {
        file_ptr.open(filename);
    }
}

void FileWriter::close() {
    if (file_ptr.is_open()) {
        file_ptr.close();
    }
}

void FileWriter::write(vector<string> data) {
    for(int i = 0; i < data.size(); ++i) {
        file_ptr << data[i];
        if (i != data.size() - 1) {
            file_ptr << endl;
        }
    }
}
