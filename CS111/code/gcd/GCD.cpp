#include "GCD.hpp"

int GCD::gcd() {

    if (a == 0) {

        return 0;
    }
    if (b == 0) {

        return 0;
    }

    return compute(this->a, this->b);
}

int GCD::compute(int a, int b) {

    if (a == b) {

        return a;
    }
    if (a < b) {

        int tmp = a;
        a = b;
        b = tmp;
    }
    return compute(a - b, b);
}