#include <iostream>

#include "IntVector.h"

using namespace std;

void displayVctr(const IntVector&);

int main() {

	cout << "Starting unit test for vector of 5 4's:" << endl;
	IntVector myVector(5, 4);

	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;
	
	displayVctr(myVector);

	cout << "Front: " << myVector.front() << endl;
	cout << "Back: " << myVector.back() << endl; 

	cout << endl << endl << "Insert 5 at 0:" << endl;
	myVector.insert(0, 5);
	myVector.insert(myVector.size() - 1, 5);

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "Push back 6, 7, 8, 9:" << endl;
	myVector.push_back(6);
	myVector.push_back(7);
	myVector.push_back(8);
	myVector.push_back(9);

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "Pop back:" << endl;
	myVector.pop_back();

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "Clear vector:" << endl;
	myVector.clear();

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "Push back 1, 1:" << endl;
	myVector.push_back(1);
	myVector.push_back(1);

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "Erase index 0:" << endl;
	myVector.erase(0);

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "Assign 10, 5:" << endl;
	myVector.assign(10, 5);

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "Reserve 30:" << endl;
	myVector.reserve(30);

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "Resize:" << endl;
	myVector.resize(5);

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "Resize:" << endl;
	myVector.resize(10, 10);

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;


	cout << endl << endl << "Insert at 0, at end, and middle:" << endl;
	myVector.insert(0, 20);
	myVector.insert(myVector.size(), 20);
	myVector.insert(3, 20);

	displayVctr(myVector);
	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;

	cout << endl << endl << "New vector: " << endl;

	IntVector myVector2;
	cout << "Size: " << myVector2.size() << endl;
	cout << "Capacity: " << myVector2.capacity() << endl;

	cout << endl << endl << "Insert new value at 0: " << endl;
	myVector2.insert(0, 430);

	displayVctr(myVector2);
	cout << "Size: " << myVector2.size() << endl;
	cout << "Capacity: " << myVector2.capacity() << endl;

	myVector2.insert(0, 1);
	displayVctr(myVector2);
	cout << "Size: " << myVector2.size() << endl;
	cout << "Capacity: " << myVector2.capacity() << endl;

	IntVector specVector;

	specVector.push_back(1);

	displayVctr(specVector);
	cout << "Size: " << specVector.size() << endl;
	cout << "Capacity: " << specVector.capacity() << endl;

	specVector.reserve(5);

	displayVctr(specVector);
	cout << "Size: " << specVector.size() << endl;
	cout << "Capacity: " << specVector.capacity() << endl;

	specVector.reserve(1);

	displayVctr(specVector);
	cout << "Size: " << specVector.size() << endl;
	cout << "Capacity: " << specVector.capacity() << endl;

	specVector.resize(6, 0);

	displayVctr(specVector);
	cout << "Size: " << specVector.size() << endl;
	cout << "Capacity: " << specVector.capacity() << endl;


	IntVector specVector2(49);

	displayVctr(specVector2);
	cout << "Size: " << specVector2.size() << endl;
	cout << "Capacity: " << specVector2.capacity() << endl;

	specVector2.resize(100);

	displayVctr(specVector2);
	cout << "Size: " << specVector2.size() << endl;
	cout << "Capacity: " << specVector2.capacity() << endl;

	IntVector specVector3(25, 1);

	specVector3.resize(100, 5);

	displayVctr(specVector3);
	cout << "Size: " << specVector3.size() << endl;
	cout << "Capacity: " << specVector3.capacity() << endl;

	return 0;
}

void displayVctr(const IntVector& myVector) {

	if (myVector.size() == 0) {

		cout << "Vector: EMPTY" << endl;
		return;
	}

	cout << "Vector: ";
	for (unsigned int i = 0; i < myVector.size(); i++) {

		cout << myVector.at(i) << " ";
	}
	cout << endl;

}