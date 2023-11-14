#ifndef __PROBLEMTESTHEIGHT_HPP__
#define __PROBLEMTESTHEIGHT_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"
#include <sstream>

TEST(ProblemTests, testHeight1) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Board* root = new Board(mat);
    new Board(mat);

    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->heightOf(root), 1);
}

TEST(ProblemTests, testHeight2) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Board* root = 
    new Board(mat);

    Problem* myProblem = new Problem(root);

    myProblem->expand(root);

    EXPECT_EQ(myProblem->heightOf(root), 2);
    EXPECT_EQ(myProblem->heightOf(root->getChild(0)), 1);
}

TEST(ProblemTests, testHeight3) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Board* root = 
    new Board(mat);

    Problem* myProblem = new Problem(root);

    myProblem->expand(root);
    myProblem->expand(root->getChild(0));

    EXPECT_EQ(myProblem->heightOf(root), 3);
    EXPECT_EQ(myProblem->heightOf(root->getChild(0)), 2);
    EXPECT_EQ(myProblem->heightOf(root->getChild(0)->getChild(0)), 1);
}

TEST(ProblemTests, testHeight4) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Board* root = 
    new Board(mat);

    Problem* myProblem = new Problem(root);

    myProblem->expand(root);
    myProblem->expand(root->getChild(0));
    myProblem->expand(root->getChild(0)->getChild(0));

    EXPECT_EQ(myProblem->heightOf(root), 4);
    EXPECT_EQ(myProblem->heightOf(root->getChild(0)), 3);
    EXPECT_EQ(myProblem->heightOf(root->getChild(0)->getChild(0)), 2);
    EXPECT_EQ(myProblem->heightOf(root->getChild(0)->getChild(0)->getChild(0)), 1);
}

#endif