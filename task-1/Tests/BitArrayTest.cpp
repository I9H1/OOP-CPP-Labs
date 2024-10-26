#include "gtest/gtest.h"
#include "BitArray.h"

TEST(getSizeTest, test_1) {
    BitArray array(12);
    EXPECT_EQ(12, array.getSize());
}

TEST(toStringTest, test_2) {
    BitArray array(3, true);
    EXPECT_EQ("111", array.toString());
}

TEST(swapTest, test_3) {
    BitArray array_1(3, true);
    BitArray array_2(3, false);
    array_1.swap(array_2);
    EXPECT_EQ("111", array_2.toString());
    EXPECT_EQ("000", array_1.toString());
}

TEST(clearTest, test_4) {
    BitArray array(3, true);
    array.clear();
    EXPECT_EQ("", array.toString());
}

TEST(resizeTest, test_5) {
    BitArray array(3, true);
    array.resize(9, false);
    EXPECT_EQ("111000000", array.toString());
}

TEST(resizeTest, test_6) {
    BitArray array(3, true);
    string check;
    try {
        array.resize(-1, false);
    } catch (const char* message) {
        check = message;
    }
    EXPECT_EQ("Invalid size", check);
}

TEST(resizeTest, test_7) {
    BitArray array(3, true);
    array.resize(1);
    EXPECT_EQ("1", array.toString());
}

TEST(pushBackTest, test_8) {
    BitArray array(3, true);
    array.pushBack(false);
    array.pushBack(true);
    EXPECT_EQ("11101", array.toString());
}

TEST(indexationTest, test_9) {
    BitArray array(3, true);
    EXPECT_EQ(true, array[1]);
}

TEST(indexationTest, test_10) {
    BitArray array(3, true);
    array[1] = false;
    EXPECT_EQ("101", array.toString());
}

TEST(indexationTest, test_11) {
    BitArray array(3, true);
    string check;
    try {
        array[-1] = false;
    } catch (const char* message) {
        check = message;
    }
    EXPECT_EQ("Wrong index", check);
}

TEST(indexationTest, test_12) {
    BitArray array(3, true);
    string check;
    try {
        array[3] = false;
    } catch (const char* message) {
        check = message;
    }
    EXPECT_EQ("Wrong index", check);
}

TEST(setTest, test_13) {
    BitArray array(3, false);
    array.set();
    EXPECT_EQ("111", array.toString());
}

TEST(resetTest, test_14) {
    BitArray array(3, true);
    array.reset();
    EXPECT_EQ("000", array.toString());
}

TEST(anyTest, test_15) {
    BitArray array(3, false);
    EXPECT_EQ(false, array.any());
}

TEST(anyTest, test_16) {
    BitArray array(3, false);
    array[1] = true;
    EXPECT_EQ(true, array.any());
}

TEST(noneTest, test_17) {
    BitArray array(3, false);
    EXPECT_EQ(true, array.none());
}

TEST(noneTest, test_18) {
    BitArray array(3, false);
    array[1] = true;
    EXPECT_EQ(false, array.none());
}

TEST(inversionTest, test_19) {
    BitArray array_1(3, false);
    array_1[1] = true;
    BitArray array_2 = ~array_1;
    EXPECT_EQ("101", array_2.toString());
}

TEST(countTest, test_20) {
    BitArray array(5, true);
    EXPECT_EQ(5, array.count());
}

TEST(isEmptyTest, test_21) {
    BitArray array(5, true);
    EXPECT_EQ(false, array.isEmpty());
    array.clear();
    EXPECT_EQ(true, array.isEmpty());
}

TEST(shiftleftTest, test_22) {
    BitArray array_1(7, false);
    array_1[0] = true;
    array_1[6] = true;
    BitArray array_2 = array_1 << 4;
    EXPECT_EQ("0010000", array_2.toString());
}

TEST(shiftleftTest, test_23) {
    BitArray array_1(7, false);
    array_1[0] = true;
    array_1[6] = true;
    BitArray array_2 = array_1 << -4;
    EXPECT_EQ("0000100", array_2.toString());
}

TEST(shiftrightTest, test_24) {
    BitArray array_1(7, false);
    array_1[0] = true;
    array_1[6] = true;
    BitArray array_2 = array_1 >> 5;
    EXPECT_EQ("0000010", array_2.toString());
}

TEST(shiftrightTest, test_25) {
    BitArray array_1(7, false);
    array_1[0] = true;
    array_1[6] = true;
    BitArray array_2 = array_1 >> -5;
    EXPECT_EQ("0100000", array_2.toString());
}

TEST(shiftlefteqTest, test_26) {
    BitArray array(7, false);
    array[0] = true;
    array[6] = true;
    array <<= 5;
    EXPECT_EQ("0100000", array.toString());
}

TEST(shiftlefteqTest, test_27) {
    BitArray array(7, false);
    array[0] = true;
    array[6] = true;
    array <<= -5;
    EXPECT_EQ("0000010", array.toString());
}

TEST(shiftrighteqTest, test_28) {
    BitArray array(7, false);
    array[0] = true;
    array[6] = true;
    array >>= 5;
    EXPECT_EQ("0000010", array.toString());
}

TEST(shiftrighteqTest, test_29) {
    BitArray array(7, false);
    array[0] = true;
    array[6] = true;
    array >>= -5;
    EXPECT_EQ("0100000", array.toString());
}

TEST(eqivTest, test_30) {
    BitArray array_1(7, false);
    BitArray array_2(array_1);
    EXPECT_EQ(true, array_1 == array_2);
    array_2[0] = true;
    EXPECT_EQ(false, array_1 == array_2);
}

TEST(noteqivTest, test_31) {
    BitArray array_1(7, false);
    BitArray array_2(array_1);
    EXPECT_EQ(false, array_1 != array_2);
    array_2[0] = true;
    EXPECT_EQ(true, array_1 != array_2);
}

TEST(andTest, test_32) {
    BitArray array_1(7, false);
    array_1[4] = true;
    BitArray array_2(7, true);
    BitArray array_3 = array_1 & array_2;
    EXPECT_EQ("0000100", array_3.toString());
}

TEST(andTest, test_33) {
    BitArray array_1(7, false);
    BitArray array_2(6, true);
    string check;
    try {
        BitArray array_3 = array_1 & array_2;
    } catch (const char* message) {
        check = message;
    }
    EXPECT_EQ("Operation & requires same size of arrays", check);
}

TEST(orTest, test_34) {
    BitArray array_1(7, false);
    array_1[4] = true;
    BitArray array_2(7, true);
    array_2[3] = false;
    BitArray array_3 = array_1 | array_2;
    EXPECT_EQ("1110111", array_3.toString());
}

TEST(orTest, test_35) {
    BitArray array_1(7, false);
    BitArray array_2(6, true);
    string check;
    try {
        BitArray array_3 = array_1 | array_2;
    } catch (const char* message) {
        check = message;
    }
    EXPECT_EQ("Operation | requires same size of arrays", check);
}

TEST(xorTest, test_36) {
    BitArray array_1(7, false);
    array_1[4] = true;
    BitArray array_2(7, true);
    BitArray array_3 = array_1 ^ array_2;
    EXPECT_EQ("1111011", array_3.toString());
}

TEST(xorTest, test_37) {
    BitArray array_1(7, false);
    BitArray array_2(6, true);
    string check;
    try {
        BitArray array_3 = array_1 ^ array_2;
    } catch (const char* message) {
        check = message;
    }
    EXPECT_EQ("Operation ^ requires same size of arrays", check);
}

TEST(andeqTEST, test_38) {
    BitArray array_1(7, false);
    BitArray array_2(7, true);
    array_1[0] = true;
    array_1 &= array_2;
    EXPECT_EQ("1000000", array_1.toString());
}

TEST(andeqTEST, test_39) {
    BitArray array_1(7, false);
    BitArray array_2(6, true);
    string check;
    try {
        array_1 &= array_2;
    } catch (const char* message) {
        check = message;
    }
    EXPECT_EQ("Operation &= requires same size of arrays", check);
}

TEST(oreqTEST, test_40) {
    BitArray array_1(7, false);
    BitArray array_2(7, true);
    array_2[0] = false;
    array_1 |= array_2;
    EXPECT_EQ("0111111", array_1.toString());
}

TEST(oreqTEST, test_41) {
    BitArray array_1(7, false);
    BitArray array_2(6, true);
    string check;
    try {
        array_1 |= array_2;
    } catch (const char* message) {
        check = message;
    }
    EXPECT_EQ("Operation |= requires same size of arrays", check);
}

TEST(xoreqTEST, test_42) {
    BitArray array_1(7, false);
    BitArray array_2(7, true);
    array_1[0] = true;
    array_1 ^= array_2;
    EXPECT_EQ("0111111", array_1.toString());
}

TEST(xoreqTEST, test_43) {
    BitArray array_1(7, false);
    BitArray array_2(6, true);
    string check;
    try {
        array_1 ^= array_2;
    } catch (const char* message) {
        check = message;
    }
    EXPECT_EQ("Operation ^= requires same size of arrays", check);
}
