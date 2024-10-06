#include "gtest/gtest.h"
#include "Tokenizer.h"

TEST(BasicTests, test_8) {
    Tokenizer tokenizer;
    string teststring = "a, b;cd[e]";
    tokenizer.get_tokens(teststring);
    EXPECT_EQ("e", tokenizer.get_last_token());
    tokenizer.remove_last_token();
    EXPECT_EQ("cd", tokenizer.get_last_token());
    tokenizer.remove_last_token();
    EXPECT_EQ("b", tokenizer.get_last_token());
    tokenizer.remove_last_token();
    EXPECT_EQ("a", tokenizer.get_last_token());
    tokenizer.remove_last_token();
}

TEST(BasicTests, test_9) {
    Tokenizer tokenizer;
    string teststring1 = "";
    tokenizer.get_tokens(teststring1);
    EXPECT_EQ(true, tokenizer.is_list_empty());
    string teststring2 = "a";
    tokenizer.get_tokens(teststring2);
    EXPECT_EQ(false, tokenizer.is_list_empty());
}