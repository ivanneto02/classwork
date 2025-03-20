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

        ~Div();

        // Old lab overrides
        virtual double evaluate() override;
        virtual std::string stringify() override;

        // Visitor lab overrides
        virtual int number_of_children() override;
        virtual Base* get_child(int i) override;

        virtual void accept(Visitor*, int) override;
};

#endif
