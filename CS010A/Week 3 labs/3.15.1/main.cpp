#include <iostream>
using namespace std;

int main() {
   int yearInSchool;
   int x;
   
   cin >> yearInSchool;
   
   x = yearInSchool;
   if (x < 0) {
      cout << "Invalid" << endl;   
   }
   else if (x <= 5) {
      cout << "Elementary school" << endl;
   }
   else if (x <= 8) {
      cout << "Middle school" << endl;   
   }
   else if (x <= 12) {
      cout << "High school" << endl;   
   }
   else if (x <= 16) {
      cout << "College" << endl;
   }
   else {
      cout << "Post-secondary" << endl;
   }

   return 0;
}
