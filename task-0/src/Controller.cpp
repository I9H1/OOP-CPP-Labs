#include "Controller.h"

using namespace std;

Controller::Controller(string in_filename, string out_filename)
    : in_file(in_filename), out_file(out_filename) {}

bool Controller::open_files() {
    return in_file.open() and out_file.open();
}

void Controller::handle_new_words() {
    tokenizer.get_tokens(in_file.get_next());
    while (!tokenizer.is_list_empty()) {
        statistics.handle_new_word(tokenizer.get_last_token());
        tokenizer.remove_last_token();
    }
}

void Controller::close_files() {
    in_file.close();
    out_file.close();
}

bool Controller::are_words_over() {
    return !in_file.has_next();
}

vector<string> Controller::get_data() {
    statistics.calculate_percentage();
    return statistics.get_data_in_strings();
}

void Controller::write_data(vector<string> data_in_strings) {
    out_file.write_data(data_in_strings);
}
