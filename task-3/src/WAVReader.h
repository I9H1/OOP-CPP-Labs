#pragma once
#include "FileReader.h"
#include "WAVformat.h"

class WAVReader : public FileReader {
private:
    bool checkFormat(WAVHeader header);

public:
    WAVReader(string filename) : FileReader(filename) {}
    WAVHeader readHeader();
    uint16_t getNextSample();
};
