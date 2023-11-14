#ifndef EXECUTE_COMMANDS
#define EXECUTE_COMMANDS

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer; // buffer to store line
    std::string result;           // we will return this variable

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);

    // In the case that pipe failed to be created
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    // Add data from the buffer to result while we are able to get output
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    // return the entirety of the output of running a command
    return result;
}

#endif