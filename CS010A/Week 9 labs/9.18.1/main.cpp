#include <iostream>
#include <vector>
using namespace std;

// Prototypes
bool IsVectorEven(vector<int>);
bool IsVectorOdd(vector<int>);
void populateVector(vector<int>&);
void displayResult(const vector<int>&);

int main() {
    int NUM_ELEMENTS;
    vector<int> myVector;

    cin >> NUM_ELEMENTS;

    // Set vector size
    myVector.resize(NUM_ELEMENTS);

    populateVector(myVector);   // Call to fill vector with items
    displayResult(myVector);    // Call to display result

    return 0;
}

// Fill the vector with values
void populateVector(vector<int>& myVec) {
    for (unsigned int i = 0; i < myVec.size(); i++) {
        cin >> myVec.at(i);
    }
}

// Determine if vector is even
bool IsVectorEven(vector<int> myVec) {
    for (unsigned int i = 0; i < myVec.size(); i++) {
        if (!(myVec.at(i) % 2 == 0)) {
            return false;
        }
    }
    return true;
}

// Determine if vector is odd
bool IsVectorOdd(vector<int> myVec) {
    for (unsigned int i = 0; i < myVec.size(); i++) {
        if (myVec.at(i) % 2 == 0) {
            return false;
        }
    }
    return true;
}

// Display whether the vector is even, odd, or neither
void displayResult(const vector<int>& myVec) {
    if (IsVectorEven(myVec)) {
        cout << "all even" << endl;
    }
    else if (IsVectorOdd(myVec)) {
        cout << "all odd" << endl;
    }
    else {
        cout << "not even or odd" << endl;
    }
}