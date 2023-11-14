#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include "test_string_eq_helper.hpp"
#include "test_trace_equivalence.hpp"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}