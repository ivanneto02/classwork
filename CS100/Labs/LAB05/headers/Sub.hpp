#ifndef SUB_H
#define SUB_H

#include "../headers/Base.hpp"

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

#endif
