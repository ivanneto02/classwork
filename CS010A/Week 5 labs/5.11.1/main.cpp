#include <iostream>
using namespace std;

int main() {
   int int1;
   int int2;
   
   cin >> int1 >> int2;
   
   if (int1 > int2) {
      cout << "Second integer can't be less than the first.";  
   }
   
   while (int1 <= int2) {
      cout << int1 << " ";
      int1 = int1 + 10;
   }

   cout << endl;

   return 0;
}