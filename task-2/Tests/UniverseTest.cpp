#include "Universe.h"
#include "gtest/gtest.h"

TEST(UniverseTests, test_1) {
    int size = 4;
    vector<int> birth = {3};
    vector<int> survival = {2, 3};
    string name = "Test 1";
    vector<pair<int, int>> coords = {{1, 1}, {1, 2}, {2, 1}};
    Universe universe(size, name, birth, survival, coords);
    universe.setAlive(1, 2);
    EXPECT_EQ(true, universe.isAlive(1, 2));
}

TEST(UniverseTests, test_2) {
    int size = 4;
    vector<int> birth = {3};
    vector<int> survival = {2, 3};
    string name = "Test 1";
    vector<pair<int, int>> coords = {{1, 1}, {1, 2}, {2, 1}};
    Universe universe(size, name, birth, survival, coords);
    universe.setDead(1, 1);
    EXPECT_EQ(false, universe.isAlive(1, 1));
}

TEST(UniverseTests, test_3) {
    int size = 4;
    vector<int> birth = {3};
    vector<int> survival = {2, 3};
    string name = "Test 1";
    vector<pair<int, int>> coords = {{1, 1}, {1, 2}, {2, 1}};
    Universe universe(size, name, birth, survival, coords);
    EXPECT_EQ(3, universe.countNeighbors(2, 2));
    EXPECT_EQ(2, universe.countNeighbors(1, 1));
}

TEST(UniverseTests, test_4) {
    int size = 4;
    vector<int> birth = {3};
    vector<int> survival = {2, 3};
    string name = "Test 1";
    vector<pair<int, int>> coords = {{0, 0}, {3, 3}};
    Universe universe(size, name, birth, survival, coords);
    EXPECT_EQ(2, universe.countNeighbors(0, 3));
}
