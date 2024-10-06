#include "gtest/gtest.h"
#include "Statistics.h"

TEST(BasicTests, test_10) {
    Statistics statistics;
    statistics.handle_new_word("a");
    vector<string> data = statistics.get_data_in_strings();
    EXPECT_EQ("a;1;0.0%", data[0]);
}

TEST(BasicTests, test_11) {
    Statistics statistics;
    statistics.handle_new_word("b");
    statistics.handle_new_word("a");
    statistics.handle_new_word("a");
    statistics.handle_new_word("a");
    statistics.calculate_percentage();
    vector<string> data = statistics.get_data_in_strings();
    vector<string> check_data = {"a;3;75.0%", "b;1;25.0%"};
    EXPECT_EQ(check_data, data);
}
