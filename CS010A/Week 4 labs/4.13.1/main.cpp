#include <iostream>
#include <string>
using namespace std;

int main() {
   string input;
   
   getline(cin, input);
   while (input != "quit 0") {
      cout << "Eating " << input.substr(input.find(' ') + 1, input.size()) << " " << input.substr(0, input.find(' ')) << " a day keeps the doctor away." << endl;
      getline(cin, input);
   }
   
   return 0;
}