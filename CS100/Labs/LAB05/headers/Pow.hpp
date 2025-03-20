#ifndef POW_H
#define POW_H

#include "../headers/Base.hpp"

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

#endif
