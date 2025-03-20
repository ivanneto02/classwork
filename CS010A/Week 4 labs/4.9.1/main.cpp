#include <iostream>
#include <string>
using namespace std;

int main() {
   int x;
   string storedValues;
   
   cin >> x;
   
   while (x > 0) {
      storedValues.append(to_string(x % 2)); //Add the value of x%2 as a string to the front of storedValues.
      x = x/2;
   }
   
   cout << storedValues << endl;
   return 0;
}