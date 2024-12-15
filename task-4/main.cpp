#include "CSVParser.h"
#include "TuplePrinter.h"
#include <fstream>
#include <iostream>
#include <tuple>

int main() {
    std::ifstream file("../example.csv", std::ios::binary);
    CSVParser<int, std::string, double> parser(file, 0);
    try {
        for (std::tuple<int, std::string, double> rs: parser) {
            std::cout << rs << std::endl;
        }
    } catch (const char *error) {
        std::cerr << error << std::endl;
    }
    return 0;
}
