// Dice class test harness - midterm

#include <iostream>
#include "Dice.h"

using namespace std;

int main() {
   
   // Die will all be 0 until setSeed and rollDice called
   Dice d1;              // 2 6-sided dice
   cout << endl << "Default Dice: " << endl;
   cout << d1 << endl;
   
   d1.setSeed(333);
   d1.rollDice();
   cout << endl << "Default Dice: " << endl;
   cout << d1 << endl;
  
   Dice d2 = Dice(3);     // 3 6-sided dice
   d2.setSeed(555);
   d2.rollDice();
   cout << endl << "Dice 1 param: " << endl;
   cout << d2 << endl;

   Dice d3 = Dice(4, 20);  // 4 20-sided dice
   d3.setSeed(101110);
   d3.rollDice();  
   cout << endl << "Dice 2 params: " << endl;
   cout << d3 << endl;
   
   cout << endl << "Test rollTotal:" << endl;
   cout << "d1 total: " << d1.rollTotal() << endl;
   cout << "d2 total: " << d2.rollTotal() << endl;
   cout << "d3 total: " << d3.rollTotal() << endl;
  
   cout << endl << "Roll again:" << endl;
   d1.rollDice();
   d2.rollDice();
   d3.rollDice();
   cout << "Dice Values:" << endl;
   cout << "d1: " << d1 << "    d2: " << d2 << "    d3: " << d3 << endl;
   cout << "Dice Totals:" << endl;
   cout << "d1 roll total: " << d1.rollTotal() << endl;
   cout << "d2 roll total: " << d2.rollTotal() << endl;
   cout << "d3 roll total: " << d3.rollTotal() << endl;

   return 0;
}
