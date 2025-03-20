#ifndef SUB_H
#define SUB_H

#include "Base.hpp"

class Sub : public Base {
    private:
        Base* left;
        Base* right;

    public:
        Sub();
        Sub(Base*, Base*);
        ~Sub();

        // Old lab overrides
        virtual double evaluate() override;
        virtual std::string stringify() override;

		// Visitor lab overrides
        virtual int number_of_children() override;
        virtual Base* get_child(int i) override;

        virtual void accept(Visitor*, int) override;
};

#endif
