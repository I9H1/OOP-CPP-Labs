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

TEST(FileReaderTests, test_3) {
    string filename = "../../Tests/TestFile2.txt";
    FileReader fileReader(filename);
    fileReader.open();
    EXPECT_EQ(15, fileReader.getSize());
    fileReader.close();
}

TEST(FileReaderTests, test_4) {
    string filename = "../../Tests/TestFile2.txt";
    FileReader fileReader(filename);
    fileReader.open();
    EXPECT_EQ("Test", fileReader.getName());
    fileReader.close();
}

TEST(FileReaderTests, test_5) {
    string filename = "../../Tests/TestFile2.txt";
    FileReader fileReader(filename);
    fileReader.open();
    EXPECT_EQ(4, fileReader.getBirthRule()[0]);
    EXPECT_EQ(3, fileReader.getBirthRule()[1]);
    fileReader.close();
}

TEST(FileReaderTests, test_6) {
    string filename = "../../Tests/TestFile2.txt";
    FileReader fileReader(filename);
    fileReader.open();
    EXPECT_EQ(1, fileReader.getSurvivalRule()[0]);
    EXPECT_EQ(5, fileReader.getSurvivalRule()[1]);
    fileReader.close();
}

TEST(FileReaderTests, test_7) {
    string filename = "../../Tests/TestFile2.txt";
    FileReader fileReader(filename);
    fileReader.open();
    vector<pair<int, int>> coords = fileReader.getCoords();
    EXPECT_EQ(3, coords[0].first);
    EXPECT_EQ(4, coords[0].second);
    EXPECT_EQ(4, coords[1].first);
    EXPECT_EQ(5, coords[1].second);
    fileReader.close();
}

TEST(FileReaderTests, test_8) {
    string filename = "../../Tests/TestFile2.txt";
    FileReader fileReader(filename);
    fileReader.open();
    EXPECT_EQ(true, fileReader.checkFormat());
    fileReader.close();
}
