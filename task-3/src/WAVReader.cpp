#include "WAVReader.h"

WAVHeader WAVReader::readHeader() {
    WAVHeader header;
    file_ptr.read(reinterpret_cast<char*>(&header), sizeof(header));
    if (!checkFormat(header)) {
        throw "Unsupported audio format!";
    }
    this->header = header;
    return header;
}

bool WAVReader::checkFormat(WAVHeader header) {
    bool check1 = (header.format == SUPPORTED_FORMAT);
    bool check2 = (header.num_channels == SUPPORTED_CHANNELS);
    bool check3 = (header.bits_per_sample == SUPPORTED_SAMPLE_SIZE);
    bool check4 = (header.sample_rate == SUPPORTED_SAMPLE_RATE);
    if (check1 and check2 and check3 and check4) {
        return true;
    }
    return false;
}

uint16_t WAVReader::getNextSample() {
    uint16_t sample;
    file_ptr.read(reinterpret_cast<char*>(&sample), sizeof(sample));
    if (!hasNext()) {
        throw "Cannot get sample!";
    }
    return sample;
}

int WAVReader::getSampleAmount() {
    return header.subchunk2_size / (header.bits_per_sample / BYTE_SIZE);
}
