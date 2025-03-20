#include <gtest/gtest.h>

#include "../headers/Pow.hpp"

// Evaluate() test suite
TEST(PowEval, posAndPos) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(2.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_DOUBLE_EQ(100.0, powOps->evaluate());
}

TEST(PowEval, posAndNeg) {

    Base* op1 = new Op(2.0);
    Base* op2 = new Op(-2.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_DOUBLE_EQ(0.25, powOps->evaluate());
}

TEST(PowEval, negAndNeg) {

    Base* op1 = new Op(-2.0);
    Base* op2 = new Op(-2.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_DOUBLE_EQ(0.25, powOps->evaluate());

    op1 = new Op(-1.0);
    op2 = new Op(-3.0);
    powOps = new Pow(op1, op2);

    ASSERT_DOUBLE_EQ(-1.0, powOps->evaluate());
}

TEST(PowEval, toZero) {

    Base* op1 = new Op(27.0);
    Base* op2 = new Op(0.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_DOUBLE_EQ(1.0, powOps->evaluate());
}

TEST(PowEval, zeroTo) {

    Base* op1 = new Op(0.0);
    Base* op2 = new Op(27.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_DOUBLE_EQ(0.0, powOps->evaluate());
}

TEST(PowEval, one) {

    Base* op1 = new Op(1.0);
    Base* op2 = new Op(27.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_DOUBLE_EQ(1.0, powOps->evaluate());
}

// Stringify() test suite
TEST(PowStri, posAndPos) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(2.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_EQ("((10.00) ** (2.00))", powOps->stringify());
}

TEST(PowStri, posAndNeg) {

    Base* op1 = new Op(2.0);
    Base* op2 = new Op(-2.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_EQ("((2.00) ** (-2.00))", powOps->stringify());
}

TEST(PowStri, negAndNeg) {

    Base* op1 = new Op(-2.0);
    Base* op2 = new Op(-2.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_EQ("((-2.00) ** (-2.00))", powOps->stringify());

    op1 = new Op(-1.0);
    op2 = new Op(-3.0);
    powOps = new Pow(op1, op2);

    ASSERT_EQ("((-1.00) ** (-3.00))", powOps->stringify());
}

TEST(PowStri, toZero) {

    Base* op1 = new Op(27.0);
    Base* op2 = new Op(0.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_EQ("((27.00) ** (0.00))", powOps->stringify());
}

TEST(PowStri, zeroTo) {

    Base* op1 = new Op(0.0);
    Base* op2 = new Op(27.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_EQ("((0.00) ** (27.00))", powOps->stringify());
}

TEST(PowStri, one) {

    Base* op1 = new Op(1.0);
    Base* op2 = new Op(27.0);
    Base* powOps = new Pow(op1, op2);

    ASSERT_EQ("((1.00) ** (27.00))", powOps->stringify());
}