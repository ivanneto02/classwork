#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {

   private:

      int numerator;
      int denominator; 

   public:

      Rational();
      explicit Rational(int); 
      Rational(int, int); 

      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;

      void simplify();
      void display() const;

   private:

      int gcd(int, int) const;
};

// Implement Rational class member functions here

// Private
int Rational::gcd(int numerator, int denominator) const {

    if (numerator == 0) {
        return 1;
    }

    // Eucledian algorithm
    while (!(numerator == denominator)) {

        // Check if the two numbers are equal to each other
        if (numerator == denominator) {
            return numerator;
        }

        // Modify depending on which one is bigger
        if (numerator > denominator) {
            numerator = numerator - denominator;
            continue;
        }

        denominator = denominator - numerator;

    }

    return numerator;
}

// Constructors

Rational::Rational() {

    this->numerator = 0;
    this->denominator = 1;

}

Rational::Rational(int numerator) {

    this->numerator = numerator;
    this->denominator = 1;

}

Rational::Rational(int numerator, int denominator) {

    this->numerator = numerator;
    this->denominator = denominator;

}
// End of constructors

// Mutators

// Simplifies the Rational object
void Rational::simplify() {

    // Greatest common denominator of the two
    int divInt = gcd(this->numerator, this->denominator);

    // Simplification
    this->numerator /= divInt;
    this->denominator /= divInt;
}

// Displays the Rational object in the form n / d
void Rational::display() const {

    // Display in the format n / d
    cout << this->numerator << " / " << this->denominator;
}
// End of mutators

// Accessor functions

// Adds one rational to another
Rational Rational::add(const Rational& oldRational) const {
    // Formula: (a/b) + (c/d) = (ad + bc) / (b*d)

    Rational newRational;

    // Values
    int a = this->numerator;
    int b = this->denominator;
    int c = oldRational.numerator;
    int d = oldRational.denominator;

    newRational.numerator = (a * d) + (b * c);
    newRational.denominator = b * d;

    newRational.simplify();

    return newRational;
}

// Subtracts one rational from another
Rational Rational::subtract(const Rational& oldRational) const {
    // Formula: (a/b) - (c/d) = (ad - bc) / (b*d)

    Rational newRational;

    // Values
    int a = this->numerator;
    int b = this->denominator;
    int c = oldRational.numerator;
    int d = oldRational.denominator;

    newRational.numerator = (a * d) - (b * c);
    newRational.denominator = b * d;
    
    newRational.simplify();

    return newRational;
}

// Multiplies one rational to another
Rational Rational::multiply(const Rational& oldRational) const {
    // Formula: (a/b) * (c/d) = (ac) / (bd)

    Rational newRational;

    // Values
    int a = this->numerator;
    int b = this->denominator;
    int c = oldRational.numerator;
    int d = oldRational.denominator;

    newRational.numerator = a * c;
    newRational.denominator = b * d;

    newRational.simplify();

    return newRational;
}

// Divides two rationals
Rational Rational::divide(const Rational& oldRational) const {
    // Formula: (a/b) / (c/d) = (ad) / (cb)

    Rational newRational;

    // Values
    int a = this->numerator;
    int b = this->denominator;
    int c = oldRational.numerator;
    int d = oldRational.denominator;

    newRational.numerator = a * d;
    newRational.denominator = c * b;

    newRational.simplify();

    return newRational;
}
// End of accessor functions

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);

   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);

   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);

   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);

   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}