#include "Slow.h"

void Slow::convertSound(WAVReader &file_in, WAVWriter &file_out) {
    file_in.open(ios_base::binary);
    file_out.open(ios_base::binary);
    WAVHeader header = file_in.readHeader();
    int sample_amount = file_in.getSampleAmount();
    header.subchunk2_size += (to_time - from_time) * header.sample_rate * 2;
    file_out.writeHeader(header);
    for (int i = 0; i < sample_amount; ++i) {
        int16_t sample = file_in.getNextSample();
        if (i >= from_time * header.sample_rate and i <= to_time * header.sample_rate) {
            file_out.writeSample(sample);
        }
        file_out.writeSample(sample);
    }
    file_in.close();
    file_out.close();
}


bool Slow::isNumber(std::string str) {
    for (int i = 0; i < str.size(); ++i) {
        if (!isdigit(str[0])) {
            return false;
        }
    }
    return true;
}

string Slow::getDescription() {
    string description = "slow <from> <to> - slows down given period of time in WAV-file twice.\n"
                         "<from>, <to> must be integers representing seconds from the beginning.\n\n";
    return description;
}

void Slow::setConfig(vector<std::string> args) {
    if (args.size() != 2) {
        throw "Invalid arguments for command <slow>!";
    } else if (!isNumber(args[0]) or !isNumber(args[1])) {
        throw "Invalid arguments for command <slow>!";
    }
    from_time = stoi(args[0]);
    to_time = stoi(args[1]);
}
