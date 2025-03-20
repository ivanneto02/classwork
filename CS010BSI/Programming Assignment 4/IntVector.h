#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector {

	private:

		// Private data members
		unsigned _size;
		unsigned _capacity;

		// Stores a dynamically-allocated array of ints
		int* _data;

		// Helper functions
		void expand();
		void expand(unsigned);

	public:

		// Constructors / Destructors
		IntVector(unsigned capacity = 0, int value = 0);
		~IntVector();

		// Accessors
		unsigned size() const;
		unsigned capacity() const;
		bool empty() const;
		const int& at(unsigned) const;
		const int& front() const;
		const int& back() const;

		// Mutators
		int& at(unsigned);
		void insert(unsigned, int);
		void erase(unsigned);
		int& front();
		int& back();
		void assign(unsigned, int);
		void push_back(int);
		void pop_back();
		void clear();
		void resize(unsigned, int value = 0);
		void reserve(unsigned);
};

#endif