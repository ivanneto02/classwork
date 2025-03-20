#ifndef MULT_H
#define MULT_H

#include "../headers/Base.hpp"

class Mult : public Base {

    private:
        Base* left;
        Base* right;

    public:
        Mult();
        Mult(Base*, Base*);
        virtual double evaluate() override;
        virtual std::string stringify() override;
};

#endif

