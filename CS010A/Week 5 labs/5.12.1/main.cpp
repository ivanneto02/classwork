#include <iostream>
#include <string>
using namespace std;

int main() {
   string userInput;

   getline(cin, userInput);
   
   while (userInput != "quit" && userInput != "q" && userInput != "Quit") {
      for (unsigned int i = 1; i <= userInput.size(); i++) {
         cout << userInput.at(userInput.size() - i);
      }
      cout << endl;
      getline(cin, userInput);
   }

   return 0;
}
