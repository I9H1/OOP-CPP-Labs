#include "CMDParser.h"
#include <iostream>

using namespace std;

CMDParser::CMDParser() {
    parameters.description_required = false;
    parameters.config_filename = "";
    parameters.output_filename = "";
}

InitParameters CMDParser::parse(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        string argv_s = static_cast<string>(argv[i]);
        if (argv_s == "-h") {
            parameters.description_required = true;
        } else if (argv_s == "-c" and i < argc - 1) {
            parameters.config_filename = static_cast<string>(argv[i + 1]);
            ++i;
        } else if (parameters.output_filename == "") {
            parameters.output_filename = argv_s;
        } else {
            parameters.input_filenames.push_back(argv_s);
        }
    }
    if (!CheckIfValid()) {
        throw "Invalid execution parameters!";
    }
    return parameters;
}

bool CMDParser::CheckIfValid() {
    const bool ch1 = parameters.output_filename == "";
    const bool ch2 = parameters.input_filenames.empty();
    const bool ch3 = parameters.config_filename == "";
    if (ch1 or ch2 or ch3) {
        return false;
    }
    return true;
}

void CMDParser::printHelp() {
    cout << "Utilite format:\n>> sound_processor [-h] -c <config.txt> "
            "<output.wav> <input1.wav> [<input2.wav> ...]\n[] - optional parameters\n";
}
