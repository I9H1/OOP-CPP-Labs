#include "FileReader.h"

FileReader::FileReader(std::string filename) {
    this->filename = filename;
}

void FileReader::open() {
    if (!file_ptr.is_open()) {
        file_ptr.open(filename);
        if (!file_ptr.is_open()) {
            throw "Wrong input filename!";
        }
    }
}

void FileReader::close() {
    if (file_ptr.is_open()) {
        file_ptr.close();
    }
}

bool FileReader::hasNext() {
    return !file_ptr.eof();
}

string FileReader::getNext() {
    string new_string;
    getline(file_ptr, new_string);
    return new_string;
}

void FileReader::reset() {
    file_ptr.seekg(0, ios_base::beg);
}
