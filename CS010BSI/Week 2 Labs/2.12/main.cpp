
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream inFS; // Input stream
	ofstream outFS; // Output stream

	// Vector of ints
	vector<int> intVctr;

	// Variables
	string inputFile;
	string outputFile;
	int sum = 0;
	int intAverage;
	int count = 0;
   
	// Assign to inputFile value of 2nd command line argument
	inputFile = argv[1];

	// Assign to outputFile value of 3rd command line argument
	outputFile = argv[2];

	// Create input stream and open input csv file.
	inFS.open(inputFile);

	// Verify file opened correctly.
	// Output error message and return 1 if file stream did not open correctly.
	if (!inFS.is_open()) {
		cout << "Error opening " << inputFile << endl;
		exit(1);
	}

	// Read in integers from input file to vector.
	while (!inFS.eof()) {
		string tempStr;
		int tempInt;

		getline(inFS, tempStr, ',');

		if (inFS.fail()) {
			break;
		}

		tempInt = stoi(tempStr.c_str());

		intVctr.push_back(tempInt);

		sum += tempInt;
		count++;
	}

	// Close input stream.
	inFS.close();

	// Get integer average of all values read in.
	intAverage = (sum * 1.0) / count;

	// Convert each value within vector to be the difference between the original value and the average.
	for (unsigned int i = 0; i < intVctr.size(); i++) {
		intVctr.at(i) = intVctr.at(i) - intAverage;
	}

	// Create output stream and open/create output csv file.
	outFS.open(outputFile);

	// Verify file opened or was created correctly.
	// Output error message and return 1 if file stream did not open correctly.
	if (!outFS.is_open()) {
		cout << "Error opening " << outputFile << endl;
		exit(1);
	}

	// Write converted values into ouptut csv file, each integer separated by a comma.
	for (unsigned int i = 0; i < intVctr.size(); i++) {
		if (i == intVctr.size() - 1) {
			outFS << intVctr.at(i);
			break;
		}

		outFS << intVctr.at(i) << ",";
	}

	// Close output stream.
	outFS.close();
   
	return 0;
}
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	string inputFile;
	string outputFile;

	// Assign to inputFile value of 2nd command line argument
	inputFile = argv[1];
	// Assign to outputFile value of 3rd command line argument
	outputFile = argv[2];
	// Create input stream and open input csv file.
	ifstream infile;

	infile.open(inputFile);
	// Verify file opened correctly.
	// Output error message and return 1 if file stream did not open correctly.

	if (!infile.is_open()) {

		cout << "Error opening " << inputFile << endl;
		return 1;
	}

	// Read in integers from input file to vector.
	vector<int> numbers;

	string filenumbers;
	int tempnum;

	while (!infile.eof()) {

		getline(infile, filenumbers, ',');

		if (infile.fail()) {
			exit(1);
		}

		tempnum = stoi(filenumbers.c_str());

		numbers.push_back(tempnum);
	}

	// Close input stream.
	infile.close();

	// Get integer average of all values read in.
	int sum;
	int count;

	sum = 0;
	count = 0;

	for (unsigned int i = 0; i < numbers.size(); ++i) {
		sum = sum + numbers.at(i);
		++count;

	}

	int average;

	average = (sum * 1.0) / count;

	// Convert each value within vector to be the difference between the original value and the average.
	for (unsigned int i = 0; i < numbers.size(); i++) {

		numbers.at(i) = numbers.at(i) - average;

	}

	// Create output stream and open/create output csv file.

	ofstream outfile;

	outfile.open(outputFile);

	// Verify file opened or was created correctly.
	// Output error message and return 1 if file stream did not open correctly.
	if (!outfile.is_open()) {

		cout << "Error opening " << outputFile << endl;
		return 1;
	}

	// Write converted values into ouptut csv file, each integer separated by a comma.
	for (unsigned int i = 0; i < numbers.size(); ++i) {
		if (i < (numbers.size() - 1)) {
			outfile << numbers.at(i) << ",";
		}
		else {
			outfile << numbers.at(i);

		}
	}

	// Close output stream.
	outfile.close();
	return 0;
}