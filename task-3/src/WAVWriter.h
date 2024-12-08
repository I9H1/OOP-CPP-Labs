#pragma once
#include "FileWriter.h"
#include "WAVformat.h"

class WAVWriter : public FileWriter {
public:
    WAVWriter(string filename) : FileWriter(filename) {}
    void writeHeader(WAVHeader header);
    void writeSample(uint16_t sample);
};
