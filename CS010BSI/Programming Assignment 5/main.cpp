#include "IntList.h"

#include <iostream>
using namespace std;

int main() {


   cout << "Enter a test number(1-6): ";
	int test;
	cin >> test;
	cout << endl;
   //tests constructor, destructor, push_front, pop_front, display
   if (test == 1) {
      cout << endl;
      cout << "list1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
   }
   if (test == 1) {
      cout << "list1 destructor called" << endl;
   }

   //tests push_back
   if (test == 2) {
      cout << endl;
      cout << "list2 constructor called" << endl;
      IntList list2;
      cout << "pushback 10" << endl;
      list2.push_back(10);
      cout << "pushback 20" << endl;
      list2.push_back(20);
      cout << "pushback 30" << endl;
      list2.push_back(30);
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
   }
   if (test == 2) {
      cout << "list2 destructor called" << endl;
   }

   //tests selection_sort
   if (test == 3) {
      cout << endl;
      cout << "list3 constructor called" << endl;
      IntList list3;
      cout << "pushfront 10" << endl;
      list3.push_front(10);
      cout << "pushfront 20" << endl;
      list3.push_front(20);
      cout << "pushfront 30" << endl;
      list3.push_front(30);
      cout << "list3: " << list3 << endl;
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
      cout << "pop" << endl;
      list3.pop_front();
      cout << "pop" << endl;
      list3.pop_front();
      cout << "pop" << endl;
      list3.pop_front();
      cout << "list3: " << list3 << endl;
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
      cout << "pushfront 10" << endl;
      list3.push_front(10);
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
      cout << "pushfront 20" << endl;
      list3.push_front(20);
      cout << "list3: " << list3 << endl;
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
   }
   if (test == 3) {
      cout << "list3 destructor called" << endl;
   }

   //tests insert_sorted
   if (test == 4) {
      cout << endl;
      cout << "list4 constructor called" << endl;
      IntList list4;
      cout << "insert 20" << endl;
      list4.insert_ordered(20);
      cout << "insert 10" << endl;
      list4.insert_ordered(10);
      cout << "insert 30" << endl;
      list4.insert_ordered(30);
      cout << "list4: " << list4 << endl;
      cout << "insert 50" << endl;
      list4.insert_ordered(50);
      cout << "list4: " << list4 << endl;
      cout << "insert 40" << endl;
      list4.insert_ordered(40);
      cout << "list4: " << list4 << endl;
      cout << "insert 11" << endl;
      list4.insert_ordered(11);
      cout << "list4: " << list4 << endl;
      cout << "insert 10" << endl;
      list4.insert_ordered(10);
      cout << "list4: " << list4 << endl;
      cout << "insert 11" << endl;
      list4.insert_ordered(11);
      cout << "list4: " << list4 << endl;
      cout << "insert 9" << endl;
      list4.insert_ordered(9);
      cout << "list4: " << list4 << endl;
      cout << "insert 50" << endl;
      list4.insert_ordered(50);
      cout << "list4: " << list4 << endl;
      cout << "insert 51" << endl;
      list4.insert_ordered(51);
      cout << "list4: " << list4 << endl;
   }
   if (test == 4) {
      cout << "list4 destructor called" << endl;
   }
   
   //tests remove_duplicates
   if (test == 5) {
      cout << endl;
      cout << "list5 constructor called" << endl;
      IntList list5;
      cout << "pushfront 10" << endl;
      list5.push_front(10);
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "pushfront 10" << endl;
      list5.push_front(10);
      cout << "pushfront 30" << endl;
      list5.push_front(30);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 10" << endl;
      list5.push_front(10);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pop" << endl;
      list5.pop_front();
      cout << "pop" << endl;
      list5.pop_front();
      cout << "push_front(30)" << endl;
      list5.push_front(30);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "push_front(30)" << endl;
      list5.push_front(30);
      cout << "push_front(30)" << endl;
      list5.push_front(30);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pop" << endl;
      list5.pop_front();
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
   }
   if (test == 5) {
      cout << "list5 destructor called" << endl;
   }

   /*
   * Destructor will be tested by looking at code. There is no run-time 
   * test for it. Make sure your destructor actually deletes ALL nodes, not
   * just the head and/or tail.
   */
   
   if (test == 6) {
        
        IntList newList;

        // Tests assignment copy operator
        cout << "push back 1" << endl;
        newList.push_back(1);

        cout << "push back 2" << endl;
        newList.push_back(2);

        cout << "push back 3" << endl;
        newList.push_back(3);

        cout << "push back 4" << endl;
        newList.push_back(4);

        cout << "Testing copy constructor..." << endl;
       
        cout << "  testing {1}" << endl;
        IntList newList1;
        newList1.push_back(1);
        IntList testList = newList1;

        cout << "Vector: " << endl;
        cout << testList << endl;

        cout << "  testing {}" << endl;
        IntList newList2;
        IntList testList1 = newList2;

        cout << "Vector: " << endl;
        cout << testList1 << endl;

        cout << "  testing {1, 2, 3, 4}" << endl;
        IntList newList3;
        newList3.push_back(1);
        newList3.push_back(2);
        newList3.push_back(3);
        newList3.push_back(4);
        IntList testList2 = newList3;

        cout << "Vector: " << endl;
        cout << testList2 << endl;

        cout << "  testing {1, 2}" << endl;
        IntList newList4;
        newList4.push_back(1);
        newList4.push_back(2);
        IntList testList3 = newList4;

        cout << testList3 << endl;

        cout << "  testing big list 1-49" << endl;

        IntList newList5;
        for (int i = 1; i < 50; i++) {

            newList5.push_back(i);
        }
        IntList testList4 = newList5;

        cout << "Vector: " << endl;
        cout << testList4 << endl;

        cout << endl << endl;
        cout << "Testing copy assignment operator..." << endl;

        cout << "  testing {}" << endl;
        IntList copyTestList;
        IntList copyTestListPair;
        copyTestListPair = copyTestList;

        cout << "Vector: " << endl;
        cout << copyTestListPair << endl;
        
        cout << "  testing {1}" << endl;
        IntList copyTestList1;
        copyTestList1.push_back(1);
        IntList copyTestListPair1;
        copyTestListPair1 = copyTestList1;

        cout << "Vector: " << endl;
        cout << copyTestListPair1 << endl;

        cout << "  testing {1, 2, 3, 4}" << endl;
        IntList copyTestList2;
        copyTestList2.push_back(1);
        copyTestList2.push_back(2);
        copyTestList2.push_back(3);
        copyTestList2.push_back(4);
        IntList copyTestListPair2;
        copyTestListPair2 = copyTestList2;

        cout << "Vector: " << endl;
        cout << copyTestListPair2 << endl;

        cout << "  testing {1, 2}" << endl;
        IntList copyTestList4;
        copyTestList4.push_back(1);
        copyTestList4.push_back(2);
        IntList copyTestListPair4;

        copyTestListPair4 = copyTestList4;

        cout << "Vector: " << endl;
        cout << copyTestList4 << endl;

        cout << "  testing big list 1-49" << endl;
        IntList copyTestList3;
        for (int i = 1; i < 50; i++) {

            copyTestList3.push_back(i);
        }
        IntList copyTestListPair3;
        copyTestListPair3 = copyTestList3;

        cout << "Vector: " << endl;
        cout << copyTestListPair3 << endl;

   }

   return 0;
}
