#include "../headers/Add.hpp"

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