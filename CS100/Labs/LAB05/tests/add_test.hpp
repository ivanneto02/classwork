#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include <gtest/gtest.h>
#include "../headers/Add.hpp"
#include "../headers/Op.hpp"

// Evaluate() test suite
TEST(AdditionEval, posAndPos) {

    Base* op1 = new Op(15.0);
    Base* op2 = new Op(15.0);
    Base* addOps = new Add(op1, op2);

    ASSERT_DOUBLE_EQ(30.0, addOps->evaluate());
}

TEST(AdditionEval, posAndNeg) {

    Base* op1 = new Op(-20.0);
    Base* op2 = new Op(15.0);
    Base* addOps = new Add(op1, op2);

    ASSERT_DOUBLE_EQ(-5.0, addOps->evaluate()); 
}

TEST(AdditionEval, negAndNeg) {

    Base* op1 = new Op(-15.0);
    Base* op2 = new Op(-15.0);
    Base* addOps = new Add(op1, op2);

    ASSERT_DOUBLE_EQ(-30.0, addOps->evaluate());
}

TEST(AdditionEval, checkZeroSum) {

    Base* op1 = new Op(15.0);
    Base* op2 = new Op(-15.0);
    Base* addOps = new Add(op1, op2);

    ASSERT_DOUBLE_EQ(0.0, addOps->evaluate());
}

// Stringify() test suite
TEST(AdditionStri, posAndPos) {

    Base* op1 = new Op(15);
    Base* op2 = new Op(15);
    Base* addOps = new Add(op1, op2);

    ASSERT_EQ("((15.00) + (15.00))", addOps->stringify());
}

TEST(AdditionStri, posAndNeg) {

    Base* op1 = new Op(-20);
    Base* op2 = new Op(15);
    Base* addOps = new Add(op1, op2);

    ASSERT_EQ("((-20.00) + (15.00))", addOps->stringify());
}

TEST(AdditionStri, negAndNeg) {

    Base* op1 = new Op(-15);
    Base* op2 = new Op(-15);
    Base* addOps = new Add(op1, op2);

    ASSERT_EQ("((-15.00) + (-15.00))", addOps->stringify());
}

TEST(AdditionStri, checkZeroSum) {

    Base* op1 = new Op(-15);
    Base* op2 = new Op(15);
    Base* addOps = new Add(op1, op2);

    ASSERT_EQ("((-15.00) + (15.00))", addOps->stringify());
}

#endif