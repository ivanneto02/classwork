#include <iostream>
using namespace std;

int main() {
   /* Type your code here. */
   double milesPerGallon;
   double dollarsPerGallon;
   
   cin >> milesPerGallon;
   cin >> dollarsPerGallon;
   
   cout << (1/milesPerGallon)*(dollarsPerGallon)*10 << " ";
   cout << (1/milesPerGallon)*(dollarsPerGallon)*50 << " ";
   cout << (1/milesPerGallon)*(dollarsPerGallon)*400 << endl;

   return 0;
}