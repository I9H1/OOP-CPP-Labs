#include <iostream>
#include "FileWriter.h"

void FileWriter::open(string filename) {
    if (!file_ptr.is_open()) {
        file_ptr.open(filename);
    }
}

void FileWriter::close() {
    if (file_ptr.is_open()) {
        file_ptr.close();
    }
}

void FileWriter::WriteFileType() {
    file_ptr << "#Life 1.06";
}

void FileWriter::WriteName(std::string name) {
    file_ptr << endl << "#N " << name;
}

void FileWriter::WriteRules(vector<int> birth, vector<int> survival) {
    file_ptr << endl << "#R B";
    for (int i = 0; i < birth.size(); ++i) {
        file_ptr << birth[i];
    }
    file_ptr << "/S";
    for (int i = 0; i < survival.size(); ++i) {
        file_ptr << survival[i];
    }
}

void FileWriter::WriteSize(int size) {
    file_ptr << endl << "#S " << size;
}

void FileWriter::WriteField(vector<vector<bool>> field) {
    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field.size(); ++j) {
            if (field[i][j]) {
                file_ptr << endl << i << " " << j;
            }
        }
    }
}
