#include <iostream>
#include "color.hh"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

class TestColor: public Test {
protected:
    Color c1;
    Color c2;
    Color c3;
public:
    TestColor(): c1(), c2(1, 2, 3), c3(1, 2, 3) {}
};

TEST_F(TestColor, Constructor) {
}

TEST_F(TestColor, AccessMembers) {
    EXPECT_EQ(c1.getRed(), 0);
    EXPECT_EQ(c1.getGreen(), 0);
    EXPECT_EQ(c1.getBlue(), 0);

    EXPECT_EQ(c2.getRed(), 1);
    EXPECT_EQ(c2.getGreen(), 2);
    EXPECT_EQ(c2.getBlue(), 3);

    EXPECT_EQ(c3.getRed(), 1);
    EXPECT_EQ(c3.getGreen(), 2);
    EXPECT_EQ(c3.getBlue(), 3);

    c1.setRed(4);
    c1.setGreen(5);
    c1.setBlue(6);

    EXPECT_EQ(c1.getRed(), 4);
    EXPECT_EQ(c1.getGreen(), 5);
    EXPECT_EQ(c1.getBlue(), 6);
}

TEST_F(TestColor, Arithmetic) {
    c1 += c2;

    EXPECT_EQ(c1.getRed(), 1);
    EXPECT_EQ(c1.getGreen(), 2);
    EXPECT_EQ(c1.getBlue(), 3);

    EXPECT_EQ(c2.getRed(), 1);
    EXPECT_EQ(c2.getGreen(), 2);
    EXPECT_EQ(c2.getBlue(), 3);

    c1 -= c2;

    EXPECT_EQ(c1.getRed(), 0);
    EXPECT_EQ(c1.getGreen(), 0);
    EXPECT_EQ(c1.getBlue(), 0);

    EXPECT_EQ(c2.getRed(), 1);
    EXPECT_EQ(c2.getGreen(), 2);
    EXPECT_EQ(c2.getBlue(), 3);

    c1 = c2 + c3;

    EXPECT_EQ(c2.getRed(), 1);
    EXPECT_EQ(c2.getGreen(), 2);
    EXPECT_EQ(c2.getBlue(), 3);

    EXPECT_EQ(c1.getRed(), 2);
    EXPECT_EQ(c1.getGreen(), 4);
    EXPECT_EQ(c1.getBlue(), 6);

    c1 = c1 - c3;

    EXPECT_EQ(c1.getRed(), 1);
    EXPECT_EQ(c1.getGreen(), 2);
    EXPECT_EQ(c1.getBlue(), 3);

    c1 *= 2;

    EXPECT_EQ(c1.getRed(), 2);
    EXPECT_EQ(c1.getGreen(), 4);
    EXPECT_EQ(c1.getBlue(), 6);

    c1 /= 2;

    EXPECT_EQ(c1.getRed(), 1);
    EXPECT_EQ(c1.getGreen(), 2);
    EXPECT_EQ(c1.getBlue(), 3);

    c1 = c1 * 3;

    EXPECT_EQ(c1.getRed(), 3);
    EXPECT_EQ(c1.getGreen(), 6);
    EXPECT_EQ(c1.getBlue(), 9);

    c1 = 3 * c2;

    EXPECT_EQ(c1.getRed(), 3);
    EXPECT_EQ(c1.getGreen(), 6);
    EXPECT_EQ(c1.getBlue(), 9);

    c1 = c2 * c3;

    EXPECT_EQ(c1.getRed(), 1);
    EXPECT_EQ(c1.getGreen(), 4);
    EXPECT_EQ(c1.getBlue(), 9);

    c2 *= c3;

    EXPECT_EQ(c2.getRed(), 1);
    EXPECT_EQ(c2.getGreen(), 4);
    EXPECT_EQ(c2.getBlue(), 9);
}

TEST_F(TestColor, StringTest) {
    ostringstream stream;
    stream << c2;

    EXPECT_EQ("( 1, 2, 3)", stream.str());
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
