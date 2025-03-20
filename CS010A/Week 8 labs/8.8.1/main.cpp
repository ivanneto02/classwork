#include <iostream>
using namespace std;

void SwapValues(int& userVal1, int& userVal2) {
   int temp = userVal1;
   userVal1 = userVal2;
   userVal2 = temp;
}

int main() {
   int val1;
   int val2;
   
   cin >> val1 >> val2;

   SwapValues(val1, val2);
   cout << val1 << " " << val2 << endl;

   return 0;
}