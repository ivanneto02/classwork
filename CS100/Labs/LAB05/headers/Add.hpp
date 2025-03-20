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

		virtual double evaluate();
		virtual std::string stringify();
};

#endif
