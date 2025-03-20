#include "../../headers/product/Rand.hpp"
// constructors 
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
