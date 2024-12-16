#include "FileReader.h"

using namespace std;

FileReader::FileReader(string p_filename) {
    filename = p_filename;
}

bool FileReader::open(ios_base::openmode mode) {
    if (!file_ptr.is_open()) {
        file_ptr.open(filename, mode);
        if (!file_ptr.is_open()) {
            throw "Cannot open file!";
        }
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

void FileReader::read(char *ptr, size_t size) {
    file_ptr.read(ptr, size);
}
