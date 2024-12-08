#include "WAVWriter.h"

void WAVWriter::writeHeader(WAVHeader header) {
    file_ptr.write(reinterpret_cast<char*>(&header), sizeof(header));
}

void WAVWriter::writeSample(uint16_t sample) {
    file_ptr.write(reinterpret_cast<char*>(&sample), sizeof(sample));
}
