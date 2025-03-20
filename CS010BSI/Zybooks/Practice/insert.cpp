#include <iostream>
#include <vector>
using namespace std;

void numsInsert(vector<int>& numsList, int newNum) {
   unsigned int i;

   for (i = 0; i < numsList.size(); ++i) {
      if (newNum < numsList.at(i)) {
         cout << "called" << endl;
         numsList.insert(numsList.begin() + i, newNum);
         break; // Exits the for loop
      }
   }

   // FIXME: change so executes if higher number NOT found
   // Change "true" to "i == ??" (determine what ?? should be)
   if (i == numsList.size() - 1) { // No higher number was found, so append to end
      numsList.push_back(newNum);
      
   }   
}

void numsPrint(const vector<int>& numsList) {
   unsigned int i;

   for (i = 0; i < numsList.size(); ++i) {
      cout << " " << numsList.at(i) << endl;
   }
}

int main() {
   vector<int> numsList;
   numsInsert(numsList, 55);
   numsInsert(numsList, 4);
   numsInsert(numsList, 250);
   numsInsert(numsList, 19);
   numsPrint (numsList);

   return 0;
}