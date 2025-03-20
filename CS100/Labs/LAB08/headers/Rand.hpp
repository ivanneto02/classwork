#ifndef RAND_H
#define RAND_H

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
		~Rand();

		// Old lab overrides
		virtual double evaluate() override {return this -> val; }
		virtual std::string stringify() override; 

		// Visitor lab overrides
        virtual int number_of_children() override;
        virtual Base* get_child(int i) override;

		virtual void accept(Visitor*, int) override;
};

#endif
