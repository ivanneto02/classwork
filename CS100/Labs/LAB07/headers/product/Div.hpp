#ifndef DIV_H
#define DIV_H

#include "Base.hpp"

class Div : public Base {

    private:
        Base* left;
        Base* right;

    public:
        Div();
        Div(Base*, Base*);

        virtual double evaluate() override;
        virtual std::string stringify() override;
};

#endif
