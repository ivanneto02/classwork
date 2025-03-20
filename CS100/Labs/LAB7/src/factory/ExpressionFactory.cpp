#include "../../headers/factory/ExpressionFactory.hpp"
#include "../../headers/factory/StandardExpressionFactory.hpp"

#include <cctype>

Base* ExpressionFactory::parser(char** input, int length) const{

    // Determine validity
    if (!(this->expression_valid())) {
        std::cout << "Invalid operation." << std::endl;
        return nullptr;
    }

}

bool ExpressionFactory::expression_valid(char** input, int length) const {

    for (int i = 0; i < length; i++) {

        // Invalidity conditions
        if (i == 0 && !std::isalpha(input[i]))  { return false; }
        if (input[i] == '(' || input[i] == ')') { return false; }
        if (input[i] == ']' || input[i] == '[') { return false; }
        if (input[i] == '.') { return false; }
        if (input[i] == ',') { return false; }
        if (input[i] == '=') { return false; }
        if (input[i] == ';') { return false; }
        // Possibily add more conditions

    }

    return true;
}  