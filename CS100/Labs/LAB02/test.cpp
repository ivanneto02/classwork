#include "c-echo.h"
#include "c-count.h"
#include "gtest/gtest.h"
#include <string>

TEST(EchoTest, HelloWorld) {

    char* test_val[3]; 
    test_val[0] = "./c-echo"; 
    test_val[1] = "hello";
    test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3, test_val));
}

TEST(EchoTest, EmptyString) {

    char* test_val[0];
    test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1, test_val));
}

TEST(EchoTest, PeriodInString) {

    // Define different cases
    char* cecho = "./c-echo";
    char* single_per[2]; single_per[0] = cecho; single_per[1] = ".";
    char* end_per[4]; end_per[0] = cecho; end_per[1] = "hello"; end_per[2] = "world"; end_per[3] = ".";
    char* start_per[3]; start_per[0] = cecho; start_per[1] = "."; start_per[2] = "hello";

    // Test three ways period could be in string
    EXPECT_EQ(".", echo(2, single_per));
    EXPECT_EQ("hello world .", echo(4, end_per));
    EXPECT_EQ(". hello", echo(3, start_per));
}

TEST(EchoTest, HasNewLine) {

    // Define different cases
    char* cecho = "./c-echo";
    char* single[2]; single[0] = cecho; single[1] = "\n";
    char* end[4]; end[0] = cecho; end[1] = "hello"; end[2] = "world"; end[3] = "\n";
    char* start[3]; start[0] = cecho; start[1] = "\n"; start[2] = "hello";

    // Test three ways period could be in string
    EXPECT_EQ("\n", echo(2, single));
    EXPECT_EQ("hello world \n", echo(4, end));
    EXPECT_EQ("\n hello", echo(3, start));
}

TEST(EchoTest, Asterisk) {

    // Define different cases
    char* cecho = "./c-echo";
    char* single[2]; single[0] = cecho; single[1] = "*";
    char* end[4]; end[0] = cecho; end[1] = "hello"; end[2] = "world"; end[3] = "*";
    char* start[3]; start[0] = cecho; start[1] = "*"; start[2] = "hello";

    // Test three ways period could be in string
    EXPECT_EQ("*", echo(2, single));
    EXPECT_EQ("hello world *", echo(4, end));
    EXPECT_EQ("* hello", echo(3, start));
}

// COUNT TESTS 
TEST(CountTest, HelloWorld) {
	    std::string test_str = "hello world";
		    EXPECT_EQ(2, count(test_str));
}

TEST(CountTest, EmptyString) {
	    std::string test_str = "";
		    EXPECT_EQ(0, count(test_str));
}

TEST(CountTest, ManySpaces) {
	    std::string test_str = "   this   string has     weird   spacing";
		    EXPECT_EQ(5, count(test_str));
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
