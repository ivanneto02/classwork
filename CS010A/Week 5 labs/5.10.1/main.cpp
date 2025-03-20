#include <iostream>
#include <string>
using namespace std;

int main() {
   string userText;
   int charCount = 0;
   
   getline(cin, userText);  // Gets entire line, including spaces. 

   for (unsigned int i = 0; i <= (userText.size() - 1); i++) {
      if (!(userText.at(i) == ' ') && !(userText.at(i) == '.') && !(userText.at(i) == ',')) {
         charCount++;   
      }
   }
   
   cout << charCount << endl;

   return 0;
}