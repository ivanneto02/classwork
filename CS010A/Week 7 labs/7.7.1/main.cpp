#include <iostream>
using namespace std;

double StepsToMiles(int userSteps) {
   double miles;
   
   miles = userSteps/2000.00;
      
   return miles;
}

int main() {
   int input;
   cin >> input;
   
   cout << StepsToMiles(input) << endl;

   return 0;
}