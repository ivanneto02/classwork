#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <string.h>     // to_string 
#include <stdlib.h>     // srand, rand
#include <ctime>		// time 
#include "Base.hpp"


class Rand : public Base {
	private:
		double val; // rand() % 100
	public:
		Rand();
		Rand(unsigned seed); 

		virtual double evaluate() override {return this -> val; }
		virtual std::string stringify() override; 

};

#endif  // __RAND_HPP__
