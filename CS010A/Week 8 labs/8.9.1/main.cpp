#include <iostream>
#include <string>
using namespace std;

void RemoveSpaces(string&);

int main() {
   string userInput;
   
   getline(cin, userInput);

   RemoveSpaces(userInput);
   
   cout << userInput << endl;
   
   return 0;
}

void RemoveSpaces(string& userString) {
   while (userString.find(" ") != string::npos) {
      int index = userString.find(" ");
      userString.replace(index, 1, "");
   }
}