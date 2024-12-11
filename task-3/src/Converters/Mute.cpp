#include "Mute.h"

using namespace std;

void Mute::convertSound(WAVReader &file_in, WAVWriter &file_out) {
    file_in.open(ios_base::binary);
    file_out.open(ios_base::binary);
    WAVHeader header = file_in.readHeader();
    file_out.writeHeader(header);
    int sample_amount = file_in.getSampleAmount();
    for (int i = 0; i < sample_amount; ++i) {
        int16_t sample = file_in.getNextSample();
        if (i >= from_time * header.sample_rate and i <= to_time * header.sample_rate) {
            sample = 0;
        }
        file_out.writeSample(sample);
    }
    file_in.close();
    file_out.close();
}

bool Mute::isNumber(std::string str) {
    for (int i = 0; i < str.size(); ++i) {
        if (!isdigit(str[0])) {
            return false;
        }
    }
    return true;
}

string Mute::getDescription() {
    string description = "mute <from> <to> - mutes given period of time in WAV-file.\n"
                  "<from>, <to> must be integers representing seconds from the beginning.\n\n";
    return description;
}

void Mute::setConfig(vector<std::string> args) {
    if (args.size() != 2) {
        throw "Invalid arguments for command <mute>!";
    } else if (!isNumber(args[0]) or !isNumber(args[1])) {
        throw "Invalid arguments for command <mute>!";
    }
    from_time = stoi(args[0]);
    to_time = stoi(args[1]);
}
