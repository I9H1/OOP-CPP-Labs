#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Word {
    string word;
    int amount;
    float percent;
};

class Statistics {
    private:
        int words_amount;
        map<string, vector<float>> data;
        vector<Word> sortData();
        void calculatePercentage();
    public:
        Statistics();
        void handle(string word);
        vector<Word> getData();
};
