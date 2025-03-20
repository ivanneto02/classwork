#include <iostream>
#include <string>
using namespace std;

int main() {
   string userInput;
   getline(cin, userInput);
   
   while (userInput.find(' ') != string::npos) {
      userInput.replace(userInput.find(' '), 1, "");
   }
   
   cout << userInput << endl;

   return 0;
}