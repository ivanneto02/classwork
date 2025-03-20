#include <gtest/gtest.h>

#include "../headers/iterator.hpp"

#include "../headers/imports.hpp"

class ExpressionChildrenTests : public ::testing::Test {
    public:
        Base* myExpression; 
        Iterator* myIterator;

        ExpressionChildrenTests() {
            // initialization code here
        }
        void SetUp() {
            // code here will execute just before the test ensues 

             /*  Creating expression tree  */
            myExpression = new Add(
                new Add(new Op(2.0), new Op(2.0)),
                new Pow(new Op(2.0), new Op(3.0))
            ); // ( (2 + 2) + (2**3) )

            /*  Initializing iterator  */
            myIterator = new Iterator(myExpression);
        }

        void TearDown() {
            // code here will be called just after the test completes
            // ok to through exceptions from here if need be
        }

        ~ExpressionChildrenTests() {
            // cleanup any pending stuff, but no exceptions allowed
        }

};


class ExpressionGetChildTests : public ::testing::Test {
    public:
        Base* myExpression; 
        Iterator* myIterator;

        ExpressionGetChildTests() {}
        void SetUp() {
             /*  Creating expression tree  */
            myExpression = new Add(
                new Add(new Op(2.0), new Op(2.0)),
                new Pow(new Op(2.0), new Op(3.0))
            ); // ( (2 + 2) + (2**3) )

            /*  Initializing iterator  */
            myIterator = new Iterator(myExpression);
        }

        void TearDown() {}

        ~ExpressionGetChildTests() {}
};


// EXPRESSION CHILDREN TESTS-----------------------------------
TEST_F(ExpressionChildrenTests, twoChildren) {

    /*  Initializing current node  */
    Base* currNode = myIterator->current_node();

    ASSERT_EQ(2, currNode->number_of_children());
}

TEST_F(ExpressionChildrenTests, noChildren) {
   
    myIterator->next(); // Go to Add(2, 2);
    myIterator->next(); // Go to left 2;
    Base* currNode = myIterator->current_node();

    ASSERT_EQ(0, currNode->number_of_children());
}


// EXPRESSION GET CHILD TESTS-----------------------------------------
TEST_F(ExpressionGetChildTests, getLeft) {
    
    Base* currNode = myIterator->current_node();

    ASSERT_EQ("((2.00) + (2.00))", currNode->get_child(0)->stringify() );
}

TEST_F(ExpressionGetChildTests, getRight) {
    
    Base* currNode = myIterator->current_node();

    ASSERT_EQ("((2.00) ** (3.00))", currNode->get_child(1)->stringify() );
}

TEST_F(ExpressionGetChildTests, noChildren) {

    myIterator->next();
    myIterator->next();

    Base* currNode = myIterator->current_node();

    ASSERT_TRUE(currNode->get_child(0) == nullptr);
    ASSERT_TRUE(currNode->get_child(1) == nullptr);
}