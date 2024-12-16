#include "CMDParser.h"
#include "ConfigParser.h"
#include "Converters/ConverterFactory.h"
#include "Exceptions.h"
#include "WAVReader.h"
#include "WAVWriter.h"
#include <iostream>
#include <string>

using namespace std;

Exceptions getErrorCode(string error);

int main(int argc, char **argv) {

    const string buffer = "../WAV_program_files/buffer.wav";

    try {
        //Initializing objects and parsing
        CMDParser cmd_parser;
        InitParameters parameters = cmd_parser.parse(argc, argv);
        ConfigParser configParser(parameters.config_filename, parameters.input_filenames);
        vector<Command> commands = configParser.parse();
        ConverterFactory factory;
        //Printing description
        if (parameters.description_required) {
            cmd_parser.printHelp();
            factory.printDescription();
        }
        //Converters loop
        string current_file = parameters.input_filenames[0];
        string next_file = buffer;
        for (int i = 0; i < commands.size(); ++i) {
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
        if (current_file == buffer or commands.empty()) {
            WAVReader result_reader(current_file);
            WAVWriter result_writer(parameters.output_filename);
            result_reader.open(ios_base::binary);
            result_writer.open(ios_base::binary);
            while (result_reader.hasNext()) {
                result_writer.writeString(result_reader.getNext());
            }
            result_reader.close();
            result_writer.close();
        }

    } catch (const char *error) {
        cerr << error;
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
    } else if (error.find("Invalid arguments") == 0) {
        return INVALID_COMMAND_ARGS_ERROR;
    } else if (error.find("Cannot open file") == 0) {
        return INVALID_FILENAME_ERROR;
    }
    return UNKNOWN_ERROR;
}
