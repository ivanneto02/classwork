#ifndef __OP_HPP__
#define __OP_HPP__

#include "Base.hpp"
#include <string>
#include <iomanip>

class Op : public Base {
        private:
	        double val;
	public:
                Op(double value) : Base(), val(value) { }
                virtual double evaluate() { return this->val; }
                virtual std::string stringify() {
                        std::ostringstream sout;

                        sout << std::setprecision(2) << std::fixed;
                        sout << "(" << this->val << ")";
                        return sout.str();
                }
};

#endif //__OP_HPP__
