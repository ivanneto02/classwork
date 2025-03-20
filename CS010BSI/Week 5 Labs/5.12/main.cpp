//include any standard libraries needed
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototypes
double mean(const double array[], int arraySize);
void remove(double array[], int &arraySize, int index);
void display(const double array[], int arraySize);

const int ARR_CAP = 100;

int main(int argc, char *argv[]) {

    ifstream inFS;

   // verify file name provided on command line
    string filename = argv[1];

   // open file and verify it opened
    inFS.open(filename);

    if (!inFS.is_open()) {

        cout << "Error opening the file " << filename << endl;
        return -1;
    }

   // Declare an array of doubles of size ARR_CAP.
    double doublesArray[ARR_CAP];
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
    double currNum;
    int i = 0;
    while (!inFS.eof()) {

        inFS >> currNum;

        if (inFS.fail()) {

            break;
        }

        doublesArray[i] = currNum;

        i++;
    }

   // Call the mean function passing it this array and output the 
   // value returned.
    cout << "Mean: " << mean(doublesArray, i) << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.

    int uIndex;
    cout << "Enter index of value to be removed (0 to " << i - 1 << "): " << endl;
    cin >> uIndex;
	
   // Call the display function to output the array.
    cout << "Before removing value: ";
    display(doublesArray, i);
    cout << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
    remove(doublesArray, i, uIndex);
  
   // Call the display function again to output the array
   // with the value removed.
    cout << "After removing value: ";
    display(doublesArray, i);
    cout << endl;
   
   // Call the mean function again to get the new mean
    cout << "Mean: " << mean(doublesArray, i) << endl;
   
	return 0;
}

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double myArray[], int arraySize) {

    double sum = 0;

    for (int i = 0; i < arraySize; i++) {

        sum += myArray[i];
    }

    return (sum / arraySize);
}


//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double myArray[], int& arraySize, int index) {

    for (int i = index; i < arraySize - 1; i++) {
        
        myArray[i] = myArray[i + 1];
    }

    arraySize--;
}

// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double myArray[], int arraySize) {

    for (int i = 0; i < arraySize; i++) {
        
        if (i == arraySize - 1) {

            cout << myArray[i];
            break;
        }

        cout << myArray[i] << ", ";
        
    }

}