#pragma once
#include "Converter.h"
#include <vector>
#include <string>

using namespace std;

class Mute : public Converter {
private:
    int from_time;
    int to_time;

public:
    void convertSound(WAVReader& file_in, WAVWriter& file_out) override;
    string getDescription() override;
    void setConfig(vector<string> args) override;
};
