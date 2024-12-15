#include "gtest/gtest.h"
#include "CSVParser.h"
#include "TuplePrinter.h"

TEST(ParserTests, test_1) {
    std::ostringstream stream;
    std::ifstream file("../../Tests/testfile_1.csv", std::ios::binary);
    CSVParser<int, std::string, double> parser(file, 0);
    for (std::tuple<int, std::string, double> rs: parser) {
         stream << rs << std::endl;
    }
    EXPECT_EQ("(1, text1, 55.11)\n(2, text2, 55.12)\n(3, text3, 55.13)\n", stream.str());
}

TEST(ParserTests, test_2) {
    std::ostringstream stream;
    std::ifstream file("../../Tests/testfile_1.csv", std::ios::binary);
    CSVParser<int, std::string, double> parser(file, 2);
    for (std::tuple<int, std::string, double> rs: parser) {
         stream << rs << std::endl;
    }
    EXPECT_EQ("(3, text3, 55.13)\n", stream.str());
}

TEST(ParserTests, test_3) {
    std::ostringstream stream;
    std::ifstream file("../../Tests/testfile_2.csv", std::ios::binary);
    CSVParser<std::string, std::string, std::string> parser(file, 0, '-');
    for (std::tuple<std::string, std::string, std::string> rs: parser) {
         stream << rs << std::endl;
    }
    EXPECT_EQ("(1, 2, 3)\n(1, 2-3, 4)\n(1, |2, 3|)\n", stream.str());
}

TEST(ParserTests, test_4) {
    std::ostringstream stream;
    std::ifstream file("../../Tests/testfile_2.csv", std::ios::binary);
    CSVParser<std::string, std::string, std::string> parser(file, 0, '-', '|');
    for (std::tuple<std::string, std::string, std::string> rs: parser) {
         stream << rs << std::endl;
    }
    EXPECT_EQ("(1, 2, 3)\n(1, \"2, 3\")\n(1, 2-3, 4)\n", stream.str());
}

TEST(ParserTests, test_5) {
    std::ostringstream stream;
    std::ifstream file("../../Tests/testfile_2.csv", std::ios::binary);
    CSVParser<std::string, std::string, std::string> parser(file, 0, ';');
    const char* error_text = "";
    try {
         for (std::tuple<std::string, std::string, std::string> rs: parser) {
             stream << rs << std::endl;
         }
    } catch (std::exception& error) {
         error_text = error.what();
    }
    EXPECT_EQ("Error in line 1: Empty field!", static_cast<std::string>(error_text));
}

TEST(ParserTests, test_6) {
    std::ostringstream stream;
    std::ifstream file("../../Tests/testfile_2.csv", std::ios::binary);
    CSVParser<std::string, int, std::string> parser(file, 0, '-');
    const char* error_text = "";
    try {
         for (std::tuple<std::string, int, std::string> rs: parser) {
             stream << rs << std::endl;
         }
    } catch (std::exception& error) {
         error_text = error.what();
    }
    EXPECT_EQ("Error in line 3: Cannot convert to asked type!", static_cast<std::string>(error_text));
}
