#include <iostream>
#include <string>
#include <filesystem>
#include "ConfigParser.h"
#include "CMDParser.h"
#include "Exceptions.h"
#include "Converters/ConverterFactory.h"
#include "WAVReader.h"
#include "WAVWriter.h"

using namespace std;

Exceptions getErrorCode(string error);

int main(int argc, char** argv) {

    const string buffer = "../buffer.wav";

    try {
        //Initializing objects and parsing
        CMDParser cmd_parser;
        InitParameters parameters = cmd_parser.parse(argc, argv);
        ConfigParser configParser(parameters.config_filename);
        vector<Command> commands = configParser.parse();
        ConverterFactory factory;

        //Converters loop
        string current_file = parameters.input_filenames[0];
        string next_file = buffer;
        for (int i = 0; i < commands.size(); ++i) {
            cout << current_file << next_file << endl;

            Converter *converter = factory.create(commands[i].name);
            if (!converter) {
                cerr << "Invalid command in " << parameters.config_filename
                     << " - " << commands[i].name;
                return INVALID_COMMAND_ERROR;
            }
            converter->setConfig(commands[i].args);

            WAVReader wavReader(current_file);
            WAVWriter wavWriter(next_file);

            converter->convertSound(wavReader, wavWriter);

            if (next_file == buffer) {
                current_file = buffer;
                next_file = parameters.output_filename;
            } else {
                current_file = parameters.output_filename;
                next_file = buffer;
            }
        }

        // Copying result to output file
        if (next_file == buffer) {
            WAVReader result_reader(next_file);
            WAVWriter result_writer(parameters.output_filename);
            result_reader.open(ios_base::binary);
            result_writer.open(ios_base::binary);
            while (result_reader.hasNext()) {
                result_writer.writeString(result_reader.getNext());
            }
            result_reader.close();
            result_writer.close();
        }
        
    } catch (const char* error) {
        cout << error;
        Exceptions exit_code = getErrorCode(static_cast<string>(error));
        return exit_code;
    }
    return NO_ERRORS;
}

Exceptions getErrorCode(string error) {
    if (error == "Cannot open configuration file!") {
        return INVALID_CONFIG_NAME_ERROR;
    } else if (error == "Invalid execution parameters!") {
        return EXECUTION_PARAMETERS_ERROR;
    } else if (error == "Unsupported audio format!") {
        return INVALID_WAV_ERROR;
    }
    return UNKNOWN_ERROR;
}
