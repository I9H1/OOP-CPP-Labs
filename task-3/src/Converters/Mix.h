#pragma once
#include "Converter.h"
#include <vector>
#include <string>

class Mix : public Converter {
private:
    string mixing_file_name;
    int from_time;
    bool isNumber(string str);

public:
    void convertSound(WAVReader& file_in, WAVWriter& file_out) override;
    string getDescription() override;
    void setConfig(vector<string> args) override;
};
