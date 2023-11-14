#include "gtest/gtest.h"

// testing the tests
#include "tests/testtest.hpp"

// Queue class
#include "tests/queueTests.hpp"

// Board class
#include "tests/boardTestConstructors.hpp"
#include "tests/boardTestSetStage.hpp"
#include "tests/boardTestDraw.hpp"
#include "tests/boardTestClear.hpp"
#include "tests/problemTestExpand.hpp"

// Problem class

// GameDriver class

// Client tests

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}