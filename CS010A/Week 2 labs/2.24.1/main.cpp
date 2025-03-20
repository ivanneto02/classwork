#include <iostream>
using namespace std;

int main() {
   /* Type your code here. */
   int age;
   double weight;
   int heartRate;
   double minutes;
   
   cin >> age >> weight >> heartRate >> minutes;
   
   cout << "Men: " << (((age*0.2017) - (weight*0.09036) + (heartRate*0.6309) - 55.0969)*minutes)/4.184 << " calories" << endl;
   cout << "Women: " << (((age*0.074) - (weight*0.05741) + (heartRate*0.4472) - 20.4022)*minutes)/4.184 << " calories" << endl;

   return 0;
}
