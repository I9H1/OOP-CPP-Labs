#include <iostream>
#include <tuple>
#include "PrintTuple.h"
#include "CSVParser.h"

using namespace std;

int main() {
    ifstream file("../example.csv");
    CSVParser<int, string> parser(file, 0 /*skip first lines count*/);
    for (tuple<int, string> rs : parser) {
        cout<< rs << endl;
    }
    return 0;
}
