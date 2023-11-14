#ifndef __BOARD_TESTCONST_HPP__
#define __BOARD_TESTCONST_HPP__

#include "../headers/Board.hpp"
#include "gtest/gtest.h"

TEST(BoardTests, testConstructor1) {

    Board newBoard = Board();

    std::ostringstream output;

    std::string compare = "- - - \n0 0 0 \n0 0 0 \n0 0 0 \n- - - \n";

    std::vector<std::vector<int>> mat = newBoard.getMat();    

    for (int i = 0; i < newBoard.getWidth(); i++) {
       output << "- "; 
    }
    output << "\n";
    // For every row...
    for (int r = 0; r < newBoard.getLength(); r++) {
        // For every item in each row...
        for (int i = 0; i < newBoard.getWidth(); i++) {
            
            output << mat.at(r).at(i) << " ";
        }
        output << "\n";
    }
    for (int i = 0; i < newBoard.getWidth(); i++) {
       output << "- "; 
    }
    output << "\n";

    EXPECT_EQ(compare, output.str());
}

TEST(BoardTests, testConstructor2) {

    Board newBoard = Board(10, 10);

    std::ostringstream output;

    std::string compare = "- - - - - - - - - - \n0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 \n- - - - - - - - - - \n";

    std::vector<std::vector<int>> mat = newBoard.getMat();

    for (int i = 0; i < newBoard.getWidth(); i++) {
       output << "- "; 
    }
    output << "\n";
    // For every row...
    for (int r = 0; r < newBoard.getLength(); r++) {
        // For every item in each row...
        for (int i = 0; i < newBoard.getWidth(); i++) {
            
            output << mat.at(r).at(i) << " ";
        }
        output << "\n";
    }
    for (int i = 0; i < newBoard.getWidth(); i++) {
       output << "- "; 
    }
    output << "\n";

    EXPECT_EQ(compare, output.str()); 
} 

TEST(BoardTests, testConstructor3) {

    int w = 3;
    int h = 3;

    std::vector<std::vector<int>> origMat(h);
    for (int r = 0; r < origMat.size(); r++) { // Iterate through rows
        origMat.at(r) = std::vector<int>(w);
        for (int i = 0; i < origMat.at(0).size(); i++) { // Fill up row
            origMat.at(r).at(i) = i;
        }
    }

    Board newBoard = Board(origMat);

    std::ostringstream output;
    std::ostringstream compare;

    // Fill up compare string
    for (int i = 0; i < w; i++) {
       compare << "- "; 
    }
    compare << "\n";
    // For every row...
    for (int r = 0; r < h; r++) {
        // For every item in each row...
        for (int i = 0; i < w; i++) {
            compare << origMat.at(r).at(i) << " ";
        }
        compare << "\n";
    }
    for (int i = 0; i < w; i++) {
       compare << "- "; 
    }
    compare << "\n";

    std::vector<std::vector<int>> mat = newBoard.getMat();

    // Fill up Board string
    for (int i = 0; i < newBoard.getWidth(); i++) {
       output << "- "; 
    }
    output << "\n";
    // For every row...
    for (int r = 0; r < newBoard.getLength(); r++) {
        // For every item in each row...
        for (int i = 0; i < newBoard.getWidth(); i++) {
            output << mat.at(r).at(i) << " ";
        }
        output << "\n";
    }
    for (int i = 0; i < newBoard.getWidth(); i++) {
       output << "- "; 
    }
    output << "\n";

    EXPECT_EQ(compare.str(), output.str());
}

#endif