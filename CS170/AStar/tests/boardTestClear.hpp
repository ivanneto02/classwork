#ifndef __BOARD_TESTCLEAR_HPP__
#define __BOARD_TESTCLEAR_HPP__

#include "../headers/Board.hpp"
#include "gtest/gtest.h"

TEST(BoardTests, testClear1) {
    std::vector<std::vector<int>> mat = {{1, 2, 3, 4 ,5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};

    Board newBoard = Board(mat);

    std::ostringstream output;

    newBoard.clear();

    newBoard.draw(output);

    std::string compare = "- - - - - \n0 0 0 0 0 \n0 0 0 0 0 \n0 0 0 0 0 \n0 0 0 0 0 \n0 0 0 0 0 \n- - - - - \n";

    EXPECT_EQ(compare, output.str());
}

#endif