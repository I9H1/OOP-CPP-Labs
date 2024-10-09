#include "gtest/gtest.h"
#include "Tokenizer.h"

TEST(BasicTests, test_8) {
    Tokenizer tokenizer;
    string teststring = "a, b;cd[e]";
    list<string> tokens = tokenizer.getTokens(teststring);
    EXPECT_EQ("e", tokens.back());
    tokens.pop_back();
    EXPECT_EQ("cd", tokens.back());
    tokens.pop_back();
    EXPECT_EQ("b", tokens.back());
    tokens.pop_back();
    EXPECT_EQ("a", tokens.back());
    tokens.pop_back();
}

TEST(BasicTests, test_9) {
    Tokenizer tokenizer;
    string teststring = "";
    list<string> tokens = tokenizer.getTokens(teststring);
    EXPECT_EQ(true, tokens.empty());
}