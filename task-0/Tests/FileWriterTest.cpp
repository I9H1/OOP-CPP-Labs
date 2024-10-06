#include "gtest/gtest.h"
#include "FileWriter.h"

TEST(BasicTests, test_6) {
    FileWriter fileWriter("../../Tests/testfile2.txt");
    EXPECT_EQ(true, fileWriter.open());
}

TEST(BasicTests_test, test_7) {
    FileWriter fileWriter("../../Tests/testfile2.txt");
    fileWriter.open();
    vector<string> data = {"string1", "string2"};
    fileWriter.write_data(data);
    fileWriter.close();
    ifstream file;
    file.open("../../Tests/testfile2.txt");
    string line;
    getline(file, line);
    EXPECT_EQ("string1", line);
    file.close();
}
