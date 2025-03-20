#include <iostream>
using namespace std;

int main() {
   /* Type your code here. */
   int userNum;
   int x;
   
   cin >> userNum;
   cin >> x;
   
   cout << userNum/x << " " << (userNum/x)/x << " " << ((userNum/x)/x)/x << " " << (((userNum/x)/x)/x)/x << endl;

   return 0;
}
