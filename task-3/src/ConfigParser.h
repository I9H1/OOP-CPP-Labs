#include "FileReader.h"
#include <fstream>
#include <string>
#include <vector>

struct Command {
    string name;
    vector<string> args;
};

class ConfigParser {
private:
    FileReader file;
    vector<string> input_files;
    Command parseLine(string line);
    bool isNumber(string str);

public:
    ConfigParser(string filename, vector<string> input_files)
        : file(filename) { this->input_files = input_files; }
    vector<Command> parse();
};
