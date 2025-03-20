#ifndef __OP_HPP__
#define __OP_HPP__

#include "Base.hpp"
#include <string>
#include <iomanip>

class Op : public Base {

        private:
	        double val;
	public:
                Op();
                Op(double value) : Base(), val(value) { }

                // Old lab overrides
                virtual double evaluate() { return this->val; }
                virtual std::string stringify() {
                        std::ostringstream sout;

                        sout << std::setprecision(2) << std::fixed;
                        sout << "(" << this->val << ")";
                        return sout.str();
                }

                // Visitor lab overrides
                virtual int number_of_children() override { return 0; }
                virtual Base* get_child(int i) override { return nullptr; }

                virtual void accept(Visitor* v, int i) override {
                        v->visit_op(this);
                };
};

#endif //__OP_HPP__
