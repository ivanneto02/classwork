#include "../headers/Rand.hpp"
// constructors 

Rand::~Rand() {
    delete this;
}

Rand::Rand() : Base() {
    srand(time(0));
    val = rand() % 100; 
} 

Rand::Rand(unsigned seed) : Base() {
    srand(seed);
    val = rand() % 100; 
} 

std::string Rand::stringify() {

    std::ostringstream sout;

    sout << std::setprecision(2) << std::fixed;
    sout << "(" << this->val << ")";
    return sout.str();

}

int Rand::number_of_children() {

	return 0;
}

Base* Rand::get_child(int i) {

	return nullptr;
}

void Rand::accept(Visitor* v, int i) {
	v->visit_rand(this);
}