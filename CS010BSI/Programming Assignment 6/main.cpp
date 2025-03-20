#include <iostream>

#include "SortedSet.h"

using namespace std;

int main() {

	int choice;
	cout << "(1) Test constructors" << endl
		 << "(2) Test mutators" << endl
		 << "(3) Test accessors" << endl
		 << "Enter your choice: ";
	cin >> choice;
	cout << endl;

	if (choice == 1) {

		IntList newList1;
		
		SortedSet newSet1 = SortedSet();
		cout << "New set initialized to empty" << endl;
		SortedSet newSet2 = SortedSet(newList1);
		cout << "New set initialized to an int list" << endl;
		SortedSet newSet3 = SortedSet(newSet1);
		cout << "New set initialized to previous set" << endl;
	}
	else if (choice == 2) {
		
		SortedSet newSet4 = SortedSet();

		cout << "add 1, push_back 2, push_front 3" << endl;
		newSet4.add(1);
		newSet4.push_back(2);
		newSet4.push_front(3);

		cout << "Set: " << newSet4 << endl;

		cout << "insert_ordered first, last, middle" << endl;

		newSet4.insert_ordered(0);
		newSet4.insert_ordered(7);
		newSet4.insert_ordered(5);

		cout << "Set: " << newSet4 << endl;

		cout << "Testing set = {0, 1, 2, 3, 5, 7} | {4, 6, 8, 9}" << endl;

		SortedSet newSet5 = SortedSet();

		newSet5.add(4);
		newSet5.add(6);
		newSet5.add(8);
		newSet5.add(9);

		newSet4 |= newSet5;

		cout << "Set: " << newSet4 << endl;

		cout << "Testing set = {0, 1, 2, 3, 5, 7} & {4, 6, 8, 9}" << endl;

		newSet4.clear();

		newSet4.add(1);
		newSet4.push_back(2);
		newSet4.push_front(3);
		newSet4.insert_ordered(0);
		newSet4.insert_ordered(7);
		newSet4.insert_ordered(5);

		newSet4 &= newSet5;

		cout << "Set: " << newSet4 << endl;

		cout << "Testing set = {0, 1, 2, 3, 4, 5} & {2, 3, 4, 6, 7, 8, 9}" << endl;

		SortedSet newSet6 = SortedSet();

		newSet6.add(0);
		newSet6.add(1);
		newSet6.add(2);
		newSet6.add(3);
		newSet6.add(4);
		newSet6.add(5);
		
		SortedSet newSet7 = SortedSet();

		newSet7.add(2);
		newSet7.add(3);
		newSet7.add(4);
		newSet7.add(6);
		newSet7.add(7);
		newSet7.add(8);
		newSet7.add(9);

		newSet6 &= newSet7;

		cout << "Set: " << newSet6 << endl;

	}
	else if (choice == 3) {
		
		cout << boolalpha << "in(0) for {0, 1, 2}" << endl;

		SortedSet newSet8 = SortedSet();

		newSet8.add(0);
		newSet8.add(1);
		newSet8.add(2);

		cout << "Result: " << newSet8.in(0) << endl;
		cout << "in(1) for {0, 1, 2}" << endl;
		cout << "Result: " << newSet8.in(1) << endl;
		cout << "in(2) for {0, 1, 2}" << endl;
		cout << "Result: " << newSet8.in(2) << endl;
		cout << "in(3) for {0, 1, 2}" << endl;
		cout << "Result: " << newSet8.in(3) << endl;
		cout << "in(-1) for {0, 1, 2}" << endl;
		cout << "Result: " << newSet8.in(-1) << endl;

		cout << "Testing set = {1, 2, 3} | {5, 6, 7}" << endl;

		SortedSet newSet9 = SortedSet();
		SortedSet newSet10 = SortedSet();

		newSet9.add(1);
		newSet9.add(2);
		newSet9.add(3);

		newSet10.add(5);
		newSet10.add(6);
		newSet10.add(7);

		SortedSet newSet11 = SortedSet();

		newSet11 = newSet9 | newSet10;

		cout << "Set: " << newSet11 << endl;

		cout << "Testing set = {1, 2, 3, 4, 5, 6} | {2, 3, 4, 5, 6, 7}" << endl;

		newSet9.clear();
		newSet10.clear();

		newSet9.add(1);
		newSet9.add(2);
		newSet9.add(3);
		newSet9.add(4);
		newSet9.add(5);
		newSet9.add(6);

		newSet10.add(2);
		newSet10.add(3);
		newSet10.add(4);
		newSet10.add(5);
		newSet10.add(6);
		newSet10.add(7);

		newSet11.clear();

		newSet11 = newSet9 & newSet10;

		cout << "Set: " << newSet11 << endl;
	}

	return 0;
}