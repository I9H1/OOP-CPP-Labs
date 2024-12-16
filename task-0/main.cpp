#include <iostream>
#include "FileReader.h"
#include "Tokenizer.h"
#include "Statistics.h"
#include "FileWriter.h"

using namespace std;

vector<string> dataToStrings(vector<Word>);

int main(int argc, char* argv[]) {
    const string input_filename = argv[1];
    const string output_filename = argv[2];
    FileReader in_file(input_filename);
    Tokenizer tokenizer;
    Statistics statistics;
    FileWriter out_file(output_filename);
    if (!in_file.open() || !out_file.open()) {
        cout << "can not open files";
        return 0;
    }
    while(in_file.hasNext()) {
        list<string> tokens = tokenizer.getTokens(in_file.getNext());
        while (!tokens.empty()) {
          statistics.handle(tokens.back());
          tokens.pop_back();
        }
    }
    out_file.write(dataToStrings(statistics.getData()));
    in_file.close();
    out_file.close();
    return 0;
}

vector<string> dataToStrings(vector<Word> data) {
    vector<string> csv_data;
    for (auto i : data) {
        string new_string =
            i.word + ";" + to_string(i.amount) + ";" + to_string((int)i.percent)
            + "." + to_string((int)((i.percent - (int)i.percent) * 100)) + "%";
        csv_data.push_back(new_string);
    }
    return csv_data;
}
