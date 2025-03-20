#include <iostream>

#include "headers/factory/ExpressionFactory.hpp"
#include "headers/factory/StandardExpressionFactory.hpp"

int main(int argc, char** argv) {

    ExpressionFactory myParse;
    myParse.parser(argv, argc);

    return 0;
}