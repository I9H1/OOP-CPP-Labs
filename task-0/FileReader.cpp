#include "FileReader.h"

using namespace std;

FileReader::FileReader(string p_filename) {
    filename = p_filename;
}

void FileReader::open() {
    if (!file_ptr.is_open()) {
        file_ptr.open(filename);
    }
}

void FileReader::close() {
    if (file_ptr.is_open())
        file_ptr.close();
}

bool FileReader::has_next() {
    return !file_ptr.eof();
}

string FileReader::get_next() {
    string new_string;
    getline(file_ptr, new_string);
    return new_string;
}
