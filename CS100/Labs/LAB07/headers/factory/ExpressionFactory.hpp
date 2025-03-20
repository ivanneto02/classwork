#ifndef __EXPRESSIONFACTORY_HPP__
#define __EXPRESSIONFACTORY_HPP__

#include "../product/Base.hpp"

class ExpressionFactory {

    public:
        virtual Base* parser(char** input, int length) const = 0;
};

#endif