#include "Statistics.h"
#include <bits/stdc++.h>

using namespace std;

Statistics::Statistics() {
    words_amount = 0;
}

void Statistics::handle_new_word(string word) {
    if (data.count(word) > 0) {
        ++data[word][0];
    } else {
        data[word] = {1, 0};
    }
    ++words_amount;
}

void Statistics::calculate_percentage() {
    for (auto i = data.begin(); i != data.end(); ++i) {
        i->second[1] = i->second[0] / words_amount * 100;
    }
}

void Statistics::sort_data() {
    vector<pair<vector<float>, string>> data_vector;
    for (auto i = data.begin(); i != data.end(); ++i) {
        pair<vector<float>, string> new_pair;
        new_pair.first = i->second;
        new_pair.second = i->first;
        data_vector.push_back(new_pair);
    }
    sort(data_vector.begin(), data_vector.end());
    reverse(data_vector.begin(), data_vector.end());
    sorted_data = data_vector;
}

vector<string> Statistics::get_data_in_strings() {
    sort_data();
    vector<string> data_in_strings;
    for (auto i = sorted_data.begin(); i != sorted_data.end(); ++i) {
        string new_string = i->second + ";" + to_string(int(i->first[0])) + ";"
                            + to_string((int)i->first[1]) + "."
                            + to_string((int)((i->first[1] - (int)i->first[1]) * 100)) + "%";
        data_in_strings.push_back(new_string);
    }
    return data_in_strings;
}