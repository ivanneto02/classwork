#ifndef HELPER_TESTS
#define HELPER_TESTS

#include "string_equalizer.hpp"

TEST(HelperTests, Trace01) {
    
    std::string result1 = "(123123) hello there (321423) hi hi ... ()";
    std::string result2 = "(11129837) hello there (9812938) hi hi ... ()";

    string_equalizer(result1);
    string_equalizer(result2);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result1, result2);
}

#endif