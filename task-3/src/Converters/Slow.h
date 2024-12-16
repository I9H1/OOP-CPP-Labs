#pragma once
#include "Converter.h"
#include <string>
#include <vector>

class Slow : public Converter {
private:
    int from_time;
    int to_time;
    bool isNumber(string str);

public:
    void convertSound(WAVReader &file_in, WAVWriter &file_out) override;
    string getDescription() override;
    void setConfig(vector<string> args) override;
};
