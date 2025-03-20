#include "stdio.h"

void test(int, double, char);

int main() {

    int hello = 10;

    test(10, 10.1, 'a');

    int x;

    if (hello == 10) {
        x = hello * 10;
    }
    else if (hello == 20) {
        x = hello * 20;
    }
    else {
        x = hello * 30;
    }

	printf("Hello world\n");

    return 0;
}

void test(int a, double b, char c) {
    double f = a * b;
    char d = c;
}
