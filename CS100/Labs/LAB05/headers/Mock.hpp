#ifndef MOCK_H
#define MOCK_H

#include "Base.h"

class SevenOpMock : public Base {

	public:
		SevenOpMock() {}
	
		virtual double evaluate() { return 7.5; }
		virtual string stringify() { return "7.5"; }

};

class ZeroOpMock : public Base {

	public:
		ZeroOpMock() {}
		
		virtual double evaluate() { return 0.0; }
		virtual string stringify() { return "0.0"; }
};

class NegativeOpMock : public Base {

	public:
		NegativeOpMock() {}

		virtual double evaluate() { return -1.0; }
		virtual string stringify() { return "-1.0"; }
};

#endif
