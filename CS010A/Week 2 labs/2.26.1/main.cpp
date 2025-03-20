#include <iostream>
using namespace std;

int main() {
   long phoneNumber;

   cin >> phoneNumber;
   
   /* Type your code here */
   cout << phoneNumber/10000000 << "-" << (phoneNumber/10000)%1000 << "-" << phoneNumber%10000 << endl;
   
   return 0;
}
