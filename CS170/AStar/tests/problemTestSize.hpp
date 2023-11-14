#ifndef __PROBLEMTESTSIZE_HPP__
#define __PROBLEMTESTSIZE_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"

TEST(ProblemTests, testSize1) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->size(), 1);
}

TEST(ProblemTests, testSize2) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    myProblem->expand(root);

    EXPECT_EQ(myProblem->size(), 5);
}

TEST(ProblemTests, testSize3) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    myProblem->expand(root);
    myProblem->expand(root->getChild(0));

    EXPECT_EQ(myProblem->size(), 9);
}

TEST(ProblemTests, testSize4) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    myProblem->expand(root);
    myProblem->expand(root->getChild(0));
    myProblem->expand(root->getChild(0)->getChild(0));

    EXPECT_EQ(myProblem->size(), 13);
}

TEST(ProblemTests, testSize5) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    myProblem->expand(root);
    myProblem->expand(root->getChild(0));
    myProblem->expand(root->getChild(0)->getChild(0));
    myProblem->expand(root->getChild(1)->getChild(0));

    EXPECT_EQ(myProblem->size(), 17);
}

TEST(ProblemTests, testSize6) {
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    myProblem->expand(root);
    myProblem->expand(root->getChild(0));
    myProblem->expand(root->getChild(0)->getChild(0));
    myProblem->expand(root->getChild(1)->getChild(0));
    myProblem->expand(root->getChild(2)->getChild(0));

    EXPECT_EQ(myProblem->size(), 21);
}

#endif