#ifndef __PROBLEMTESTTREEHEIGHT_HPP__
#define __PROBLEMTESTTREEHEIGHT_HPP__

#include "gtest/gtest.h"

#include "../headers/Problem.hpp"

TEST(ProblemTests, treeHeight1) {

    // Regular 8-puzzle
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProb = new Problem(root);

    EXPECT_EQ(myProb->height(), 1);
}

TEST(ProblemTests, treeHeight2) {

    // Regular 8-puzzle
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);

    Problem* myProb = new Problem(root);

    myProb->expand(root);

    EXPECT_EQ(myProb->height(), 2);
}

TEST(ProblemTests, treeHeight3) {

    // Regular 8-puzzle
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProb = new Problem(root);

    // Expand twice
    myProb->expand(root);
    myProb->expand(root->getChild(0));

    EXPECT_EQ(myProb->height(), 3);
}

TEST(ProblemTests, treeHeight4) {

    // Regular 8-puzzle
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProb = new Problem(root);

    // Expand three times
    myProb->expand(root);
    myProb->expand(root->getChild(0));
    myProb->expand(root->getChild(0)->getChild(0));

    EXPECT_EQ(myProb->height(), 4);
}

#endif