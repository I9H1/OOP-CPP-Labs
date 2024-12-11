#include "ConfigParser.h"
#include <sstream>

bool ConfigParser::isNumber(std::string str) {
    for (int i = 0; i < str.size(); ++i) {
        if (!isdigit(str[0])) {
            return false;
        }
    }
    return true;
}

Command ConfigParser::parseLine(std::string line) {
    Command command;
    stringstream stream(line);
    string word = "";
    while (getline(stream, word, ' ')) {
        if (command.name.empty()) {
            command.name = word;
        } else {
            if (word.find('$') == 0) {
                string index = word.substr(1);
                if (!isNumber(index)) {
                    throw "Invalid arguments!";
                }
                if (input_files.size() < stoi(index)) {
                    throw "Invalid arguments!";
                }
                command.args.push_back(input_files[stoi(index) - 1]);
            } else {
                command.args.push_back(word);
            }
        }
    }
    return command;
}

vector<Command> ConfigParser::parse() {
    vector<Command> commands;
    if (!file.open()) {
        throw "Cannot open configuration file!";
    }
    string new_line;
    while (file.hasNext()) {
        new_line = file.getNext();
        if (new_line[0] == '#' or new_line.empty())
            continue;
        Command new_command = parseLine(new_line);
        commands.push_back(new_command);
    }
    file.close();
    return commands;
}