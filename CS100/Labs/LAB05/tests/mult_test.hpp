#include <gtest/gtest.h>

#include "../headers/Mult.hpp"

// Evaluate() test suite
TEST(MultEval, posAndPos) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(10.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_DOUBLE_EQ(100.0, multOps->evaluate());
}

TEST(MultEval, posAndNeg) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(-10.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_DOUBLE_EQ(-100.0, multOps->evaluate());
}

TEST(MultEval, negAndNeg) {

    Base* op1 = new Op(-10.0);
    Base* op2 = new Op(-10.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_DOUBLE_EQ(100.0, multOps->evaluate());
}

TEST(MultEval, zeroTo) {

    Base* op1 = new Op(0.0);
    Base* op2 = new Op(10.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_DOUBLE_EQ(0.0, multOps->evaluate());
}

TEST(MultEval, toZero) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(0.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_DOUBLE_EQ(0.0, multOps->evaluate());
}

// Stringify() test suite
TEST(MultStri, posAndPos) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(10.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_EQ("((10.00) * (10.00))", multOps->stringify());
}

TEST(MultStri, posAndNeg) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(-10.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_EQ("((10.00) * (-10.00))", multOps->stringify());
} 

TEST(MultStri, negAndNeg) {

    Base* op1 = new Op(-10.0);
    Base* op2 = new Op(-10.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_EQ("((-10.00) * (-10.00))", multOps->stringify());
}

TEST(MultStri, zeroTo) {

    Base* op1 = new Op(0.0);
    Base* op2 = new Op(10.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_EQ("((0.00) * (10.00))", multOps->stringify());
}

TEST(MultStri, toZero) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(0.0);
    Base* multOps = new Mult(op1, op2);

    ASSERT_EQ("((10.00) * (0.00))", multOps->stringify());
}