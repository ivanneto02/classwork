#include "../../headers/product/Mult.hpp"

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