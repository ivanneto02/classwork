#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Essential function prototypes
void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

// Nonspecified function prototypes
void displayVctr(const vector<double>&, const vector<double>&);
bool isInVector(double, const vector<double>&);
double fetchValue(double, const vector<double>, const vector<double>);
void fetchInsertIndex(double, const vector<double>, int&, int&);

int main(int argc, char* argv[]) {

	// Variable definitions
	string filename = argv[1];

	string uAnswer;
	double flightAngle;

	// Vector definitions
	vector<double> flightAngles;
	vector<double> liftCoefficients;

	// Read data and store on vectors
	readData(filename, flightAngles, liftCoefficients);

	// Check order and order
	if (!isOrdered(flightAngles)) {
		reorder(flightAngles, liftCoefficients);
	}

	// Get flight-path angle
	cout << "Enter a flight-path angle: ";
	cin >> flightAngle;
	cout << endl;

	// Check for boundary
	if (isInVector(flightAngle, flightAngles)) {
		cout << "Lift coefficient: " << fetchValue(flightAngle, flightAngles, liftCoefficients) << endl;
	}
	else if ((flightAngle > flightAngles.at(0)) && (flightAngle < flightAngles.at(flightAngles.size() - 1))) {
		cout << "Lift coefficient: " << interpolation(flightAngle, flightAngles, liftCoefficients) << endl;
	}

	// Prompt user to input again
	cout << "Would you like to input another fligth path?: ";
	cin >> uAnswer;
	cout << endl;

	// Repeat until user types "No"
	while (uAnswer != "No") {

		if (uAnswer == "Yes") {
			cout << "Enter a flight-path angle: ";
			cin >> flightAngle;
			cout << endl;

			// Repeat process
			if (isInVector(flightAngle, flightAngles)) {
				cout << "Lift coefficient: " << fetchValue(flightAngle, flightAngles, liftCoefficients) << endl;
			}
			else if ((flightAngle > flightAngles.at(0)) && (flightAngle < flightAngles.at(flightAngles.size() - 1))) {
				cout << "Lift coefficient: " << interpolation(flightAngle, flightAngles, liftCoefficients) << endl;
			}

		}

		if (uAnswer == "No") {
			break;
		}

		cout << "Would you like to input another fligth path?: ";
		cin >> uAnswer;
		cout << endl;

	}

	return 0;
}

// Essential functions //

// This function stores the data from the files into vectors
void readData(const string& filename, vector<double>& angles, vector<double>& coeffs) {

	ifstream inFS;

	inFS.open(filename);

	// Check for errors
	if (!inFS.is_open()) {
		cout << "Error opening " << filename.c_str() << endl;
		exit(1);
	}
	
	// Fill vectors
	double currValue;
	int index = 0;

	while (inFS >> currValue) {

		if (inFS.fail()) {
			exit(1);
		}

		// Check if reading first or second value in file
		if (index % 2 == 0) {
			angles.push_back(currValue);
		}
		else {
			coeffs.push_back(currValue);
		}

		index++;

	}

}

// Computes interpolation for a new lift coefficient
double interpolation(double newAngle, const vector<double>& vctr1, const vector<double>& vctr2) {
	
	// Equation: f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))

	double newCoeff;

	double f_a;
	double f_c;
	double a;
	double b;
	double c;

	int index1;
	int index2;

	// Check if newAngle is inside of vctr1
	for (unsigned int i = 0; i < vctr1.size(); i++) {
		if (vctr1.at(i) == newAngle) {
			return vctr2.at(i);
		}
	}

	// Assign index1 and index2 with the indexes of the two angles
	// surrounding the newAngle
	fetchInsertIndex(newAngle, vctr1, index1, index2);

	f_a = vctr2.at(index1);
	f_c = vctr2.at(index2);
	a = vctr1.at(index1);
	b = newAngle;
	c = vctr1.at(index2);

	newCoeff = f_a + ((b - a) / ((c - a) * 1.0)) * (f_c - f_a);

	return newCoeff;

}

// Checks the order of the vector
bool isOrdered(const vector<double>& vctr) {
	unsigned int count = 0;

	if (vctr.size() == 0) {
		return true;
	}

	for (unsigned int i = 0; i < vctr.size() - 1; i++) {
		if (vctr.at(i) <= vctr.at(i + 1)) {
			count++;

		}
	}

	if (count == vctr.size() - 1) {
		return true;
	}

	return false;
}

// Make the vector ordered
void reorder(vector<double>& vctr1, vector<double>& vctr2) {
	double temp;

	for (unsigned int i = 0; i < vctr1.size(); i++) {

		for (unsigned int j = 0; j < vctr1.size() - 1; j++) {

			if ((vctr1.at(j) > vctr1.at(j + 1))) {

				// Switch for first fector
				temp = vctr1.at(j);
				vctr1.at(j) = vctr1.at(j + 1);
				vctr1.at(j + 1) = temp;

				// Switch for second vector
				temp = vctr2.at(j);
				vctr2.at(j) = vctr2.at(j + 1);
				vctr2.at(j + 1) = temp;
			}

		}

	}

}

// Nonspecified functions //

// Displays the vector for test purposes
void displayVctr(const vector<double>& vctr1, const vector<double>& vctr2) {

	cout << "Vector 1   Vector 2" << endl;
	for (unsigned int i = 0; i < vctr1.size(); i++) {
		cout << vctr1.at(i) << "       " << vctr2.at(i) << endl;
	}

}

// Checks if a given value is in a given vector.
bool isInVector(double value, const vector<double>& vctr) {

	// Iterate through vector, check if value is in vector
	for (unsigned int i = 0; i < vctr.size(); i++) {
		if (vctr.at(i) == value) {
			return true;
		}
	}

	return false;
}

// Gets the value from a vector that corresponds to another vector
double fetchValue(double value, const vector<double> vctr1, const vector<double> vctr2) {

	double fetch;

	// Iterate through, find index of value
	for (unsigned int i = 0; i < vctr1.size(); i++) {
		if (vctr1.at(i) == value) {
			fetch = vctr2.at(i);
		}
	}

	return fetch;
}

void fetchInsertIndex(double value, const vector<double> vctr, int& index1, int& index2) {

	// For value b, and current values a and c, find index such that a < b < c
	for (unsigned int i = 0; i < vctr.size() - 1; i++) {
		if ((vctr.at(i) < value) && (vctr.at(i + 1) > value)) {
			index1 = i;
			index2 = i + 1;
			return;
		}

	}

}