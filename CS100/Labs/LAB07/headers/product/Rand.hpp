#ifndef RAND_H
#define RAND_H

#include <string.h>     // to_string 
#include <stdlib.h>     // srand, rand
#include <ctime>		// time 
#include "base.hpp"


class Rand : public Base {
	private:
		double val; // rand() % 100
	public:
		Rand();
		Rand(unsigned seed); 

		virtual double evaluate() override {return this -> val; }
		virtual std::string stringify() override; 

};

#endif
