#include <iostream>

#include "IntVector.h"

using namespace std;

int main() {

	/*
	cout << "For vector 1: " << endl << endl;
	IntVector v1;
	
	for (unsigned int i = 0; i < v1.size(); i++) {

		cout << v1.at(i) << " ";
	}

	cout << "size: " << v1.size() << endl
		 << "capacity: " << v1.capacity() << endl
		 << "empty: " << v1.empty() << endl
		 << "front: " << v1.front() << endl
		 << "back: " << v1.back() << endl;
	*/

	cout << "For vector 2: " << endl << endl;
	IntVector v2(10);

	for (unsigned int i = 0; i < v2.size(); i++) {

		cout << v2.at(i) << " ";
	}

	cout << "size: " << v2.size() << endl
		<< "capacity: " << v2.capacity() << endl
		<< "empty: " << v2.empty() << endl
		<< "at 5: " << v2.at(5) << endl
		<< "front: " << v2.front() << endl
		<< "back: " << v2.back() << endl;

	cout << "For vector 3: " << endl << endl;
	IntVector v3(15, 5);

	for (unsigned int i = 0; i < v3.size(); i++) {

		cout << v3.at(i) << " ";
	}

	cout << "size: " << v3.size() << endl
		<< "capacity: " << v3.capacity() << endl
		<< "empty: " << v3.empty() << endl
		<< "at 5: " << v3.at(5) << endl
		<< "front: " << v3.front() << endl
		<< "back: " << v3.back() << endl;

	return 0;
}