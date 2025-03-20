#include "../../headers/product/Pow.hpp"

#include <cmath>

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