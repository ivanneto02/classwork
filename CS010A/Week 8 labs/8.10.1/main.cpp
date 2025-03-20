#include <iostream>
#include <string>
using namespace std;

void IntegerToReverseBinary(int, string&);
void DisplayReverseString(const string&);

int main() {
   string reverseBinary;
   int userInput;
   
   cin >> userInput;

   IntegerToReverseBinary(userInput, reverseBinary);
   DisplayReverseString(reverseBinary);
   
   return 0;
}

void IntegerToReverseBinary(int integerValue, string& s) {
   while (integerValue != 0) {
      s += to_string(integerValue % 2);
      integerValue /= 2;
   }
}

void DisplayReverseString(const string& userString) {
   for (unsigned int i = userString.length(); i > 0; i--) {
      cout << userString.at(i - 1);
   }
   cout << endl;
}