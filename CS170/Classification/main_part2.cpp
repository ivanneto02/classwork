#include <iostream>
#include <string>

#include "./headers/ClassifierDriver.hpp"

int main() {

    ClassifierDriver* driver = new ClassifierDriver();
    driver->run();
    
    return 0;
}