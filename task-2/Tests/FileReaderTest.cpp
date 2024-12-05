#include "gtest/gtest.h"
#include "FileReader.h"

TEST(FileReaderTests, test_1) {
    string filename = "";
    FileReader fileReader(filename);
    bool got_error = false;
    try {
        fileReader.open();
    } catch (const char* error) {
        got_error = true;
    }
    EXPECT_EQ(true, got_error);
    fileReader.close();
}

TEST(FileReaderTests, test_2) {
    string filename = "../../Tests/TestFile.txt";
    FileReader fileReader(filename);
    bool got_error = false;
    try {
        fileReader.open();
    } catch (const char* error) {
        got_error = true;
    }
    EXPECT_EQ(false, got_error);
    fileReader.close();
}
