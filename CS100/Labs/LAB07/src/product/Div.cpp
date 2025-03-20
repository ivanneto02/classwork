#include "../headers/Div.hpp"

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