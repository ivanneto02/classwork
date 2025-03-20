#include <iostream>
using namespace std;

int main() {
   int trunkHeight = 0;
   int trunkWidth;
   int leafWidth = 0;
   int leafRows;
   
   cout << "Enter height of trunk: ";
   cin >> trunkHeight;
   cout << endl;
   while (!(trunkHeight > 0)) {
        cout << "Please enter a positive number for height of trunk: ";
        cin >> trunkHeight;
        cout << endl;
   }

   cout << "Enter width of trunk: ";
   cin >> trunkWidth;
   cout << endl;
   while ((trunkWidth%2 == 0) || (trunkWidth <= 0)) {
        cout << "Please enter an odd number for width of trunk: ";
        cin >> trunkWidth;
        cout << endl;
   }

   cout << "Enter width of leaves: ";
   cin >> leafWidth;
   cout << endl;
   while ((leafWidth <= trunkWidth) || (leafWidth%2 == 0)) {
        cout << "Please enter a number for width of leaves larger than " << trunkWidth + 1 << ": ";
        cin >> leafWidth;
        cout << endl;
   }

   cout << endl;

   for (int i = 1; i <= leafWidth; i += 2) {
        for (int j = 1; j <= leafWidth - i; j += 2) {
            cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
   }

   for (int i = 1; i <= trunkHeight; i++) {
       for (int j = 1; j < (leafWidth - trunkWidth + 2)/2; j++) {
           cout << " ";
       }

       for (int j = 1; j <= trunkWidth; j++) {
           cout << "*";
       }

       cout << endl;
   }
   
    return 0;
}