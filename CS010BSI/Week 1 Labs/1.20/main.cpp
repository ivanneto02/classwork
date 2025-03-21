// This program implements the Monte Carlo Method for estimating the value of PI.
#include <iostream>
#include <cstdlib>
#include <cmath>
   
using namespace std;

bool isInside(double, double, double);
bool throwDart(int);

int main() {
    srand(333);
    int side; // this is the side of the square and is also our resolution. 
    int tries;  // this is the number of tries.

    //Ask the user for the size (integer) of a side of the square
    cout << "Enter the length of a side of the square: ";

    //Get the users input using cin
    cin >> side;

    //Ask the user for the number of tries using cout.
    cout << "How many tries?: ";

    //Get the users input using cin.
    cin >> tries;

    int inCount = 0; //counter to track number of throws that fall inside the circle

    for(int i = 0; i < tries; ++i) {
        //throw a dart using throwDart method and increment the counter depending on its output.
        
        if (throwDart(side)) {
            inCount++;
        }
    }

    //Compute and display the estimated value of PI. Make sure you are not using integer division.

    double piEstimate = 4.0 * ((static_cast<double>(inCount)) / (static_cast<double>(tries)));
    cout << "The estimated value of pi is: " << piEstimate << endl;

    return 0;
}

// given the coordinates of a point (x,y) computes if the point is inside or on the circle 
// centered at origin with radius r. Returns 'true' if it is inside or on the circle, 'false' otherwise.
// DO NOT use the sqrt function here. Just compare to r squared.
bool isInside(double x, double y, double r) {
    return ((pow(x, 2) + pow(y, 2)) <= pow(r, 2));
}

// given s, the size of the side of a square that is centered at the origin, 
// chooses a random coordinates inside the square, and calls isInside function 
// to test if the point is inside the circle or not.
bool throwDart(int s) {
    int x, y;
    
    // assign x and y to two random integers between -s/2 and s/2 
    x = rand()%(s + 1) - (s/2.0);
    y = rand()%(s + 1) - (s/2.0);

    //Call the isInside function and return its output.
    return isInside(x, y, s/2);
    //You do not have to cast x & y to doubles, it is done automatically.
}