#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Date {

     private:

        unsigned day;
        unsigned month;
        string monthName;
        unsigned year;

        vector<string> monthsVector = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        vector<int> daysVector = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

     public:

        vector<string> getMonthsVector() const { return this->monthsVector; };
        vector<int> getDaysVector() const { return this->daysVector; };

        // creates the date January 1st, 2000.
        Date();

        /* parameterized constructor: month number, day, year 
            - e.g. (3, 1, 2010) will construct the date March 1st, 2010

            If any of the arguments are invalid (e.g. 15 for month or 32 for day)
            then the constructor will construct instead a valid Date as close
            as possible to the arguments provided - e.g. in above example,
            Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
            In case of such invalid input, the constructor will issue a console error message: 

            Invalid date values: Date corrected to 12/31/2010.
            (with a newline at the end).
        */
        Date(unsigned m, unsigned d, unsigned y);


        /* parameterized constructor: month name, day, year
            - e.g. (December, 15, 2012) will construct the date December 15th, 2012

            If the constructor is unable to recognize the string argument as a valid month name,
            then it will issue a console error message: 

            Invalid month name: the Date was set to 1/1/2000.
            (with a newline at the end).
 
            If the day argument is invalid for the given month (but the month name was valid),
            then the constructor will handle this error in the same manner as the other
            parameterized constructor. 

            This constructor will recognize both "december" and "December"
            as month name.
        */
        Date(const string &mn, unsigned d, unsigned y);


        /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
            Does not output a newline at the end.
        */
        void printNumeric() const;


        /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
            The first letter of the month name is upper case, and the month name is
            printed in full - January, not Jan, jan, or january. 
            Does not output a newline at the end.
        */
        void printAlpha() const;

     private:

        /* Returns true if the year passed in is a leap year, otherwise returns false.
        */
        bool isLeap(unsigned y) const;


        /* Returns number of days allowed in a given month
            -  e.g. daysPerMonth(9, 2000) returns 30.
            Calculates February's days for leap and non-leap years,
            thus, the reason year is also a parameter.
        */
        unsigned daysPerMonth(unsigned m, unsigned y) const;

        /* Returns the name of a given month
            - e.g. name(12) returns the string "December"
        */
        string name(unsigned m) const;

        /* Returns the number of a given named month
            - e.g. number("March") returns 3
        */
        unsigned number(const string &mn) const;

        /* 
        
        */
        void normalize(unsigned&, unsigned&, unsigned&) const;
        
        bool checkForMonthValue(const string&) const;
};

// Implement the Date member functions here

// Constructors

// Default constructor
Date::Date() {

    // Default variables
    this->day = 1;
    this->month = 1;
    this->monthName = "January";
    this->year = 2000;

}

Date::Date(unsigned m, unsigned d, unsigned y) {

    this->normalize(m, d, y);

    this->monthName = name(m);
    this->month = m;
    this->day = d;
    this->year = y;

}

Date::Date(const string& mn, unsigned d, unsigned y) {
    
    this->monthName = mn;
    this->monthName[0] = toupper(this->monthName[0]);

    if (!checkForMonthValue(this->monthName)) {

        cout << "Invalid month name: the Date was set to 1/1/2000." << endl;

        this->day = 1;
        this->month = 1;
        this->year = 2000;
        this->monthName = "January";

        return;

    }

    this->month = number(this->monthName); // Fix month name check

    this->normalize(month, d, y);

    this->day = d;
    this->year = y;

}

// End of constructors

// Public methods

/* Outputs to the console (cout) a Date exactly in the format "3/15/2012".
    Does not output a newline at the end.
*/
void Date::printNumeric() const {

    cout << this->month << "/" << this->day << "/" << this->year;

}

/* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
    The first letter of the month name is upper case, and the month name is
    printed in full - January, not Jan, jan, or january.
    Does not output a newline at the end.
*/
void Date::printAlpha() const {

    cout << this->monthName << " " << this->day << ", " << this->year;

}

// End of public methods

// Private methods

// Determines whether year is leap year
bool Date::isLeap(unsigned y) const {

    if (y % 400 == 0) {

        return true;

    }

    if ((y % 4 == 0) && !(y % 100 == 0)) {

        return true;

    }

    return false;

}

// Determines how many days per month
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {

    vector<int> daysVector = this->getDaysVector();

    if (m == 2 && isLeap(y)) {

        return 29;

    }

    return daysVector.at(m - 1);

}

// Gets name of given month number
string Date::name(unsigned m) const {

    vector<string> monthsVector = this->getMonthsVector();

    if (m > 0 && m < 13) {

        return monthsVector.at(m - 1);
    
    }

    return "Null";

}

// Gets the number of a given month name
unsigned Date::number(const string& mn) const {

    vector<string> monthsVector = this->getMonthsVector();

    for (unsigned int i = 0; i < monthsVector.size(); i++) {
        if (monthsVector.at(i) == mn) {
            
            return i + 1;

        }

    }

    return 0;

}

void Date::normalize(unsigned& m, unsigned& d, unsigned& y) const {

    int count = 0;

    if (m < 1) {
        m = 1;
        count++;
    }

    if (m > 12) {
        m = 12;
        count++;
    }

    if (d < 1) {
        d = 1;
        count++;
    }

    if (d > this->daysPerMonth(m, y)) {
        d = this->daysPerMonth(m, y);
        count++;
    }

    if (count >= 1) {

        cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;

    }

}

bool Date::checkForMonthValue(const string& tryName) const {

    vector<string> monthsVector = this->getMonthsVector();

    int count = 0;

    for (unsigned int i = 0; i < monthsVector.size(); i++) {

        if (tryName == monthsVector.at(i)) {

            count++;

        }

    }

    if (count > 0) {
        return true;
    }

    return false;

}

// End of private methods

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}