#include "../headers/Sub.hpp"

Sub::~Sub() {
	delete left;
	delete right;
}

Sub::Sub(Base* left, Base* right) {

    this->left = left;
    this->right = right;
}

double Sub::evaluate() {

    return this->left->evaluate() - this->right->evaluate();
}

std::string Sub::stringify() {

    std::ostringstream sout;

    sout << std::setprecision(2) << std::fixed
         << "(" << this->left->stringify()
         << " - "
         << this->right->stringify() << ")";

    return sout.str();
}

int Sub::number_of_children() {

	return 2;
}

Base* Sub::get_child(int i) {

	return (i == 0) ? this->left : this->right;
}

void Sub::accept(Visitor* v, int i) {
	switch(i) {
		case 0:
			v->visit_sub_begin(this);
			break;
		case 1:
			v->visit_sub_middle(this);
			break;
		case 2:
			v->visit_sub_end(this);
			break;
	}
}