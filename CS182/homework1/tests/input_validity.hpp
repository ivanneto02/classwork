#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <regex>

struct InputValidityFixture : public ::testing::Test {

    int failures;

    // performs action at the start of fixture execution
    virtual void SetUp() {
        failures = 0;
    }

    // performs action at the end of fixture execution
    virtual void TearDown() {
        if (failures > 0) {
            std::cerr << "Errors encountered in this test. Do not proceed with input" << std::endl;
            // exit(0);
        }

    }

};

// Test1: Tests whether input contains \D followed by nonprintable character
TEST_F(InputValidityFixture, DAndNonPrintable) {

    std::ifstream inFS;
    inFS.open("./input.txt");

    if (!inFS.is_open()) {
        std::cerr << "Error opening input.txt" << std::endl;
        exit(0);
    }

    std::string finalInputString = "";
    char curr;

    // read every line from input.txt
    while (inFS.get(curr)) {
        if (inFS.fail()) {
            std::cerr << "Input reading failure" << std::endl;
        }
        finalInputString += curr;
    }

    // std::cout << finalInputString << std::endl;

    // check validity

    std::smatch m;// holds the match

    // Detects \D followed by nonprintable. Credit: https://stackoverflow.com/questions/24229262/match-non-printable-non-ascii-characters-and-remove-from-text
    std::regex pattern(R"(\\D[^ -~])");

    EXPECT_FALSE( std::regex_search(finalInputString, m, pattern) );

    std::cout<<"String that matches the pattern:"<<std::endl;
    for (auto x : m) 
        std::cout << "\"" << x << "\"" << " "; 

    failures += ::testing::Test::HasFailure();
}

TEST_F(InputValidityFixture, GivenRangeAndNewline) {
    
    std::ifstream inFS;
    inFS.open("./input.txt");

    if (!inFS.is_open()) {
        std::cerr << "Error opening input.txt" << std::endl;
        exit(0);
    }

    std::string finalInputString = "";
    char curr;

    // read every line from input.txt
    while (inFS.get(curr)) {
        if (inFS.fail()) {
            std::cerr << "Input reading failure" << std::endl;
        }
        finalInputString += curr;
    }


    // check validity

    std::smatch m;// holds the match

    // Detects ASCII range 128-255 followed by newline. Credit: https://stackoverflow.com/questions/3203190/regex-any-ascii-character
    std::regex pattern("[\x80-\xFF]\n+");

    EXPECT_FALSE(std::regex_search(finalInputString, m, pattern));

    std::cout<<"String that matches the pattern:"<<std::endl;
    for (auto x : m) 
        std::cout << "\"" << x << "\"" << " ";

    failures += ::testing::Test::HasFailure();
}

TEST_F(InputValidityFixture, SingleDotAndNewline) {
    
    std::ifstream inFS;
    inFS.open("./input.txt");

    if (!inFS.is_open()) {
        std::cerr << "Error opening input.txt" << std::endl;
        exit(0);
    }

    std::string finalInputString = "";
    char curr;

    // read every line from input.txt
    while (inFS.get(curr)) {
        if (inFS.fail()) {
            std::cerr << "Input reading failure" << std::endl;
        }
        finalInputString += curr;
    }

    // check validity

    // Detects single dot followed by newline

    EXPECT_TRUE(finalInputString.find(".\n") == std::string::npos);

    failures += ::testing::Test::HasFailure();
}