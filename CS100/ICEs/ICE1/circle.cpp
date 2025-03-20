#include "circle.hpp"
#include <cmath>

double Circle::area() const {

    if (this->radius < 0) {
        return -1.0;
    }

    return M_PI * this->radius * this->radius;
}

double Circle::perimeter() const {

    if (this->radius < 0) {
        return -1.0;
    }

    return 2 * M_PI * this->radius;
}