#include "Statistics.h"
#include <bits/stdc++.h>

using namespace std;

Statistics::Statistics() {
    words_amount = 0;
}

void Statistics::handle(string word) {
    if (data.count(word) > 0) {
        ++data[word][0];
    } else {
        data[word] = {1, 0};
    }
    ++words_amount;
}

void Statistics::calculatePercentage() {
    for (auto i = data.begin(); i != data.end(); ++i) {
        i->second[1] = i->second[0] / words_amount * 100;
    }
}

vector<Word> Statistics::sortData() {
    vector<Word> data_vector;
    for (auto i = data.begin(); i != data.end(); ++i) {
        Word new_line;
        new_line.word = i->first;
        new_line.amount = i->second[0];
        new_line.percent = i->second[1];
        data_vector.push_back(new_line);
    }
    sort(data_vector.begin(), data_vector.end(),
         [](Word &a, Word &b) {return a.amount > b.amount;});
    return data_vector;
}

vector<Word> Statistics::getData() {
    calculatePercentage();
    return sortData();
}