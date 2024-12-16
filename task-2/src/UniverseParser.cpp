#include "UniverseParser.h"
#include "FileReader.h"

using namespace std;

bool UniverseParser::checkFormat() {
    file.reset();
    if (file.hasNext()) {
        if (file.getNext() == "#Life 1.06") {
            return true;
        }
    }
    return false;
}

vector<vector<bool>> UniverseParser::getField(int size) {
    vector<vector<bool>> field;
    for (int i = 0; i < size; ++i) {
        vector<bool> row(size, false);
        field.push_back(row);
    }
    string tmp;
    file.reset();
    while (file.hasNext()) {
        tmp = file.getNext();
        if (tmp.find("#") == -1) {
            int x = stoi(tmp.substr(0, tmp.find(" ")));
            int y = stoi(tmp.substr(tmp.find(" ") + 1, tmp.size() - tmp.find(" ") - 1));
            field[x][y] = true;
        }
    }
    return field;
}

UniverseConfig UniverseParser::parse(string filename) {
    file = FileReader(filename);
    file.open();
    if (!checkFormat()) {
        file.close();
        throw "Wrong file format!";
    }
    UniverseConfig config;
    config.name = "Nameless";
    config.size = 10;
    string tmp;
    for (int i = 0; i < 3; ++i) {
        if (file.hasNext()) {
            tmp = file.getNext();
        }
        if (tmp.find("#R") != -1) {
            for (int i = 4; i != tmp.find("/"); ++i) {
                config.birth_rule.push_back(tmp[i] - '0');
            }
            for (int i = tmp.find("/") + 2; i < tmp.length(); ++i) {
                config.survival_rule.push_back(tmp[i] - '0');
            }
        } else if (tmp.find("#N") != -1) {
            config.name = tmp.substr(3, tmp.length() - 3);
        } else if (tmp.find("#S") != -1) {
            config.size = stoi(tmp.substr(3, tmp.length() - 3));
        }
    }
    if (config.birth_rule.empty()) {
        config.birth_rule = {3};
    }
    if (config.survival_rule.empty()) {
        config.survival_rule = {2, 3};
    }
    config.field = getField(config.size);
    file.close();
    return config;
}
