#include <iostream>
#include <string>
using namespace std;

int main() {
   char targetChar;
   string targetString;
   string storeSizeString;
   string input;
   
   getline(cin, input);
   
   targetChar = input.at(0);
   targetString = input.substr(input.find(' '), input.size());
   
   unsigned int i = 0;
   while(i < targetString.size()) {
         if (targetString.at(i) == targetChar) {
               storeSizeString += targetChar;
         }
         i++;
   }
   
   cout << storeSizeString.size() << endl;

   return 0;
}