#include "Mix.h"

void Mix::convertSound(WAVReader &file_in, WAVWriter &file_out) {
    WAVReader mixing_file(mixing_file_name);
    file_in.open(ios_base::binary);
    file_out.open(ios_base::binary);
    mixing_file.open(ios_base::binary);
    WAVHeader src_header = file_in.readHeader();
    file_out.writeHeader(src_header);
    WAVHeader mix_header = mixing_file.readHeader();
    int sample_amount = file_in.getSampleAmount();
    int mix_sample_amount = mixing_file.getSampleAmount();
    int sample_counter = 0;
    for (int i = 0; i < sample_amount; ++i) {
        int16_t sample = file_in.getNextSample();
        if (i >= from_time * src_header.sample_rate and sample_counter < mix_sample_amount) {
            int16_t second_sample = mixing_file.getNextSample();
            int16_t new_sample = static_cast<int16_t>(sample / 2 + second_sample / 2);
            file_out.writeSample(new_sample);
            ++sample_counter;
        } else {
            file_out.writeSample(sample);
        }
    }
    file_in.close();
    file_out.close();
    mixing_file.close();
}

bool Mix::isNumber(std::string str) {
    for (int i = 0; i < str.size(); ++i) {
        if (!isdigit(str[0])) {
            return false;
        }
    }
    return true;
}

string Mix::getDescription() {
    string description = "mix $<file_number> <from> - mixes source file with\n"
                         "given file from <from> second to the end.\n\n";
    return description;
}

void Mix::setConfig(vector<std::string> args) {
    mixing_file_name = args[0];
    if (args.size() != 2) {
        throw "Invalid arguments for command <mix>!";
    } else if (!isNumber(args[1])) {
        throw "Invalid arguments for command <mix>!";
    }
    from_time = stoi(args[1]);
}
