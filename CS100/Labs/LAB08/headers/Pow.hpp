#ifndef POW_H
#define POW_H

#include "Base.hpp"

class Pow : public Base {

    private:
        Base* left;
        Base* right;

    public:
        Pow();
        Pow(Base*, Base*);
        ~Pow();

        // Old lab overrides
        virtual double evaluate() override;
        virtual std::string stringify() override;

        // Visitor lab overrides
        virtual int number_of_children() override;
        virtual Base* get_child(int i) override;

        virtual void accept(Visitor*, int) override;
};

#endif
