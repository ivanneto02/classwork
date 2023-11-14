#ifndef __PROBLEMTESTHEURISTIC_HPP__
#define __PROBLEMTESTHEURISTIC_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"
 
/*
NOTE:

Right now only testing for 3x3 puzzle, or 8-puzzle. The reason for this
is that I don't want to calculate the heuristic for larger puzzles as it would
be difficult and error prone. But eventually I will, to test them out.
*/

TEST(ProblemTests, misplacedTile1) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 0, 8}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->misplacedHeuristic(root), 1); // one right
}

TEST(ProblemTests, misplacedTile2) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->misplacedHeuristic(root), 0); // don't move
}

TEST(ProblemTests, misplacedTile3) {

    std::vector<std::vector<int>> mat = {{4, 1, 2}, {5, 6, 0}, {7, 8, 3}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->misplacedHeuristic(root), 6); // move a lot
}

TEST(ProblemTests, misplacedTile1) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 0, 8}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->euclideanHeuristic(root), 1); // one right
}

TEST(ProblemTests, misplacedTile2) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->euclideanHeuristic(root), 0); // don't move
}

TEST(ProblemTests, misplacedTile3) {

    std::vector<std::vector<int>> mat = {{4, 1, 2}, {5, 6, 0}, {7, 8, 3}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->euclideanHeuristic(root), 7); // ADD ACTUAL HEURISTIC
}

#endif