#include "ConfigParser.h"
#include <sstream>
#include <iostream>

Command ConfigParser::parseLine(std::string line) {
    Command command;
    stringstream stream(line);
    string word = "";
    while (getline(stream, word, ' ')) {
        if (command.name.empty())
            command.name = word;
        else
            command.args.push_back(word);
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