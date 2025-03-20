#ifndef MULT_H
#define MULT_H

#include "Base.hpp"

class Mult : public Base {

    private:
        Base* left;
        Base* right;

    public:
        Mult();
        Mult(Base*, Base*);
        ~Mult();

        // Old lab overrides
        virtual double evaluate() override;
        virtual std::string stringify() override;

		// Visitor lab overrides
        virtual int number_of_children() override;
        virtual Base* get_child(int i) override;

        virtual void accept(Visitor*, int) override;
};

#endif