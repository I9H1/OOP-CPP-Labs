#include "Universe.h"
#include "gtest/gtest.h"

TEST(UniverseTests, test_1) {
    UniverseConfig config;
    config.size = 4;
    config.birth_rule = {3};
    config.survival_rule = {2, 3};
    config.name = "Test 1";
    config.field = {{0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 1, 0, 0},
                    {0, 0, 0, 0}};
    Universe universe(config);
    EXPECT_EQ(3, universe.countNeighbors(2, 2));
    EXPECT_EQ(2, universe.countNeighbors(1, 1));
}

TEST(UniverseTests, test_2) {
    UniverseConfig config;
    config.size = 4;
    config.birth_rule = {3};
    config.survival_rule = {2, 3};
    config.name = "Test 1";
    config.field = {{1, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 1}};
    Universe universe(config);
    EXPECT_EQ(2, universe.countNeighbors(0, 3));
}
