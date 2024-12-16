#include "FileWriter.h"

using namespace std;

FileWriter::FileWriter(string p_filename) {
    filename = p_filename;
}

bool FileWriter::open(ios_base::openmode mode) {
    if (!file_ptr.is_open()) {
        file_ptr.open(filename, mode);
        if (!file_ptr.is_open()) {
            throw "Cannot open file " + filename;
        }
    }
    return file_ptr.is_open();
}

void FileWriter::write(char* ptr, size_t size) {
    file_ptr.write(ptr, size);
}

void FileWriter::close() {
    if (file_ptr.is_open()) {
        file_ptr.close();
    }
}

void FileWriter::writeString(std::string data) {
    file_ptr << data << endl;
}
