#include <iostream>
#include <vector> 
using namespace std;

// Prototypes
int GetMinimumInt(vector<int>);
void populateVector(vector<int>&);
void subtractValue(vector<int>&, int);
void displayVector(const vector<int>&);

int main() {
    int NUM_ELEMENTS;
    int minimumValue;
    vector<int> integerVector;

    cin >> NUM_ELEMENTS;

    // Set vector size
    integerVector.resize(NUM_ELEMENTS);

    populateVector(integerVector);                   // Call to fill vector with values

    minimumValue = GetMinimumInt(integerVector);    // Call minimum value function and set variable

    subtractValue(integerVector, minimumValue);     // Call to subtract values by minimum
    displayVector(integerVector);                   // Call to display final vector

    return 0;
}

// Fill vector with integer values
void populateVector(vector<int>& vctr) {
    for (unsigned int i = 0; i < vctr.size(); i++) {
        cin >> vctr.at(i);
    }
}

// Find minimum value in vector
int GetMinimumInt(vector<int> listInts) {
    int minimumInt = listInts.at(0);
    for (unsigned int i = 0; i < listInts.size(); i++) {
        if (listInts.at(i) <= minimumInt) {
            minimumInt = listInts.at(i);
        }
    }
    return minimumInt;
}

// Subtract every value with the minimum
void subtractValue(vector<int>& vctr, int min) {
    for (unsigned int i = 0; i < vctr.size(); i++) {
        vctr.at(i) = vctr.at(i) - min;
    }
}

// Display the vector
void displayVector(const vector<int>& vctr) {
    for (unsigned int i = 0; i < vctr.size(); i++) {
        cout << vctr.at(i) << " ";
    }
    cout << endl;
}