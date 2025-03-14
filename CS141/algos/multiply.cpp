#include <iostream>

int multiply(int x, int y) {
    
    if (y == 0) {
        return 0;
    }

    int z = multiply(x, y / 2);
    if (y % 2 == 0) {
        std::cout << y << " " << x << " " << 2*z << std::endl;
        return 2*z;
    }
    else {
        std::cout << y << " " << x << " " << x + 2*z << std::endl;
        return x + 2*z;
    }

}

int main() {

    int result = multiply(50, 100);
    std::cout << result << std::endl;

    return 0;
}