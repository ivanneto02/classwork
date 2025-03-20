#include <iostream>
#include <string>
using namespace std;

int main() {
   string userString;
   bool status = true;
   
   cin >> userString;

   for (unsigned int i = 0; i < userString.size(); i++) {
      if (!(userString.at(i) >= '0' && userString.at(i) <= '9')) {
         status = false;   
      }
   }
   
   if (status) {
      cout << "yes" << endl;
   }
   else {
      cout << "no" << endl;   
   }

   return 0;
}