#include "gtest/gtest.h"
#include "Game.h"
#include "FileReader.h"

using namespace std;

TEST(Basic_tests, test_1) {
    int size = 4;
    vector<int> birth = {3};
    vector<int> survival = {2, 3};
    string name = "Test 1";
    vector<pair<int, int>> coords = {{1, 1}, {1, 2}, {2, 1}};
    Game game(size, name, birth, survival, coords);
    game.printUniverse();
    game.tick();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    FileReader fileReader("../../Tests/TestFile.txt");
    fileReader.open();
    EXPECT_EQ(name, fileReader.getName());
    EXPECT_EQ(birth, fileReader.getBirthRule());
    EXPECT_EQ(survival, fileReader.getSurvivalRule());
    vector<pair<int, int>> test_coords = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    EXPECT_EQ(test_coords, fileReader.getCoords());
}

TEST(Basic_tests, test_2) {
    int size = 4;
    vector<int> birth = {3};
    vector<int> survival = {2, 3};
    string name = "Test 2";
    vector<pair<int, int>> coords = {{0, 0}, {3, 3}, {0, 3}};
    Game game(size, name, birth, survival, coords);
    game.printUniverse();
    game.tick();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    FileReader fileReader("../../Tests/TestFile.txt");
    fileReader.open();
    vector<pair<int, int>> test_coords = {{0, 0}, {0, 3}, {3, 0}, {3, 3}};
    EXPECT_EQ(test_coords, fileReader.getCoords());
}

TEST(Basic_tests, test_3) {
    int size = 4;
    vector<int> birth = {3};
    vector<int> survival = {};
    string name = "Test 3";
    vector<pair<int, int>> coords = {{0, 0}, {3, 3}, {0, 3}};
    Game game(size, name, birth, survival, coords);
    game.printUniverse();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    FileReader fileReader("../../Tests/TestFile.txt");
    fileReader.open();
    vector<pair<int, int>> test_coords = {{3, 0}};
    EXPECT_EQ(test_coords, fileReader.getCoords());
}

TEST(Basic_tests, test_4) {
    int size = 4;
    vector<int> birth = {};
    vector<int> survival = {2, 3};
    string name = "Test 4";
    vector<pair<int, int>> coords = {{0, 0}, {0, 3}, {3, 3}};
    Game game(size, name, birth, survival, coords);
    game.printUniverse();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    FileReader fileReader("../../Tests/TestFile.txt");
    fileReader.open();
    EXPECT_EQ(coords, fileReader.getCoords());
}

TEST(Basic_tests, test_5) {
    int size = 4;
    vector<int> birth = {3};
    vector<int> survival = {2, 3};
    string name = "Test 5";
    vector<pair<int, int>> coords = {{1, 1}, {3, 3}};
    Game game(size, name, birth, survival, coords);
    game.printUniverse();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    FileReader fileReader("../../Tests/TestFile.txt");
    fileReader.open();
    vector<pair<int, int>> test_coords = {};
    EXPECT_EQ(test_coords, fileReader.getCoords());
}