#ifndef __BOARD_TEST_SETSTAGE_HPP
#define __BOARD_TEST_SETSTAGE_HPP

#include <sstream>
#include "gtest/gtest.h"
#include "../headers/Board.hpp"

TEST(BoardTest, testSetStage1) {

    std::vector<std::vector<int>> origMat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Board newBoard = Board();
    newBoard.setStage(origMat);

    std::ostringstream output;
    std::ostringstream compare;

    // Fill up compare string
    for (int i = 0; i < origMat.at(0).size(); i++) {
       compare << "- "; 
    }
    compare << "\n";
    // For every row...
    for (int r = 0; r < origMat.size(); r++) {
        // For every item in each row...
        for (int i = 0; i < origMat.at(0).size(); i++) {
            compare << origMat.at(r).at(i) << " ";
        }
        compare << "\n";
    }
    for (int i = 0; i < origMat.at(0).size(); i++) {
       compare << "- "; 
    }
    compare << "\n";

    // Draw onto output string stream
    newBoard.draw(output);

    EXPECT_EQ(compare.str(), output.str());
}

TEST(BoardTest, testSetStage2) {

    std::vector<std::vector<int>> origMat = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};

    Board newBoard = Board();
    newBoard.setStage(origMat);

    std::ostringstream output;
    std::ostringstream compare;

    // Fill up compare string
    for (int i = 0; i < origMat.at(0).size(); i++) {
       compare << "- "; 
    }
    compare << "\n";
    // For every row...
    for (int r = 0; r < origMat.size(); r++) {
        // For every item in each row...
        for (int i = 0; i < origMat.at(0).size(); i++) {
            compare << origMat.at(r).at(i) << " ";
        }
        compare << "\n";
    }
    for (int i = 0; i < origMat.at(0).size(); i++) {
       compare << "- "; 
    }
    compare << "\n";

    // Draw onto output string stream
    newBoard.draw(output);

    EXPECT_EQ(compare.str(), output.str());
}

TEST(BoardTest, testSetStage3) {

    std::vector<std::vector<int>> origMat = {{1, 2}, {3, 4}};

    Board newBoard = Board();
    newBoard.setStage(origMat);

    std::ostringstream output;
    std::ostringstream compare;

    // Fill up compare string
    for (int i = 0; i < origMat.at(0).size(); i++) {
       compare << "- "; 
    }
    compare << "\n";
    // For every row...
    for (int r = 0; r < origMat.size(); r++) {
        // For every item in each row...
        for (int i = 0; i < origMat.at(0).size(); i++) {
            compare << origMat.at(r).at(i) << " ";
        }
        compare << "\n";
    }
    for (int i = 0; i < origMat.at(0).size(); i++) {
       compare << "- "; 
    }
    compare << "\n";

    // Draw onto output string stream
    newBoard.draw(output);

    EXPECT_EQ(compare.str(), output.str());
}

TEST(BoardTest, testSetStage4) {

    std::vector<std::vector<int>> origMat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    Board newBoard = Board();
    newBoard.setStage(origMat);

    std::ostringstream output;
    std::ostringstream compare;

    // Fill up compare string
    for (int i = 0; i < origMat.at(0).size(); i++) {
       compare << "- "; 
    }
    compare << "\n";
    // For every row...
    for (int r = 0; r < origMat.size(); r++) {
        // For every item in each row...
        for (int i = 0; i < origMat.at(0).size(); i++) {
            compare << origMat.at(r).at(i) << " ";
        }
        compare << "\n";
    }
    for (int i = 0; i < origMat.at(0).size(); i++) {
       compare << "- "; 
    }
    compare << "\n";

    // Draw onto output string stream
    newBoard.draw(output);

    EXPECT_EQ(compare.str(), output.str());
}

#endif