#include <iostream>
using namespace std;

int main() {
   int inputYear;
   bool isLeapYear = false;
   
   cin >> inputYear;
   
   if ((inputYear%4) == 0) {
      isLeapYear = true;
      if ((inputYear%100) == 0) {
         if ((inputYear%400) == 0) {
            isLeapYear = true;   
         } else {
            isLeapYear = false;   
         }
      }
   }
   
   if (isLeapYear) {
      cout << inputYear << " is a leap year." << endl;   
   } else {
      cout << inputYear << " is not a leap year." << endl;   
   }

   return 0;
}