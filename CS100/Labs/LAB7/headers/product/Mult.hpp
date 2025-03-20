#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "Base.hpp"

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

#endif // __MULT_HPP__

