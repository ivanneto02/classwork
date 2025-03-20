#include <iostream>

#include "IntList.h"

using namespace std;

// Constructors / destructor

// Default constructor
IntList::IntList() {
	
	this->head = nullptr;
	this->tail = nullptr;

}

// Copy constructor FIXME
IntList::IntList(const IntList& toCopy) {

	// In the case that the copy list is empty
	if (toCopy.head == nullptr) {

		this->head = this->tail = nullptr;

		return;
	}

	// In the case that the copy list only has one element
	if (toCopy.head == toCopy.tail) {

		this->head = new IntNode(toCopy.head->value);
		this->tail = this->head;
		this->tail->next = nullptr;

		return;
	}

	// Traverse the linked list and copy each node
	IntNode* prev = nullptr;
	for (IntNode* curr = toCopy.head; curr != nullptr; curr = curr->next) {

		// In the case of the first nodes
		if (curr == toCopy.head) {

			IntNode* newNode = new IntNode(curr->value);
			this->head = newNode;
			prev = newNode;
			newNode->next = nullptr;

			continue;
		}

		// In the case of the middle nodes
		IntNode* newNode = new IntNode(curr->value);
		prev->next = newNode;
		newNode->next = nullptr;

		prev = prev->next;

	}

	this->tail = prev;

}

// Destructor
IntList::~IntList() {

	// Only iterate if head is not empty
	while (this->head != nullptr) {
		
		// Save head's next value
		IntNode* tmp = this->head->next;

		// Delete head
		delete this->head;

		// Move on to the next value
		this->head = tmp;
				
	}

}

// End of constructors / destructors

// Mutators

/// Inserts a value at the beginning of the linked list
void IntList::push_front(int value) {

	if (head != nullptr) {

		// Create new node
		IntNode* newNode = new IntNode(value);

		// New node's next is head
		newNode->next = this->head;

		// Head is new node
		this->head = newNode;

		return;

	}

	// If list is empty, both head and tail
	// point to one new node
	this->head = this->tail = new IntNode(value);

}

/// Removes the value from the front of the list
void IntList::pop_front() {
	
	// Check if list is not empty
	if (this->head != nullptr) {

		// In the case of one element
		if (this->head == this->tail) {

			// Deallocate
			delete this->head;

			// Both head and tail point to nothing
			this->head = this->tail = nullptr;

			return;
		}

		// Set tmp to head
		IntNode* tmp = this->head;

		// Head becomes next
		this->head = this->head->next;

		// Deletes tmp, or old head
		delete tmp;

	}

}

void IntList::push_back(int value) {

	// Check if list is empty
	if (this->head == nullptr) {

		this->head = new IntNode(value);
		this->tail = this->head;

		return;
	}

	// Allocate memory
	IntNode* newNode = new IntNode(value);

	// Insert at the end
	this->tail->next = newNode;
	this->tail = newNode;

}

/// Removes every element in the list
void IntList::clear() {

	// While there isn't only one element
	while (this->head != this->tail) {

		// Delete the node after
		IntNode* tmp = this->head;
		this->head = this->head->next;
		delete tmp;

	}
	
	// When only the last element is left

	delete this->head;

	this->head = this->tail = nullptr;

}

/// Sorts into ascending order
void IntList::selection_sort() {
	
	// Check if array is empty
	if (this->head == nullptr) {

		return;
	}

	// Iterate as long as there is a next value	
	for (IntNode* i = this->head; i != nullptr; i = i->next) {
		
		IntNode* minimum = i;

		// Nested iteration to find minimum value
		for (IntNode* j = i; j != nullptr; j = j->next) {

			// Find new minimum
			if (j->value < minimum->value) {

				minimum = j;

				continue;
			}
			
		}

		// Swap the integers
		int tmp = i->value;
		i->value = minimum->value;
		minimum->value = tmp;

	}

}

/// Inserts a data value in an ordered list
void IntList::insert_ordered(int value) {

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

/// Removes each duplicate element
void IntList::remove_duplicates() {

	// In the case the list is empty
	if (this->head == nullptr) {
	
		return;
	}

	// Iterate through each item
	IntNode* i = this->head;
	while (i != nullptr) {

		// Further iterate to find duplicates
		IntNode* p = i;
		IntNode* c = p->next;
		while (c != nullptr) {

			// If match is found
			if (i->value == c->value) {

				// In the case of the last element
				if (c->next == nullptr) {
					
					IntNode* tmp = c;
					p->next = nullptr;
					this->tail = p;
					delete tmp;

					break;
				}
				
				// In the case of an intermediate node
				IntNode* tmp = c;
				p->next = p->next->next;
				c = p->next;
				delete tmp;

				continue;
			}

			// Move to the next line
			p = p->next;
			c = p->next;

		}

		i = i->next;
	}

}

// End of mutators

// Accessors

/// Determine whether list is empty
bool IntList::empty() const {

	return (this->head == nullptr);
}

/// Returns the value of the first node
const int& IntList::front() const {

	return (this->head->value);
}

/// Returns the value of the last node
const int& IntList::back() const {

	return (this->tail->value);
}

// End of accessors

// Overloaded operators

/// Copy assignment operator
IntList& IntList::operator=(const IntList& currList) {

	// Only execute if the objects are not the same
	if (this != &currList) {
		
		// Empty list in  the case it is not empty to begin with.
		this->clear();

		// In the case that the list is empty
		if (currList.head == nullptr) {

			return *this;
		}

		// In the case that there is just one node
		if (currList.head == currList.tail) {

			this->push_back(currList.head->value);

			return *this;
		}
		
		// In the case where there are many nodes
		IntNode* curr = currList.head;
		while (curr != nullptr) {

			this->push_back(curr->value);
			curr = curr->next;
		}

	}

	return *this;
}

// End of overloaded operators

// Global functions

/// Compatibilizes the IntList class with the cout ostream function
ostream& operator<<(ostream& out, const IntList& currList) {

	IntNode* curr = currList.head;

	// While head exists in currList
	while (curr != nullptr) {
		
		// At the end of the list
		if (curr->next == nullptr) {
			
			out << curr->value;
			curr = curr->next;

			continue;
		}

		// Output the head and move on to the next value
		out << curr->value << " ";
		curr = curr->next;

	}

	return out;
}

// End of global functions

// Helper functions
 
IntNode* min(IntNode*) {

	return nullptr;
}

void copy(const IntList&) {

	return;
}

// End of helper functions