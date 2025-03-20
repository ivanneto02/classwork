#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string);

int main() {

	string filename;
	int sum = 0;

	// Take in filename
	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << endl;

	// Call filesum
	sum = fileSum(filename);

	// Output sum
	cout << "Sum: " << sum << endl;

	return 0;
}

// File sum function
int fileSum(string filename) {

	// Variable declarations
	ifstream inFS;
	int currentValue;
	int sum = 0;

	// Open file with file name
	inFS.open(filename);
	
	// Check if file was open successfully
	if (!inFS.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(-1);
	}

	// Read each line in the file
	while (!inFS.eof()) {

		inFS >> currentValue;

		if (inFS.fail()) {
			break;
		}

		sum += currentValue;
	}

	inFS.close();

	return sum;
}