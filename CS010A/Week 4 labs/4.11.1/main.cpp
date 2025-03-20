#include <iostream>
using namespace std;

int main() {
   int sum = 0;
   int count = 0;
   int average;
   int maxNum;
   int current;
   cin >> current;
   
   maxNum = current;
   while (current >= 0) {
      sum += current;
      count++;
      if (maxNum < current) {
         maxNum = current;   
      }
      cin >> current;
   }
   
   average = sum / count;

   cout << average << " " << maxNum << endl;

   return 0;
}