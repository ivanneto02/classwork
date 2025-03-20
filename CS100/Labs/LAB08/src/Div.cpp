#include "../headers/Div.hpp"

Div::~Div() {
	delete left;
	delete right;
}

Div::Div(Base* left, Base* right) {

    this->left = left;
    this->right = right;
}

double Div::evaluate() {

    return this->left->evaluate() / this->right->evaluate();
}

std::string Div::stringify() {

    std::ostringstream sout;

    sout << std::setprecision(2) << std::fixed
         << "(" << this->left->stringify()
         << " / "
         << this->right->stringify() << ")";
    
    return sout.str();
}

int Div::number_of_children() {

	return 2;
}

Base* Div::get_child(int i) {

	return (i == 0) ? this->left : this->right;
}

void Div::accept(Visitor* v, int i) {
	switch(i) {
		case 0:
			v->visit_div_begin(this);
			break;
		case 1:
			v->visit_div_middle(this);
			break;
		case 2:
			v->visit_div_end(this);
			break;
	}
}