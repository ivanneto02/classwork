#include <iostream>

#include "../headers/ExpressionFactory1.hpp"

int main(int argc, char** argv) {

    ExpressionFactoryA myParse;
    myParse.parser(argv, argc);

    return 0;
}