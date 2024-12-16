#pragma once
#include <string>
#include <vector>
#include <string>

using namespace std;

struct InitParameters {
    bool description_required;
    string config_filename;
    string output_filename;
    vector<string> input_filenames;
};

class CMDParser {
private:
    InitParameters parameters;
    bool CheckIfValid();

public:
    CMDParser();
    InitParameters parse(int argc, char** argv);
    void printHelp();
};
