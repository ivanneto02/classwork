#ifndef __STANDARDEXPRESSIONFACTORY_HPP__
#define __STANDARDEXPRESSIONFACTORY_HPP__

#include "ExpressionFactory.hpp"
#include "../product/Base.hpp"

class StandardExpressionFactory : public ExpressionFactory {

    public:

        virtual Base* parser(char** input, int length) const override;
};

#endif