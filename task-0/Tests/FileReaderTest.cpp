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
    fileReader.getNext();
    EXPECT_EQ(false, fileReader.hasNext());
    fileReader.close();
}

TEST(BasicTests, test_4) {
    FileReader fileReader("../../Tests/testfile1.txt");
    fileReader.open();
    EXPECT_EQ(true, fileReader.hasNext());
    fileReader.close();
}

TEST(BasicTests, test_5) {
    FileReader fileReader("../../Tests/testfile1.txt");
    fileReader.open();
    EXPECT_EQ("test string", fileReader.getNext());
    fileReader.close();
}
