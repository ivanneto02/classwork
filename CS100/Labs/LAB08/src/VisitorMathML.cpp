#include "../headers/VisitorMathML.hpp"

#include "../headers/Base.hpp"
#include "../headers/Rand.hpp"
#include "../headers/Op.hpp"

VisitorMathML::VisitorMathML() {
    this->finalExp = "";
    this->currTab = "    ";
    this->tabSize = "    ";
}

void VisitorMathML::visit_op(Op* node) {

    std::ostringstream sout;

    sout << this->currTab << "<cn>"
         << node->evaluate()
         << "</cn>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_rand(Rand* node) {

    std::ostringstream sout;

    sout << this->currTab << "<cn>"
         << node->evaluate()
         << "</cn>\n";
    
    this->finalExp += sout.str();
}

// Nodes with two children are visited three times.
// index = 0 -> begin
// index = 1 -> middle
// index = 2 -> end
void VisitorMathML::visit_add_begin(Add* node) {

    std::ostringstream sout;

    sout << this->currTab << "<apply>\n";

    this->currTab += this->tabSize;

    sout << this->currTab << "<plus/>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_add_middle(Add* node) {

    return;
}

void VisitorMathML::visit_add_end(Add* node) {

    std::ostringstream sout;

    this->currTab = this->currTab.substr(0, this->currTab.length() - this->tabSize.size());

    sout << this->currTab << "</apply>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_sub_begin(Sub* node) {

    std::ostringstream sout;

    sout << this->currTab << "<apply>\n";

    this->currTab += this->tabSize;

    sout << this->currTab << "<minus/>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_sub_middle(Sub* node) {

    return;
}

void VisitorMathML::visit_sub_end(Sub* node) {

    std::ostringstream sout;

    this->currTab = this->currTab.substr(0, this->currTab.length() - this->tabSize.size());

    sout << this->currTab << "</apply>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_mult_begin(Mult* node) {

    std::ostringstream sout;

    sout << this->currTab << "<apply>\n";

    this->currTab += this->tabSize;

    sout << this->currTab << "<times/>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_mult_middle(Mult* node) {

    return;
}

void VisitorMathML::visit_mult_end(Mult* node) {

    std::ostringstream sout;

    this->currTab = this->currTab.substr(0, this->currTab.length() - this->tabSize.size());

    sout << this->currTab << "</apply>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_div_begin(Div* node) {

    std::ostringstream sout;

    sout << this->currTab << "<apply>\n";

    this->currTab += this->tabSize;

    sout << this->currTab << "<divide/>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_div_middle(Div* node) {

    return;
}

void VisitorMathML::visit_div_end(Div* node) {

    std::ostringstream sout;

    this->currTab = this->currTab.substr(0, this->currTab.length() - this->tabSize.size());

    sout << this->currTab << "</apply>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_pow_begin(Pow* node) {

    std::ostringstream sout;

    sout << this->currTab << "<apply>\n";

    this->currTab += this->tabSize;

    sout << this->currTab << "<power/>\n";

    this->finalExp += sout.str();
}

void VisitorMathML::visit_pow_middle(Pow* node) {

    return;
}

void VisitorMathML::visit_pow_end(Pow* node) {

    std::ostringstream sout;

    this->currTab = this->currTab.substr(0, this->currTab.length() - this->tabSize.size());

    sout << this->currTab << "</apply>\n";

    this->finalExp += sout.str();
}