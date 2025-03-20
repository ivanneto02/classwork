#include <iostream>
#include <stdexcept>

#include "IntVector.h"

using namespace std;

// Constructors

IntVector::IntVector(unsigned capacity, int value) {

	this->_capacity = capacity;
	this->_size = capacity;

	if (this->_capacity > 0) {

		this->_data = new int[_capacity];


		for (unsigned i = 0; i < _capacity; i++) {

			_data[i] = value;
		}

	}
	else {

		this->_data = nullptr;
	}

}

// Destructor
IntVector::~IntVector() {

	delete[] this->_data;
}

// End of constructor

// Accessors

// Returns the size of the vector
unsigned IntVector::size() const {

	return this->_size;
}

// Returns the capacity of the vector
unsigned IntVector::capacity() const {

	return this->_capacity;
}

// Identifies whether the vector is empty and has no values
bool IntVector::empty() const {

	if (this->_size == 0) {

		return true;
	}

	return false;
}

// Returns the address of the value at index
const int& IntVector::at(unsigned index) const {

	if (index >= this->_size) {

		throw out_of_range("IntVector::at_range_check");
	}

	return this->_data[index];
}

// Returns the value at the front of the vector
const int& IntVector::front() const {
		
	return this->_data[0];
}

// Returns the value at the back of the vector
const int& IntVector::back() const {

	return this->_data[this->_size - 1];
}

// End of accessors