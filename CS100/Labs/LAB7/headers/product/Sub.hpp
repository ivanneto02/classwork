#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "Base.hpp"

class Sub : public Base {
    private:
        Base* left;
        Base* right;

    public:
        Sub();
        Sub(Base*, Base*);
        virtual double evaluate() override;
        virtual std::string stringify() override;
};

#endif  // __SUB_HPP__
