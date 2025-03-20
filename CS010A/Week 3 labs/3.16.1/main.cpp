#include <iostream>
using namespace std;

int main() {
   int red;
   int green;
   int blue;
   int smallestVal;
   
   cin >> red >> green >> blue;
   
   if ((red < green) && (red < blue)) {
      smallestVal = red;
   }
   else if ((green < red) && (green < blue)) {
      smallestVal = green;
   }
   else if ((blue < red) && (blue < green)) {
      smallestVal = blue;   
   } else {
      if ((red == green) && (blue < red)) {
         smallestVal = blue;   
      }   
      else if ((red == blue) && (green < red)) {
         smallestVal = green;   
      }
      else if ((blue == green) && (red < blue)) {
         smallestVal = red;   
      } else {
         smallestVal = red;   
      }
   }
   
   red -= smallestVal;
   green -= smallestVal;
   blue -= smallestVal;
   
   cout << red << " " << green << " " << blue << endl;
   
   return 0;
}
