#include <iostream>
#include <string>
using namespace std;

int main() {
   string firstName;
   string middleName;
   string lastName;
   string message;
   string input;
   getline(cin, input);
   
   firstName = input.substr(0, input.find(' '));
   if (input.substr(input.find(' ') + 1, input.size()).find(' ') != string::npos) {
      string temp = input.substr(input.find(' ') + 1, input.size());
      middleName = temp.substr(0, temp.find(' '));
      lastName = temp.substr(temp.find(' ') + 1, temp.size());
      message = lastName + ", " + firstName + " " + middleName.at(0) + ".";
   }
   else {
      lastName = input.substr(input.find(' ') + 1, input.size());
      message = lastName + ", " + firstName; 
   }
   
   cout << message << endl;
   
   return 0;
}