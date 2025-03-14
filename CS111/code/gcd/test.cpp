#include "gtest/gtest.h"
#include "GCD.hpp"

TEST(GCDTest, Zeros) {

    // Test 0, 0
    GCD curr(0, 0);
    EXPECT_EQ(0, curr.gcd());

    // Test five in the format (x, 0)
    for (int i = 0; i < 5; i++) {

        curr = GCD(0, i + 1);
        EXPECT_EQ(0, curr.gcd());
    }

    // Test five in the format(0, x)
    for (int i = 0; i < 5; i++) {

        curr = GCD(0, i + 1);
        EXPECT_EQ(0, curr.gcd());
    }
}

TEST(GCDTest, Negatives) {
    // Expects -1 for all inputs with either negative
    
    // Left is negative
    GCD curr = GCD(-10, 10);
    EXPECT_EQ(-1, curr.gcd());

    // Both
    curr = GCD(-10, -10);
    EXPECT_EQ(-1, curr.gcd());

    // Right is negative
    curr = GCD(10, -10);
    EXPECT_EQ(-1, curr.gcd());
}

TEST(GCDTest, Normal) {

    // Pre-computed GCD values

    GCD curr = GCD(1, 1);
    EXPECT_EQ(1, curr.gcd());

    curr = GCD(11, 121);
    EXPECT_EQ(121, curr.gcd());

    curr = GCD(34, 52);
    EXPECT_EQ(2, curr.gcd());

    curr = GCD(45, 100);
    EXPECT_EQ(5, curr.gcd());

    curr = GCD(123, 321);
    EXPECT_EQ(3, curr.gcd());
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}