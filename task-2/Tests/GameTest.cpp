#include "gtest/gtest.h"
#include "Game.h"
#include "UniverseParser.h"

using namespace std;

TEST(Basic_tests, test_1) {
    UniverseConfig config;
    config.size = 4;
    config.birth_rule = {3};
    config.survival_rule = {2, 3};
    config.name = "Test 1";
    config.field = {{0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 1, 0, 0},
                    {0, 0, 0, 0}};
    Game game(config);
    game.printUniverse();
    game.tick();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    UniverseParser parser;
    UniverseConfig new_config = parser.parse("../../Tests/TestFile.txt");
    EXPECT_EQ(config.name, new_config.name);
    EXPECT_EQ(config.birth_rule, new_config.birth_rule);
    EXPECT_EQ(config.survival_rule, new_config.survival_rule);
    vector<vector<bool>> test_field = {{0, 0, 0, 0},
                                       {0, 1, 1, 0},
                                       {0, 1, 1, 0},
                                       {0, 0, 0, 0}};
    EXPECT_EQ(test_field, new_config.field);
}

TEST(Basic_tests, test_2) {
    UniverseConfig config;
    config.size = 4;
    config.birth_rule = {3};
    config.survival_rule = {2, 3};
    config.name = "Test 2";
    config.field = {{1, 0, 0, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 1}};
    Game game(config);
    game.printUniverse();
    game.tick();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    UniverseParser parser;
    UniverseConfig new_config = parser.parse("../../Tests/TestFile.txt");
    vector<vector<bool>> test_field = {{1, 0, 0, 1},
                                       {0, 0, 0, 0},
                                       {0, 0, 0, 0},
                                       {1, 0, 0, 1}};
    EXPECT_EQ(test_field, new_config.field);
}

TEST(Basic_tests, test_3) {
    UniverseConfig config;
    config.size = 4;
    config.birth_rule = {3};
    config.survival_rule = {};
    config.name = "Test 3";
    config.field = {{1, 0, 0, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 1}};
    Game game(config);
    game.printUniverse();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    UniverseParser parser;
    UniverseConfig new_config = parser.parse("../../Tests/TestFile.txt");
    vector<vector<bool>> test_field = {{0, 0, 0, 0},
                                       {0, 0, 0, 0},
                                       {0, 0, 0, 0},
                                       {1, 0, 0, 0}};
    EXPECT_EQ(test_field, new_config.field);
}

TEST(Basic_tests, test_4) {
    UniverseConfig config;
    config.size = 4;
    config.birth_rule = {};
    config.survival_rule = {2, 3};
    config.name = "Test 4";
    config.field = {{1, 0, 0, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 1}};
    Game game(config);
    game.printUniverse();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    UniverseParser parser;
    UniverseConfig new_config = parser.parse("../../Tests/TestFile.txt");
    vector<vector<bool>> test_field = {{1, 0, 0, 1},
                                       {0, 0, 0, 0},
                                       {0, 0, 0, 0},
                                       {0, 0, 0, 1}};
    EXPECT_EQ(test_field, new_config.field);
}

TEST(Basic_tests, test_5) {
    UniverseConfig config;
    config.size = 4;
    config.birth_rule = {3};
    config.survival_rule = {2, 3};
    config.name = "Test 5";
    config.field = {{0, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 1}};
    Game game(config);
    game.printUniverse();
    game.tick();
    game.printUniverse();
    cout << endl;
    game.dump("../../Tests/TestFile.txt");
    UniverseParser parser;
    UniverseConfig new_config = parser.parse("../../Tests/TestFile.txt");
    vector<vector<bool>> test_field = {{0, 0, 0, 0},
                                       {0, 0, 0, 0},
                                       {0, 0, 0, 0},
                                       {0, 0, 0, 0}};
    EXPECT_EQ(test_field, new_config.field);
}