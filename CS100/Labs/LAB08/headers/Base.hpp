#ifndef __BASE_HPP__
#define __BASE_HPP__

#include "visitor.hpp"

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

class Base {
    public:
        virtual ~Base() = default;

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;

        // Visitor lab pure virtual functions
        virtual int number_of_children() = 0;
        virtual Base* get_child(int i) = 0;
        
        virtual void accept(Visitor*, int) = 0;
};

#endif //__BASE_HPP__
