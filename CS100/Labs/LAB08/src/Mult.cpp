#include "../headers/Mult.hpp"

Mult::~Mult() {

	delete left;
	delete right;
}

Mult::Mult(Base* left, Base* right) {

    this->left = left;
    this->right = right;
}

double Mult::evaluate() {

    return this->left->evaluate() * this->right->evaluate();
}

std::string Mult::stringify() {

    std::ostringstream sout;

    sout << std::setprecision(2) << std::fixed
         << "(" << this->left->stringify()
         << " * "
         << this->right->stringify() << ")";

    return sout.str();
}

int Mult::number_of_children() {

	return 2;
}

Base* Mult::get_child(int i) {

	return (i == 0) ? this->left : this->right;
}

void Mult::accept(Visitor* v, int i) {
	switch(i) {
		case 0:
			v->visit_mult_begin(this);
			break;
		case 1:
			v->visit_mult_middle(this);
			break;
		case 2:
			v->visit_mult_end(this);
			break;
	}
}