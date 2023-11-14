#ifndef __PROBLEMTESTEXPAND_HPP__
#define __PROBLEMTESTEXPAND_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"
#include <sstream>

TEST(ProblemTests, testExpand1) {
    /* Specific for 8 puzzle, will add more cases later. */

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Board* root = 
    new Board(mat);

    Problem* myProblem = new Problem(root);

    myProblem->expand(root);

    std::ostringstream out;
    std::string compare;
    
    // MOVING LEFT
    compare = "- - - \n1 2 3 \n4 5 6 \n7 0 8 \n- - - \n";
    root->getChild(0)->draw(out);
    EXPECT_EQ(out.str(), compare);
    out.str("");
}

TEST(ProblemTests, testExpand2) {
    /* Specific for 8 puzzle, will add more cases later. */

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Board* root = 
    new Board(mat);

    Problem* myProblem = new Problem(root);

    myProblem->expand(root);

    std::ostringstream out;
    std::string compare;

    // MOVING RIGHT
    compare = "- - - \n1 2 3 \n4 5 6 \n0 7 8 \n- - - \n";
    root->getChild(1)->draw(out);
    EXPECT_EQ(out.str(), compare);
    out.str("");
}

TEST(ProblemTests, testExpand3) {
    /* Specific for 8 puzzle, will add more cases later. */

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Board* root = 
    new Board(mat);

    Problem* myProblem = new Problem(root);

    myProblem->expand(root);

    std::ostringstream out;
    std::string compare;

    // MOVING UP
    compare = "- - - \n1 2 3 \n4 5 0 \n7 8 6 \n- - - \n";
    root->getChild(2)->draw(out);
    EXPECT_EQ(out.str(), compare);
    out.str("");
}

TEST(ProblemTests, testExpand4) {
    /* Specific for 8 puzzle, will add more cases later. */

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Board* root = 
    new Board(mat);

    Problem* myProblem = new Problem(root);

    myProblem->expand(root);

    std::ostringstream out;
    std::string compare;

    // MOVING DOWN
    compare = "- - - \n1 2 0 \n4 5 3 \n7 8 6 \n- - - \n";
    root->getChild(3)->draw(out);
    EXPECT_EQ(out.str(), compare);
    out.str("");
}

TEST(ProblemTests, testExpand5) {
    /* Specific for 8 puzzle, will add more cases later. */

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {0, 7, 8}};
    Board* root = 
    new Board(mat);

    Problem* myProblem = new Problem(root);

    myProblem->expand(root);

    std::ostringstream out;
    std::string compare;

    // MOVING LEFT
    compare = "- - - \n1 2 3 \n4 5 6 \n7 8 0 \n- - - \n";
    root->getChild(0)->draw(out);
    EXPECT_EQ(out.str(), compare);
    out.str("");
}

// TEST(ProblemTests, testExpand6) {
//     /* Specific for 8 puzzle, will add more cases later. */

//     std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
//     Board* root = 
//     new Board(mat);

//     Problem* myProblem = new Problem(root);

//     myProblem->expand(root);

//     std::ostringstream out;
//     std::string compare;

//     // MOVING RIGHT
//     compare = "- - - \n1 2 3 \n4 5 3 \n7 8 6 \n- - - \n";
//     root->getChild(3)->draw(out);
//     EXPECT_EQ(out.str(), compare);
//     out.str("");
// }

// TEST(ProblemTests, testExpand7) {
//     /* Specific for 8 puzzle, will add more cases later. */

//     std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
//     Board* root = 
//     new Board(mat);

//     Problem* myProblem = new Problem(root);

//     myProblem->expand(root);

//     std::ostringstream out;
//     std::string compare;

//     // MOVING DOWN
//     compare = "- - - \n1 2 0 \n4 5 3 \n7 8 6 \n- - - \n";
//     root->getChild(3)->draw(out);
//     EXPECT_EQ(out.str(), compare);
//     out.str("");
// }

#endif