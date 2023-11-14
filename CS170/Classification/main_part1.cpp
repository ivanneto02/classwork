#include <iostream>
#include <string>

#include "./headers/Driver.hpp"

/*
This was an old iteration of main() only needed for part1. I will leave it here
just in case I need to do some testing later.
*/
int main() {
    std::cout << "Running application..." << std::endl;
    Driver* myDriver = new Driver();
    myDriver->run();
    std::cout << "Done running application..." << std::endl;
    return 0;
}