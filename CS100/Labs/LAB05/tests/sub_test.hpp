#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include <gtest/gtest.h>

#include "../headers/Sub.hpp"

using namespace std; 

// Evaluate() test suite
TEST(SubEval, posAndPos) {

    Base* op1 = new Op(5.0);
    Base* op2 = new Op(3.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_DOUBLE_EQ(2.0, subOps->evaluate());  
}

TEST(SubEval, posAndNeg) {
    
    Base* op1 = new Op(5.0);
    Base* op2 = new Op(-3.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_DOUBLE_EQ(8.0, subOps->evaluate());  
}

TEST(SubEval, negAndNeg) {

    Base* op1 = new Op(-5.0);
    Base* op2 = new Op(-3.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_DOUBLE_EQ(-2.0, subOps->evaluate());  
}

TEST(SubEval, subZero) {

    Base* op1 = new Op(5.0);
    Base* op2 = new Op(0.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_DOUBLE_EQ(5.0, subOps->evaluate());  
}

TEST(SubEval, zeroSub) {

    Base* op1 = new Op(0.0);
    Base* op2 = new Op(5.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_DOUBLE_EQ(-5.0, subOps->evaluate());  
}

// Stringify() test suite
TEST(SubStri, posAndPos) {

    Base* op1 = new Op(5.0);
    Base* op2 = new Op(3.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_EQ("((5.00) - (3.00))", subOps->stringify());
}

TEST(SubStri, posAndNeg) {

    Base* op1 = new Op(5.0);
    Base* op2 = new Op(-3.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_EQ("((5.00) - (-3.00))", subOps->stringify());
}

TEST(SubStri, negAndNeg) {

    Base* op1 = new Op(-5.0);
    Base* op2 = new Op(-3.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_EQ("((-5.00) - (-3.00))", subOps->stringify());
}

TEST(SubStri, subZero) {

    Base* op1 = new Op(5.0);
    Base* op2 = new Op(0.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_EQ("((5.00) - (0.00))", subOps->stringify());
}

TEST(SubStri, zeroSub) {

    Base* op1 = new Op(0.0);
    Base* op2 = new Op(5.0);
    Base* subOps = new Sub(op1, op2);

    ASSERT_EQ("((0.00) - (5.00))", subOps->stringify());
}
 
#endif

