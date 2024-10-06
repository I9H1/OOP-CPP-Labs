#pragma once
#include "FileReader.h"
#include "Tokenizer.h"
#include "Statistics.h"
#include "FileWriter.h"

using namespace std;

class Controller {
    private:
        FileReader in_file;
        Tokenizer tokenizer;
        Statistics statistics;
        FileWriter out_file;
    public:
        Controller(string in_filename, string out_filename);
        bool open_files();
        void handle_new_words();
        bool are_words_over();
        vector<string> get_data();
        void write_data(vector<string> data_in_strings);
        void close_files();
};
