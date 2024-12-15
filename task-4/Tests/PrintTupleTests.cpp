#include "gtest/gtest.h"
#include "TuplePrinter.h"
#include <tuple>
#include <sstream>
#include <iostream>

TEST(PrintTests, test_1) {
    std::ostringstream stream;
    std::tuple<int, double> tuple = {1, 10.01};
    stream << tuple;
    EXPECT_EQ("(1, 10.01)", stream.str());
}

TEST(PrintTests, test_2) {
    std::ostringstream stream;
    std::tuple<bool, std::string> tuple = {false, "text"};
    stream << tuple;
    EXPECT_EQ("(0, text)", stream.str());
}
