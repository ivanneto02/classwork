#include "../headers/Pow.hpp"

#include <cmath>

Pow::~Pow() {

	delete left;
	delete right;
}

Pow::Pow(Base* left, Base* right) {

    this->left = left;
    this->right = right;
}

double Pow::evaluate() {

    return std::pow(this->left->evaluate(), this->right->evaluate());
}

std::string Pow::stringify() {

    std::ostringstream sout;
    
    sout << std::setprecision(2) << std::fixed
         << "(" << this->left->stringify()
         << " ** "
         << this->right->stringify() << ")";

    return sout.str();
}

int Pow::number_of_children() {

	return 2;
}

Base* Pow::get_child(int i) {

	return (i == 0) ? this->left : this->right;
}

void Pow::accept(Visitor* v, int i) {
	switch(i) {
		case 0:
			v->visit_pow_begin(this);
			break;
		case 1:
			v->visit_pow_middle(this);
			break;
		case 2:
			v->visit_pow_end(this);
			break;
	}
}