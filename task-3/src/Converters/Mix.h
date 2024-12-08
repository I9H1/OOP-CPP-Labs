#pragma once
#include "Converter.h"
#include <vector>
#include <string>

class Mix : public Converter {
private:
    vector<string> args;

public:
    void convertSound(WAVReader& file_in, WAVWriter& file_out) override;
    string getDescription() override;
    void setConfig(vector<string> args) override;
};
