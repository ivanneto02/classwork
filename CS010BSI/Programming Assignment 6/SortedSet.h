#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"

class SortedSet : public IntList {

	public:
		
		// Constructors
		SortedSet();
		SortedSet(const SortedSet&);
		SortedSet(const IntList&);
		~SortedSet();

		// Mutators
		void add(int);
		void push_front(int);
		void push_back(int);
		void insert_ordered(int);
		SortedSet operator|=(const SortedSet&);
		SortedSet operator&=(const SortedSet&);

		// Accessors
		bool in(int value) const;
		SortedSet operator|(const SortedSet&);
		SortedSet operator&(const SortedSet&);

};

#endif