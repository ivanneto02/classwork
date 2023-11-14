#ifndef STRING_EQUALIZER
#define STRING_EQUALIZER

#include <string>
#include <regex>

/*
Takes in a string and removes everything in between parenthesis.

The purpose for this function is to test my output for the traces.
*/
void string_equalizer(std::string& inputStr) {

    /* Using regex to remove unequalizers. */
    inputStr = std::regex_replace(inputStr, std::regex{"\\(.*\\)"}, "(...)"); // parentheses
    inputStr = std::regex_replace(inputStr, std::regex{"\\[.*\\]"}, "[...]"); // brackers
    inputStr = std::regex_replace(inputStr, std::regex{"tshref"}, "");        // references to tshref
    inputStr = std::regex_replace(inputStr, std::regex{"tsh"}, "");           // references to tsh
    inputStr = std::regex_replace(inputStr, std::regex{"\\d*"}, "");           // numbers
}

#endif