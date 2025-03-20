#include "../headers/Sub.hpp"

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