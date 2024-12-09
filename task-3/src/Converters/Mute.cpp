#include "Mute.h"
#include <iostream>

void Mute::convertSound(WAVReader &file_in, WAVWriter &file_out) {

}

string Mute::getDescription() {
    string description = "mute <from> <to> - mutes given period of time in WAV-file.\n"
                  "<from>, <to> must be integers representing seconds from the beginning";
    return description;
}

void Mute::setConfig(vector<std::string> args) {
    
}
