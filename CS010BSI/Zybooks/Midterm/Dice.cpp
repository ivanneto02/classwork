// Dice class implementation file


//int _numSides;
//vector<int> _latestRoll;

#include "Dice.h"

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
Dice::Dice(int numDice, int numSides) {
   
   this->_numSides = numSides;
   this->_latestRoll.resize(numDice);
   
}


/* Outputs all dice with a space between them 
    * and no space or newline at the end
    */
ostream& operator<<(ostream& out, const Dice& currDice) {
   
   for (unsigned int i = 0; i < currDice._latestRoll.size(); i++) {
      
      if (i == currDice._latestRoll.size() - 1) {
         
         out << currDice._latestRoll.at(i);
         break;
      }
      
      out << currDice._latestRoll.at(i) << " ";
   }
   
   return out;
}

/* Gets random values for all dice and stores them in _latestRoll
    */
void Dice::rollDice() {
   
   for (unsigned int i = 0; i < this->_latestRoll.size(); i++) {
   
      _latestRoll.at(i) = randInt(1, this->_numSides);
   }
   
}

void Dice::setSeed(int seed) {
   
   srand(seed);
}

/* Returns the total of all dice from latest roll
    */
int Dice::rollTotal() const {
   
   int sum = 0;
   
   for (unsigned int i = 0; i < this->_latestRoll.size(); i++) {
      
      sum += _latestRoll.at(i);   
      
   }
   
   return sum;
   
}

int Dice::randInt(int low, int high) const {
   
   return (rand() % (high - low)) + low;
   
}