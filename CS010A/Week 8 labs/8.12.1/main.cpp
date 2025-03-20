#include <iostream>
#include <vector> 
using namespace std;

void ExactChange(int, int&, int&, int&, int&, int&);
void OutputChange(int, int, int, int, int, int);

int main() {
   int inputVal;
   
   int dollars = 0;
   int quarters = 0;
   int dimes = 0;
   int nickels = 0;
   int pennies = 0;
   
   cin >> inputVal;
   
   ExactChange(inputVal, dollars, quarters, dimes, nickels, pennies);
   OutputChange(inputVal, dollars, quarters, dimes, nickels, pennies);
   
   return 0;
}

void ExactChange(int userTotal, int& numDollars, int& numQuarters, int& numDimes, int& numNickels, int& numPennies) {
   numDollars = (userTotal / 100);
   numQuarters = (userTotal % 100) / 25;
   numDimes = ((userTotal % 100) % 25) / 10;
   numNickels = (((userTotal % 100) % 25) % 10) / 5;
   numPennies = (userTotal % 5);
}

void OutputChange(int userTotal, int numDollars, int numQuarters, int numDimes, int numNickels, int numPennies) {
   if (userTotal <= 0) {
      cout << "no change" << endl;
      return;
   }
   if (numDollars != 0) {
      if (numDollars == 1) {
         cout << numDollars << " dollar" << endl;   
      }
      else {
         cout << numDollars << " dollars" << endl;
      }
   }
   if (numQuarters != 0) {
      if (numQuarters == 1) {
         cout << numQuarters << " quarter" << endl;
      }
      else {
         cout << numQuarters << " quarters" << endl;   
      }
   }
   if (numDimes != 0) {
      if (numDimes == 1) {
         cout << numDimes << " dime" << endl;
      }
      else {
         cout << numDimes << " dimes" << endl;   
      }  
   }
   if (numNickels != 0) {
      if (numNickels == 1) {
         cout << numNickels << " nickel" << endl;
      }
      else {
         cout << numNickels << " nickels" << endl;   
      } 
   }
   if (numPennies != 0) {
      if (numPennies == 1) {
         cout << numPennies << " penny" << endl;
      }
      else {
         cout << numPennies << " pennies" << endl;   
      }   
   }
}