#include "../headers/Add.hpp"

Add::~Add() {

	delete left;
	delete right;
}

// TODO check constructor
Add::Add(Base* left, Base* right) {
	
	// Assign data members
	this->left = left;
	this->right = right;
}

// TODO check
double Add::evaluate() {

	return this->left->evaluate() + this->right->evaluate();
}

// TODO check
std::string Add::stringify() {

	std::ostringstream sout;

	sout << std::setprecision(2) << std::fixed;
	sout << "(" << this->left->stringify()
		 << " + "
		 << this->right->stringify() << ")";

	return sout.str();
}

int Add::number_of_children() {
 
	return 2;
}

Base* Add::get_child(int i) {

	return (i == 0) ? this->left : this->right;
}

void Add::accept(Visitor* v, int i) {
	switch(i) {
		case 0:
			v->visit_add_begin(this);
			break;
		case 1:
			v->visit_add_middle(this);
			break;
		case 2:
			v->visit_add_end(this);
			break;
	}
}