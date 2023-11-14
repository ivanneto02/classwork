#ifndef __BOARDTESTCHILD_HPP__
#define __BOARDTESTCHILD_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"
#include <sstream>

TEST(BoardTests, testChild1) {

    // Makes solved 8x8 puzzle
    Problem* myProblem = new Problem();

    // Expand the root node
    myProblem->expand(myProblem->getRoot());

    std::ostringstream out;

    std::string compare = "- - - \n1 2 3 \n4 5 6 \n7 0 8 \n- - - \n";

    myProblem->getRoot()->getChild(0)->draw(out);

    EXPECT_EQ(out.str(), compare);
}

TEST(BoardTests, testChild2) {
    // Makes solved 8x8 puzzle
    Problem* myProblem = new Problem();

    // Expand the root node
    myProblem->expand(myProblem->getRoot());

    std::ostringstream out;

    std::string compare = "- - - \n1 2 3 \n4 5 6 \n0 7 8 \n- - - \n";

    myProblem->getRoot()->getChild(1)->draw(out);

    EXPECT_EQ(out.str(), compare);
}

TEST(BoardTests, testChild3) {

    // Makes solved 8x8 puzzle
    Problem* myProblem = new Problem();

    // Expand the root node
    myProblem->expand(myProblem->getRoot());

    std::ostringstream out;

    std::string compare = "- - - \n1 2 3 \n4 5 0 \n7 8 6 \n- - - \n";

    myProblem->getRoot()->getChild(2)->draw(out);

    EXPECT_EQ(out.str(), compare);
}

TEST(BoardTests, testChild4) {

    // Makes solved 8x8 puzzle
    Problem* myProblem = new Problem();

    // Expand the root node
    myProblem->expand(myProblem->getRoot());

    std::ostringstream out;

    std::string compare = "- - - \n1 2 0 \n4 5 3 \n7 8 6 \n- - - \n";

    myProblem->getRoot()->getChild(3)->draw(out);

    EXPECT_EQ(out.str(), compare);
}

#endif