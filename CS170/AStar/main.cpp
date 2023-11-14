#include <iostream>

#include "./headers/GameDriver.hpp"

using namespace std;

int main() {

    GameDriver* myDriver = new GameDriver();

    myDriver->beginGame();

    return 0;
}