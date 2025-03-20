//Dice class interface

#ifndef __DICE_H__
#define __DICE_H__

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Dice {
 private:
   int _numSides;
   vector<int> _latestRoll;
   
 public:
 
   /* Default number of dice is 2.
    * Default number of sides is 6.
    *
    * Side values always start at 1.
    * For example, a 6-sided die would have the values
    * 1 2 3 4 5 6 on its sides.
    *
    * Can use vector's resize function
    * to resize the vector to the appropriate size.
    */
   Dice(int = 2, int = 6);
   
   /* Uses srand() to set the seed of the rand() function.
    */
   void setSeed(int);
   
   /* Gets random values for all dice and stores them in _latestRoll
    */
   void rollDice();
   
   /* Returns the total of all dice from latest roll
    */
   int rollTotal() const;
   
   /* Outputs all dice with a space between them 
    * and no space or newline at the end
    */
   friend ostream & operator<<(ostream &, const Dice &);
   
 private:
 
   /* Generates a random integer with the range low to high
    */
   int randInt(int low, int high) const;
};

#endif // __DICE_H__