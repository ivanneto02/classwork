#include <iostream>
#include <vector>
using namespace std;

// Prototypes
void displayVectorByBound(const vector<int>&, int, int);
void populateVector(vector<int>&);

int main() {
   vector<int> integerVector;
   int NUM_ELEMENTS;
   int lowerBound;
   int upperBound;
   
   cin >> NUM_ELEMENTS;
   
   integerVector.resize(NUM_ELEMENTS); // Set vector size;

   // Call to fill vector with values
   populateVector(integerVector);
   
   // Define boundaries
   cin >> lowerBound >> upperBound;

   // Call to print values within range
   displayVectorByBound(integerVector, lowerBound, upperBound);

   return 0;
}

// Displays vector values within range
void displayVectorByBound(const vector<int>& vctr, int lowerBound, int upperBound) {
   for (unsigned int i = 0; i < vctr.size(); i++) {
      if ((vctr.at(i) >= lowerBound) && (vctr.at(i) <= upperBound)) {
         cout << vctr.at(i) << " ";   
      }
   }
   cout << endl;
}

// Fills the vector with values
void populateVector(vector<int>& vctr) {
   for (unsigned int i = 0; i < vctr.size(); i++) {
      cin >> vctr.at(i);
   }
}