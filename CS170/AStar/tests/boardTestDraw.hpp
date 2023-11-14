#ifndef __BOARD_TEST_DRAW_HPP__
#define __BOARD_TEST_DRAW_HPP__

#include "gtest/gtest.h"
#include <sstream>
#include "../headers/Board.hpp"

TEST(BoardTestDraw, drawEmptyBoard) {

    Board newBoard = Board();

    std::ostringstream output;

    newBoard.draw(output);
    
    std::string compare = "- - - \n0 0 0 \n0 0 0 \n0 0 0 \n- - - \n";

    EXPECT_EQ(compare, output.str()); 
}

TEST(BoardTestDraw, drawCustomBoard) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Board newBoard = Board(mat);

    std::ostringstream output;

    newBoard.draw(output);

    std::string compare = "- - - \n1 2 3 \n4 5 6 \n7 8 9 \n- - - \n";

    EXPECT_EQ(compare, output.str());
}

TEST(BoardTestDraw, drawBigEmpty) {

    Board newBoard = Board(5, 5);

    std::ostringstream output;

    newBoard.draw(output);

    std::string compare = "- - - - - \n0 0 0 0 0 \n0 0 0 0 0 \n0 0 0 0 0 \n0 0 0 0 0 \n0 0 0 0 0 \n- - - - - \n";

    EXPECT_EQ(compare, output.str());   
}

TEST(BoardTestDraw, drawBigCustom) {

    std::vector<std::vector<int>> mat = {{1, 2, 3, 4 ,5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};

    Board newBoard = Board(mat);

    std::ostringstream output;

    newBoard.draw(output);

    std::string compare = "- - - - - \n1 2 3 4 5 \n6 7 8 9 10 \n11 12 13 14 15 \n16 17 18 19 20 \n21 22 23 24 25 \n- - - - - \n";

    EXPECT_EQ(compare, output.str());
}

#endif