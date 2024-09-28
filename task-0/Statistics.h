#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

class Statistics {
    private:
        int words_amount;
        map<string, vector<float>> data;
        vector<pair<vector<float>, string>> sorted_data;
    public:
        Statistics();
        void handle_new_word(string word);
        void calculate_percentage();
        void sort_data();
        vector<string> get_data_in_strings();
};
