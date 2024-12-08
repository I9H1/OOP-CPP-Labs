#include <fstream>
#include <vector>
#include <string>
#include "FileReader.h"

struct Command {
    string name;
    vector<string> args;
};

class ConfigParser {
private:
    FileReader file;
    Command parseLine(string line);

public:
    ConfigParser(string filename) : file(filename) {}
    vector<Command> parse();
};
