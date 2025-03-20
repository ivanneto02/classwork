#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {

	int value;
	IntNode* next;
	IntNode(int value) : value(value), next(nullptr) {};

};

class IntList {

	 private:
		IntNode* head;
		IntNode* tail;

	 public:
		// Constructors
		IntList();
		~IntList();
		IntList(const IntList&);

		// Mutators
		void push_front(int);
		void pop_front();
		void push_back(int);
		void clear();
		void selection_sort();
		void insert_ordered(int);
		void remove_duplicates();

		// Accessors
		bool empty() const;
		const int& front() const;
		const int& back() const;

		// Friends
		friend ostream& operator<<(ostream&, const IntList&);

		// Overloaded operators
		IntList& operator=(const IntList&);

};

#endif
