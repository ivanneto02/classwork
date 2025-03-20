#include "../headers/VisitorLaTeX.hpp"

#include "../headers/Base.hpp"
#include "../headers/Rand.hpp"
#include "../headers/Op.hpp"

void VisitorLaTeX::visit_op(Op* node) {

    std::ostringstream sout;

    sout << "{"
         << node->evaluate()
         << "}";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_rand(Rand* node) {

    std::ostringstream sout;

    sout << "{"
         << node->evaluate()
         << "}";
    
    this->finalExp += sout.str();
}

// Nodes with two children are visited three times.
// index = 0 -> begin
// index = 1 -> middle
// index = 2 -> end
void VisitorLaTeX::visit_add_begin(Add* node) {

    std::ostringstream sout;

    sout << "{(";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_add_middle(Add* node) {

    std::ostringstream sout;

    sout << "+";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_add_end(Add* node) {

    std::ostringstream sout;

    sout << ")}";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_sub_begin(Sub* node) {

    std::ostringstream sout;

    sout << "{(";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_sub_middle(Sub* node) {

    std::ostringstream sout;

    sout << "-";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_sub_end(Sub* node) {

    std::ostringstream sout;

    sout << ")}";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_mult_begin(Mult* node) {

    std::ostringstream sout;

    sout << "{(";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_mult_middle(Mult* node) {

    std::ostringstream sout;

    sout << "\\cdot";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_mult_end(Mult* node) {

    std::ostringstream sout;

    sout << ")}";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_div_begin(Div* node) {

    std::ostringstream sout;

    sout << "\\frac{";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_div_middle(Div* node) {

    std::ostringstream sout;

    sout << "}{";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_div_end(Div* node) {

    std::ostringstream sout;

    sout << "}";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_pow_begin(Pow* node) {

    std::ostringstream sout;

    sout << "{(";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_pow_middle(Pow* node) {

    std::ostringstream sout;

    sout << "^";

    this->finalExp += sout.str();
}

void VisitorLaTeX::visit_pow_end(Pow* node) {

    std::ostringstream sout;

    sout << ")}";

    this->finalExp += sout.str();
}