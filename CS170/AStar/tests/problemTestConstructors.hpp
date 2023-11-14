#ifndef __PROBLEMTESTCONST_HPP__
#define __PROBLEMTESTCONST_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"
#include <sstream>

TEST(ProblemTests, testConstructor1) {

    Problem* myProblem = new Problem();

    Board* root = myProblem.getRoot();

    std::ostringstream out;
    root->draw(out);

    std::string compare = "- - - \n1 2 3 \n4 5 6 \n7 8 0 \n- - - \n";

    EXPECT_EQ(myProblem->height(), 1);
    EXPECT_EQ(myProblem->size(), 1);
    EXPECT_EQ(out.str(), compare);
}

TEST(ProblemTests, testConstructor2) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 0, 8}};

    Board* root = new Board(mat);

    Problem* myProblem = new Problem(root);

    std::ostringstream out;

    myProblem->getRoot()->draw(out);

    std::string compare = "- - - \n1 2 3 \n4 5 6 \n7 0 8 \n- - - \n";

    EXPECT_EQ(myProblem->height(), 1);
    EXPECT_EQ(myProblem->size(), 1);
    EXPECT_EQ(out.str(), compare);
}

#endif
