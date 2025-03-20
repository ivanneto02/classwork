#include <iostream>
#include <cmath>
using namespace std;

int main() {
   double x;
   double y;
   double z;
   /* Type your code here. Note: Include the math library above first. */
   
   cin >> x >> y >> z;
   
   cout << pow(x, y) << " ";
   cout << pow(x, pow(y, z)) << " ";
   cout << fabs(x) << " ";
   cout << sqrt(pow(x*y, z)) << endl;

   return 0;
}