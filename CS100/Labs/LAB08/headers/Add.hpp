#ifndef ADD_H
#define ADD_H

#include "Base.hpp"

class Add : public Base {

	private:
		Base* left;
		Base* right;

	public:
		Add();
		Add(Base*, Base*);
		~Add();

		// Old lab overrides
		virtual double evaluate() override;
		virtual std::string stringify() override;

		// Visitor lab overrides
        virtual int number_of_children() override;
        virtual Base* get_child(int i) override;

		virtual void accept(Visitor*, int) override;
};

#endif
