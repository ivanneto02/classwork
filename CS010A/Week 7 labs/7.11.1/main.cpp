#include <iostream>
#include <cstdlib>
using namespace std;

string HeadsOrTails() {
   if (rand()%2 == 0) {
      return "heads";   
   }   
   return "tails";
}

int main() {
   int iterations;
   
   cin >> iterations;
   
   srand(2);  // Unique seed

   for (int i = 0; i < iterations; i++) {
      cout << HeadsOrTails() << endl;
   }

   return 0;
}