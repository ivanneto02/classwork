#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include <iomanip>
#include <sstream>

class Base{

    public:
        /* Constructors */
        Base() { }

        virtual ~Base() {}

        /* Pure virtual functions */
        virtual double evaluate() = 0;
        virtual std::strirng stringify() = 0;
};

#endif