#include <gtest/gtest.h>

#include "iterator_tests.hpp"
#include "latex_tests.hpp"
#include "mathml_tests.hpp"

int main(int argc, char** argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}