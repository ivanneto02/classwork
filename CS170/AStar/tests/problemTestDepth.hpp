#ifndef __PROBLEMTESTDEPTH_HPP__
#define __PROBLEMTESTDEPTH_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"

TEST(ProblemTests, testDepth1) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->depthOf(root), 0);
}

TEST(ProblemTests, testDepth2) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    myProblem->expand(root);

    EXPECT_EQ(myProblem->depthOf(root), 1);
}

TEST(ProblemTests, testDepth2) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    myProblem->expand(root);
    myProblem->expand(root->getChild(0));

    EXPECT_EQ(myProblem->depthOf(root), 2);
}

TEST(ProblemTests, testDepth2) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    myProblem->expand(root);
    myProblem->expand(root->getChild(0));
    myProblem->expand(root->getChild(0)->getChild(0));

    EXPECT_EQ(myProblem->depthOf(root), 3);
}

#endif