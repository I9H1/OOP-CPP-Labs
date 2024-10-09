#include "gtest/gtest.h"
#include "Statistics.h"

TEST(BasicTests, test_10) {
    Statistics statistics;
    statistics.handle("a");
    vector<Word> data = statistics.getData();
    EXPECT_EQ("a", data[0].word);
    EXPECT_EQ(1, data[0].amount);
    EXPECT_EQ(100, data[0].percent);
}

TEST(BasicTests, test_11) {
    Statistics statistics;
    statistics.handle("b");
    statistics.handle("a");
    statistics.handle("a");
    statistics.handle("a");
    vector<Word> data = statistics.getData();
    EXPECT_EQ("a", data[0].word);
    EXPECT_EQ(3, data[0].amount);
    EXPECT_EQ(75.0, data[0].percent);
    EXPECT_EQ("b", data[1].word);
    EXPECT_EQ(1, data[1].amount);
    EXPECT_EQ(25.0, data[1].percent);
}
