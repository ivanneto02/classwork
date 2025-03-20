#ifndef __POW_HPP__
#define __POW_HPP__

#include "Base.hpp"

class Pow : public Base {

    private:
        Base* left;
        Base* right;

    public:
        Pow();
        Pow(Base*, Base*);
        virtual double evaluate() override;
        virtual std::string stringify() override;
};

#endif  // __POW_HPP__
