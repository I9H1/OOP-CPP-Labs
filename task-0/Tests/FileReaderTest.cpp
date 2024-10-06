#include "gtest/gtest.h"
#include "FileReader.h"

TEST(BasicTests, test_1) {
    FileReader fileReader("../../Tests/testfile1.txt");
    EXPECT_EQ(true, fileReader.open());
    fileReader.close();
}

TEST(BasicTests, test_2) {
    FileReader fileReader("");
    EXPECT_EQ(false, fileReader.open());
}

TEST(BasicTests, test_3) {
    FileReader fileReader("../../Tests/testfile1.txt");
    fileReader.open();
    fileReader.get_next();
    EXPECT_EQ(false, fileReader.has_next());
    fileReader.close();
}

TEST(BasicTests, test_4) {
    FileReader fileReader("../../Tests/testfile1.txt");
    fileReader.open();
    EXPECT_EQ(true, fileReader.has_next());
    fileReader.close();
}

TEST(BasicTests, test_5) {
    FileReader fileReader("../../Tests/testfile1.txt");
    fileReader.open();
    EXPECT_EQ("test string", fileReader.get_next());
    fileReader.close();
}
