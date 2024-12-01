#include "FileReader.h"

FileReader::FileReader(std::string filename) {
    this->filename = filename;
}

void FileReader::open() {
    if (!file_ptr.is_open()) {
        file_ptr.open(filename);
        if (!file_ptr.is_open()) {
            throw "Wrong input filename";
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

bool FileReader::checkFormat() {
    file_ptr.seekg(0, ios_base::beg);
    string tmp;
    if (hasNext()) {
        getline(file_ptr, tmp);
    }
    return tmp == "#Life 1.06";
}

string FileReader::getName() {
    file_ptr.seekg(0, ios_base::beg);
    string tmp;
    for (int i = 0; i < 4; ++i) {
        if (hasNext()) {
            getline(file_ptr, tmp);
        }
        if (tmp.find("#N") != -1) {
            return tmp.substr(3, tmp.length() - 3);
        }
    }
    return "Nameless";
}

int FileReader::getSize() {
    file_ptr.seekg(0, ios_base::beg);
    string tmp;
    for (int i = 0; i < 4; ++i) {
        if (hasNext()) {
            getline(file_ptr, tmp);
        }
        if (tmp.find("#S") != -1) {
            return stoi(tmp.substr(3, tmp.length() - 3));
        }
    }
    return 10;
}

vector<int> FileReader::getBirthRule() {
    vector<int> birth_rule;
    file_ptr.seekg(0, ios_base::beg);
    string tmp;
    for (int i = 0; i < 4; ++i) {
        if (hasNext()) {
            getline(file_ptr, tmp);
        }
        if (tmp.find("#R") != -1) {
            for (int i = 4; i != tmp.find("/"); ++i) {
                birth_rule.push_back(tmp[i] - '0');
            }
            return birth_rule;
        }
    }
    birth_rule = {3};
    return birth_rule;
}

vector<int> FileReader::getSurvivalRule() {
    vector<int> survival_rule;
    file_ptr.seekg(0, ios_base::beg);
    string tmp;
    for (int i = 0; i < 4; ++i) {
        if (hasNext()) {
            getline(file_ptr, tmp);
        }
        if (tmp.find("#R") != -1) {
            for (int i = tmp.find("/") + 2; i < tmp.length(); ++i) {
                survival_rule.push_back(tmp[i] - '0');
            }
            return survival_rule;
        }
    }
    survival_rule = {2, 3};
    return survival_rule;
}

vector<pair<int, int>> FileReader::getCoords() {
    vector<pair<int, int>> coords = {};
    string tmp;
    file_ptr.seekg(0, ios_base::beg);
    do {
        getline(file_ptr, tmp);
    } while (tmp.find("#") != -1 and hasNext());
    if (tmp.find("#") != -1)
        return coords;
    do {
        int x = stoi(tmp.substr(0, tmp.find(" ")));
        int y = stoi(tmp.substr(tmp.find(" ") + 1, tmp.size() - tmp.find(" ") - 1));
        pair<int, int> new_pair = {x, y};
        coords.push_back(new_pair);
    } while (getline(file_ptr, tmp));
    return coords;
}
