#include <gtest/gtest.h>

// Valid expression test suite
TEST(ValidExpression, singleSum) {


}

TEST(ValidExpression, singleMult) {


}

TEST(ValidExpression, singleDiv) {


}

TEST(ValidExpression, compoundExp) {


}

// Invalid expression test suite
TEST(InvalidExpression, singleSum) {


}

TEST(InvalidExpression, singleMult) {


}

TEST(InvalidExpression, singleDiv) {


}

TEST(InvalidExpression, compoundExp) {


}

int main(int argc, char** argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}