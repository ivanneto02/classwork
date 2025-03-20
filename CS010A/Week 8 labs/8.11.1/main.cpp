#include <iostream>
#include <string>
using namespace std;

int CountCharacters(char, const string&);

int main() {
   char comparisonChar;
   string comparisonString;
   
   cin >> comparisonChar;
   getline(cin, comparisonString);

   cout << CountCharacters(comparisonChar, comparisonString) << endl;

   return 0;
}

int CountCharacters(char userChar, const string& userString) {
   int count = 0;
   for (unsigned int i = 0; i < userString.size(); i++) {
      if (userString.at(i) == userChar) {
         count++;   
      }
   }
   return count;
}