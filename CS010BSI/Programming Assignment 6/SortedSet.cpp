#include <iostream>

#include "SortedSet.h"

using namespace std;

// Constructors

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet& currSet) :

	IntList(currSet)
{}

SortedSet::SortedSet(const IntList& currSet) :

	IntList(currSet)
{
	remove_duplicates();
	selection_sort();
}

SortedSet::~SortedSet() {

	return;

	cout << "Destructor: FIXME" << endl;
}

// End of constructors

// Mutators

void SortedSet::add(int value) {

	this->insert_ordered(value);
}

void SortedSet::push_front(int value) {

	this->insert_ordered(value);
}

void SortedSet::push_back(int value) {

	this->insert_ordered(value);
}

void SortedSet::insert_ordered(int value) {

	if (this->in(value)) {

		return;
	}

	// In the case that the list is empty
	if (this->head == nullptr) {

		this->head = new IntNode(value);
		this->tail = this->head;

		return;
	}

	// In the case that insert position is beginning
	if (value <= this->head->value) {
		
		IntNode* newNode = new IntNode(value);
		newNode->next = this->head;
		this->head = newNode;

		return;
	}

	// In the case that insert position is end
	if (value >= this->tail->value) {

		IntNode* newNode = new IntNode(value);
		this->tail->next = newNode;
		this->tail = newNode;

		return;
	}

	// Iterate through each item to find insert spot
	for (IntNode* i = this->head; i != nullptr; i = i->next) {

		// Check if condition fits to insert
		if ((i->value <= value) && (i->next->value >= value)) {
		
			// Insert node
			IntNode* newNode = new IntNode(value);
			newNode->next = i->next;
			i->next = newNode;

			break;
		}

	}
	
}

SortedSet SortedSet::operator|=(const SortedSet& rightSet) {

	SortedSet newSet = SortedSet(rightSet);

	for (IntNode* curr = this->head; curr != nullptr; curr = curr->next) {

		newSet.insert_ordered(curr->value);
	}

	this->clear();

	*this = newSet;

	return *this;
}

SortedSet SortedSet::operator&=(const SortedSet& rightSet) {

	SortedSet newSet = SortedSet();

	for (IntNode* curr = this->head; curr != nullptr; curr = curr->next) {

		if (this->in(curr->value) && rightSet.in(curr->value)) {

			newSet.insert_ordered(curr->value);
		}

	}

	this->clear();

	*this = newSet;

	return *this;
}

// End of mutators

// Accessors

bool SortedSet::in(int value) const {
	
	if (this->head == nullptr) {

		return false;
	}

	for (IntNode* curr = this->head; curr != nullptr; curr = curr->next) {

		if (curr->value == value) {

			return true;
		}

	}

	return false;
}

SortedSet SortedSet::operator|(const SortedSet& rightSet) {

	SortedSet newSet = SortedSet(rightSet);

	for (IntNode* curr = this->head; curr != nullptr; curr = curr->next) {

		newSet.insert_ordered(curr->value);
	}

	return newSet;
}

SortedSet SortedSet::operator&(const SortedSet& rightSet) {
	
	SortedSet newSet = SortedSet();
	
	for (IntNode* curr = this->head; curr != nullptr; curr = curr->next) {

		if (this->in(curr->value) && rightSet.in(curr->value)) {
			
			newSet.add(curr->value);
		}
	}

	return newSet;
}

// End of accessors