#ifndef __ADD_HPP__
#define __ADD_HPP__

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

#endif  // __ADD_HPP__
