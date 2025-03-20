#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#include "Distance.h"

// Constructors

// Initializes private variables to 0
Distance::Distance() {

	this->feet = 0;
	this->inches = 0.0;

}

// Initializes private variables to ft and in
Distance::Distance(unsigned ft, double in) {

	this->feet = ft;
	this->inches = in;

	init();
}

// Initializes private variables to 0, in
Distance::Distance(double in) {

	this->feet = 0;
	this->inches = in;

	init();
}

// End of constructors


// Getter methods

// Gets feet value
unsigned Distance::getFeet() const {

	return this->feet;
}

// Gets inches value
double Distance::getInches() const {

	return this->inches;
}

// Gets distance in inches
double Distance::distanceInInches() const {

	return (this->feet * 12 + this->inches);
}

// Gets distance in feet
double Distance::distanceInFeet() const {

	return (this->feet + (getInches() / 12));
}

// Gets distance in meters
double Distance::distanceInMeters() const {

	return (this->distanceInInches() * 0.0254);
}

// End of getter methods

// Overloaded operators

// Overloads the + operator to work on Distance objects
Distance Distance::operator+(const Distance& rhs) const {

	unsigned totalFeet = this->feet + rhs.feet;
	double totalInches = this->inches + rhs.inches;

	return Distance(totalFeet, totalInches);
}

// Overloads the - operator to work on Distance objects
Distance Distance::operator-(const Distance& rhs) const {

	double aggregateInches = fabs(this->distanceInInches() - rhs.distanceInInches());

	unsigned totalFeet = aggregateInches / 12;

	double totalInches = fabs(aggregateInches - totalFeet * 12);

	return Distance(totalFeet, totalInches);
}

// Overloads the << ostream operator to work on Distance objects
ostream& operator<<(ostream& out, const Distance& rhs) {

	out << rhs.feet << "' " << rhs.inches << "\"";

	return out;
}

// End of overloaded operators

// Mutator methods

void Distance::init() {

	// In the case feet is negative
	int tempIntFt = static_cast<int>(this->feet);

	if (tempIntFt < 0) {

		tempIntFt = fabs(tempIntFt);

	}

	this->feet = static_cast<unsigned>(tempIntFt);

	// In case inches is negative
	if (this->inches < 0) {

		this->inches = fabs(this->inches);

	}

	// In case inches is more than 12
	while (this->inches >= 12) {

		this->feet += 1;

		this->inches -= 12;

	}

}