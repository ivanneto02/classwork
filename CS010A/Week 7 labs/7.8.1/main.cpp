#include <iostream>
#include <cmath>
using namespace std;

int MaxMagnitude(int num1, int num2) {
   if (fabs(num1) >= fabs(num2)) {
      return num1;
   }
   return num2;
}

int main() {
   int number1, number2;
   cin >> number1 >> number2;
   
   cout << MaxMagnitude(number1, number2) << endl;

   return 0;
}
