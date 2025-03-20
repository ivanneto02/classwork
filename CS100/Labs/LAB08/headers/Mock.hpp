#ifndef MOCK_H
#define MOCK_H

#include "Base.h"

class SevenOpMock : public Base {

	public:
		SevenOpMock() {}
	
		virtual double evaluate() override { return 7.5; }
		virtual string stringify() override { return "7.5"; }

		// Visitor lab overrides
        virtual int number_of_children() override { return 0; }
        virtual Base* get_child(int i) override { return nullptr; }

		virtual void accept(Visitor* v, int i) override {};
};

class ZeroOpMock : public Base {

	public:
		ZeroOpMock() {}
		
		virtual double evaluate() override { return 0.0; }
		virtual string stringify() override { return "0.0"; }

		// Visitor lab overrides
        virtual int number_of_children() override { return 0; }
        virtual Base* get_child(int i) override { return nullptr; }

		virtual void accept(Visitor* v, int i) override {};
};

class NegativeOpMock : public Base {

	public:
		NegativeOpMock() {}

		virtual double evaluate() override { return -1.0; }
		virtual string stringify() override { return "-1.0"; }

		// Visitor lab overrides
        virtual int number_of_children() override { return 0; }
        virtual Base* get_child(int i) override { return nullptr; }

		virtual void accept(Visitor* v, int i) override {};
};

#endif
