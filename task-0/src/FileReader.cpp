#include "FileReader.h"

using namespace std;

FileReader::FileReader(string p_filename) {
    filename = p_filename;
}

bool FileReader::open() {
    if (!file_ptr.is_open()) {
        file_ptr.open(filename);
    }
    return file_ptr.is_open();
}

void FileReader::close() {
    if (file_ptr.is_open())
        file_ptr.close();
}

bool FileReader::hasNext() {
    return !file_ptr.eof();
}

string FileReader::getNext() {
    string new_string;
    getline(file_ptr, new_string);
    return new_string;
}
