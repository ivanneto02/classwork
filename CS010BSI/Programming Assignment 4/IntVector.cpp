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

// Private helpers

/// Expands the array's capacity by a factor of 2.
void IntVector::expand() {
	
	// In the case capacity is 0.
	if (this->_capacity == 0) {

		delete[] this->_data;
		
		this->_data = new int[1];

		this->_capacity = 1;
		
		return;

	}

	int* _tempData = new int[this->_capacity * 2];

	// Copies smaller array into bigger array.
	for (unsigned int i = 0; i < this->_size; i++) {
	
		_tempData[i] = this->_data[i];
	}
	
	// Deletes old data
	delete[] this->_data;

	// Copies new _tempData into brand new _data
	this->_data = new int[this->_capacity * 2];

	for (unsigned int i = 0; i < this->_size; i++) {

		this->_data[i] = _tempData[i];
	}

	// Increases capacity by twice itself
	this->_capacity *= 2;

	// Old data is no longer needed
	delete[] _tempData;

}

/// Expands the array's capacity by amount specified
void IntVector::expand(unsigned amount) {

	int* _tempData = new int[this->_capacity + amount];

	// Copies smaller array into bigger array.
	for (unsigned int i = 0; i <  this->_size; i++) {

		_tempData[i] = this->_data[i];

	}

	// Deletes old data
	delete[] this->_data;

	this->_data = new int[this->_capacity + amount];

	// Copies new _tempData into brand new _data
	for (unsigned int i = 0; i < this->_size; i++) {

		this->_data[i] = _tempData[i];
	}

	// Increases capacity by amount specified
	this->_capacity += amount;

	delete[] _tempData;

}

// End of private helpers

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

// Mutators

/// Finds the value located at the
/// specified index provided by the
/// user of this class.
int& IntVector::at(unsigned index) {
	
	// Range check
	if (index >= this->_size) {

		throw out_of_range("IntVector::at_range_check");
	}

	return this->_data[index];

}

/// Inserts a value provided by the
/// user of this class into an index
/// of the array also provided by the user.
void IntVector::insert(unsigned index, int value) {

	// Check for range
	if (index > this->size()) {

		throw out_of_range("IntVector::insert_range_check");
	}

	// Check for expansion
	if (this->_size + 1 > this->_capacity) {

		expand();
	}

	// Move everything to the right
	int temp[this->_capacity];

	for (unsigned int i = 0; i < this->_size; i++) {

		temp[i] = this->_data[i];
	}

	for (unsigned int i = index; i < this->_size; i++) {

		this->_data[i + 1] = temp[i];

	}

	// Copy value into array
	this->_data[index] = value;

	// Increment size by 1.
	this->_size += 1;
}

// Erases the value specified by the index
void IntVector::erase(unsigned index) {
	
	if (index >= this->_size) {

		throw out_of_range("IntVector::erase_range_check");
	}

	for (unsigned int i = index; i < this->_size; i++) {

		this->_data[i] = this->_data[i + 1];
	}

	this->_size -= 1;

}

int& IntVector::front() {

	return this->_data[0];
}

int& IntVector::back() {

	return this->_data[this->_size - 1];
}

/// Copies the specified n number of values value
/// Into a vector, modifying the size accordingly.
void IntVector::assign(unsigned n, int value) {

	// In case of out of range
	if (n > this->_capacity) {

		// Check for which capacity would be higher
		if (this->_capacity * 2 > this->_capacity + (n - this->_capacity)) {

			expand();
		}
		else {

			expand(n - this->_capacity);
		}

	}

	// Assign every value up to n in the array with the specified value
	for (unsigned int i = 0; i < n; i++) {

		this->_data[i] = value;
	}

	this->_size = n;

}

/// Places a specified value to the end of the vector and
/// increases size by 1.
void IntVector::push_back(int value) {
	
	// Check for expansion
	if (this->size() == this->capacity()) {

		expand();
	}

	// Assign value to the end of array
	this->_data[this->_size] = value;

	// Add one to size
	this->_size += 1;

}

void IntVector::pop_back() {

	this->_size -= 1;
}

void IntVector::clear() {

	this->_size = 0;
}

void IntVector::resize(unsigned size, int value) {
	
	// Check for redundancy of call
	if (size < this->_size) {
		
		this->_size = size;

		return;
	}

	// Check if size is greater than capacity
	if (size > this->_capacity) {

		if (size >= this->_capacity * 2) {
			
			expand(size - this->_capacity);
		}
		else {

			expand();
		}

	}

	// Assign new values
	for (unsigned int i = this->_size; i < size; i++) {
	
		this->_data[i] = value;
	}

	// Resize
	this->_size = size;

}

void IntVector::reserve(unsigned n) {

	// Check for redundancy
	if (n <= this->_capacity) {

		return;
	}

	// New dynamically allocated array
	int* _tempData = new int[n];

	// Copy data from old data into bigger tempData
	for (unsigned int i = 0; i < this->_size; i++) {

		_tempData[i] = this->_data[i];
	}

	// Delete old data
	delete[] _data;

	// Copy tempData into data
	this->_data = new int[n];

	for (unsigned int i = 0; i < this->_size; i++) {

		this->_data[i] = _tempData[i];
	}


	// Set capacity to n
	this->_capacity = n;
	
	// Delete temporary variable
	delete[] _tempData;

}

// End of mutators