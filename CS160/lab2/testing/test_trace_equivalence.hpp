#ifndef TRACETESTS
#define TRACETESTS

#include <iostream>
#include <string>
#include <cstring>
#include "execute_command.hpp"
#include "trace_commands.hpp"
#include "string_equalizer.hpp"
#include <regex>

TEST(TraceTests, Trace01) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace01.txt").c_str());
    std::string rresult = exec(rtrace_command("trace01.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace02) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace02.txt").c_str());
    std::string rresult = exec(rtrace_command("trace02.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace03) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace03.txt").c_str());
    std::string rresult = exec(rtrace_command("trace03.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace04) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace04.txt").c_str());
    std::string rresult = exec(rtrace_command("trace04.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace05) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace05.txt").c_str());
    std::string rresult = exec(rtrace_command("trace05.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace06) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace06.txt").c_str());
    std::string rresult = exec(rtrace_command("trace06.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace07) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace07.txt").c_str());
    std::string rresult = exec(rtrace_command("trace07.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace08) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace08.txt").c_str());
    std::string rresult = exec(rtrace_command("trace08.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace09) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace09.txt").c_str());
    std::string rresult = exec(rtrace_command("trace09.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace10) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace10.txt").c_str());
    std::string rresult = exec(rtrace_command("trace10.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace11) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace11.txt").c_str());
    std::string rresult = exec(rtrace_command("trace11.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace12) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace12.txt").c_str());
    std::string rresult = exec(rtrace_command("trace12.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace13) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace13.txt").c_str());
    std::string rresult = exec(rtrace_command("trace13.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace14) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace14.txt").c_str());
    std::string rresult = exec(rtrace_command("trace14.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace15) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace15.txt").c_str());
    std::string rresult = exec(rtrace_command("trace15.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

TEST(TraceTests, Trace16) {
    // Save the test result from exec running trace01.txt
    // c_str is used because exec requires const char*
    std::string result  = exec(trace_command("trace16.txt").c_str());
    std::string rresult = exec(rtrace_command("trace16.txt").c_str());

    string_equalizer(result);
    string_equalizer(rresult);

    // Tests whether our reference output is the same
    // as our program output
    EXPECT_EQ(result, rresult);
}

#endif