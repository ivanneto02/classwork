#include <iostream>
#include <vector>
using namespace std;

// Prototypes
void populateVector(vector<int>&);
void sortVector(vector<int>&);
void displayTwoSmallest(const vector<int>& vctr);

int main() {
	
   int NUM_ELEMENTS;
   
   vector<int> integerVector;
   
   cin >> NUM_ELEMENTS;
   
   // Set vector size
   integerVector.resize(NUM_ELEMENTS);
   
   populateVector(integerVector);      // Call to fill vector
   sortVector(integerVector);          // Call to sort vector
   displayTwoSmallest(integerVector);  // Call to display vector

   return 0;
}

// Fill vector with values
void populateVector(vector<int>& vctr) {
   for (unsigned int i = 0; i < vctr.size(); i++) {
      cin >> vctr.at(i);
   }
}

// Sort vector algorithm
void sortVector(vector<int>& vctr) {
   int temp;
   for (unsigned int i = 0; i < vctr.size(); i++) {
      for (unsigned int j = 0; j < vctr.size() - 1; j++) {
         if (vctr.at(j) < vctr.at(j + 1)) {
            temp = vctr.at(j);
            vctr.at(j) = vctr.at(j + 1);
            vctr.at(j + 1) = temp;
         }
      }
   }
   
   
   for (unsigned int i = 0; i < vctr.size(); i++) {
		
		cout << vctr.at(i) << " ";
   }
   cout << endl;
   
}

// Display two smallest values
void displayTwoSmallest(const vector<int>& vctr) {
    int lastIndex = vctr.size() - 1;
    for (unsigned int i = 1; i < vctr.size(); i++) {
        if (vctr.at(lastIndex - i) > vctr.at(lastIndex)) {
            cout << vctr.at(lastIndex) << " " << vctr.at(lastIndex - i) << endl;
            return;
        }
    }
    cout << vctr.at(lastIndex) << " " << vctr.at(lastIndex) << endl;
}