#include <iostream>
using namespace std;

int main() {
   // Declare ints
   int int1;
   int int2;
   int int3;
   
   cin >> int1 >> int2 >> int3; // take in ints
   
   // All possible values and outcomes
   if ((int1 > int2) && (int1 > int3)) {
      cout << int1 << endl;   
   }
   else if ((int2 > int1) && (int2 > int3)) {
      cout << int2 << endl;
   }
   else if ((int3 > int1) && (int3 > int2)) {
      cout << int3 << endl;   
   }
   else {
      if ((int1 == int2) && (int3 > int1)) {
         cout << int3 << endl;   
      }
      else if ((int2 == int3) && (int1 > int2)) {
         cout << int1 << endl;
      }
      else if ((int1 == int3) && (int2 > int1)) {
         cout << int2 << endl;
      }
      else {
         cout << int1 << endl;
      }
   }

   return 0;
}