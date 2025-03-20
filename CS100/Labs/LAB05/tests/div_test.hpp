#include <gtest/gtest.h>

#include "../headers/Op.hpp"
#include "../headers/Div.hpp"

// Evaluate() test suite ( simple operands )
TEST(DivisionEval, posAndPos) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(20.0);
    Base* divOps = new Div(op1, op2);

    ASSERT_DOUBLE_EQ(0.5, divOps->evaluate());
}

TEST(DivisionEval, posAndNeg) {

    Base* op1 = new Op(-10.0);
    Base* op2 = new Op(20.0);
    Base* divOps = new Div(op1, op2);

    ASSERT_DOUBLE_EQ(-0.5, divOps->evaluate());
}

TEST(DivisionEval, negAndNeg) {

    Base* op1 = new Op(-10.0);
    Base* op2 = new Op(-20.0);
    Base* divOps = new Div(op1, op2);

    ASSERT_DOUBLE_EQ(0.5, divOps->evaluate());
}

TEST(DivisionEval, zeroNumerator) {

    Base* op1 = new Op(0.0);
    Base* op2 = new Op(20.0);
    Base* divOps = new Div(op1, op2);

    ASSERT_DOUBLE_EQ(0.0, divOps->evaluate());
}

// Stringify() test suite ( simple operands )
TEST(DivisionStri, posAndPos) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(20.0);
    Base* divOps = new Div(op1, op2);

    ASSERT_EQ("((10.00) / (20.00))", divOps->stringify());
}

TEST(DivisionStri, posAndNeg) {

    Base* op1 = new Op(10.0);
    Base* op2 = new Op(-20.0);
    Base* divOps = new Div(op1, op2);

    ASSERT_EQ("((10.00) / (-20.00))", divOps->stringify());
}

TEST(DivisionStri, negAndNeg) {

    Base* op1 = new Op(-10.0);
    Base* op2 = new Op(-20.0);
    Base* divOps = new Div(op1, op2);

    ASSERT_EQ("((-10.00) / (-20.00))", divOps->stringify());
}

TEST(DivisionStri, zeroNumerator) {

    Base* op1 = new Op(0.0);
    Base* op2 = new Op(20.0);
    Base* divOps = new Div(op1, op2);

    ASSERT_EQ("((0.00) / (20.00))", divOps->stringify());
}
