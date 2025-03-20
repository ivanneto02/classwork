#ifndef __DIV_HPP__
#define __DIV_HPP__

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

#endif //__DIV_HPP__
