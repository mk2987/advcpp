#include <iostream>
#include "vector3f.hh"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

class TestVector3F: public Test {
protected:
    Vector3F v1;
    Vector3F v2;
    Vector3F v3;
public:
    TestVector3F(): v1(), v2(1, 2, 3), v3(1, 2, 3) {}
};

TEST_F(TestVector3F, Constructor) {
}

TEST_F(TestVector3F, AccessMembers) {
    EXPECT_EQ(v1[0], 0);
    EXPECT_EQ(v1[1], 0);
    EXPECT_EQ(v1[2], 0);

    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);

    EXPECT_EQ(v3[0], 1);
    EXPECT_EQ(v3[1], 2);
    EXPECT_EQ(v3[2], 3);

    v1[0] = 4;
    v1[1] = 5;
    v1[2] = 6;

    EXPECT_EQ(v1[0], 4);
    EXPECT_EQ(v1[1], 5);
    EXPECT_EQ(v1[2], 6);
}

TEST_F(TestVector3F, Arithmetic) {
    v1 += v2;

    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 3);

    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);

    v1 -= v2;

    EXPECT_EQ(v1[0], 0);
    EXPECT_EQ(v1[1], 0);
    EXPECT_EQ(v1[2], 0);

    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);

    v1 = v2 + v3;

    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);

    EXPECT_EQ(v1[0], 2);
    EXPECT_EQ(v1[1], 4);
    EXPECT_EQ(v1[2], 6);

    v1 = v1 - v3;

    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 3);

    v1 *= 2;

    EXPECT_EQ(v1[0], 2);
    EXPECT_EQ(v1[1], 4);
    EXPECT_EQ(v1[2], 6);

    v1 /= 2;

    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 3);

    v1 = v1 * 3;

    EXPECT_EQ(v1[0], 3);
    EXPECT_EQ(v1[1], 6);
    EXPECT_EQ(v1[2], 9);

    v1 = 3 * v2;

    EXPECT_EQ(v1[0], 3);
    EXPECT_EQ(v1[1], 6);
    EXPECT_EQ(v1[2], 9);
}

TEST_F(TestVector3F, VectorProduct) {
    float res = v2 * v3;

    EXPECT_EQ(res, 14);

    v1 = v2 % v3;

    EXPECT_EQ(v1[0], 0);
    EXPECT_EQ(v1[1], 0);
    EXPECT_EQ(v1[2], 0);
}

TEST_F(TestVector3F, Magnitude) {
    float res = v2.magSq();

    EXPECT_EQ(res, 14);

    res = v2.mag();

    EXPECT_FLOAT_EQ(res, sqrtf(14));

    v1 = v2.norm();

    EXPECT_FLOAT_EQ(v1[0], 1 / sqrtf(14));
    EXPECT_FLOAT_EQ(v1[1], 2 / sqrtf(14));
    EXPECT_FLOAT_EQ(v1[2], 3 / sqrtf(14));
}

TEST_F(TestVector3F, StringTest) {
    ostringstream stream;
    stream << v2;

    EXPECT_EQ("( 1, 2, 3)", stream.str());
}


int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
