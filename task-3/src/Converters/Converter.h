#pragma once
#include "WAVReader.h"
#include "WAVWriter.h"

class Converter {
public:
    virtual void convertSound(WAVReader &file_in, WAVWriter &file_out) = 0;
    virtual string getDescription() = 0;
    virtual void setConfig(vector<string> args) = 0;
    virtual ~Converter() = default;
};
