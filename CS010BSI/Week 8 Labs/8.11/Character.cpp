#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

// Constructors

Character::Character(HeroType type, const string& name, double health, double attackStrength) {
	
	this->type = type;
	this->name = name;
	this->health = health;
	this->attackStrength = attackStrength;

}

// End of constructors

// Accessors

HeroType Character::getType() const {

	return this->type;
}

const string& Character::getName() const {

	return this->name;
}

int Character::getHealth() const {

	return static_cast<int>(this->health);
}

bool Character::isAlive() const {

	return (this->getHealth() > 0);
}

// End of accessors

// Mutators

void Character::damage(double damage) {

	this->health -= damage;
}

// End of mutators
