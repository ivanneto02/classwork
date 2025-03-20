#include <iostream>
#include <string>

#include "Wizard.h"
#include "Elf.h"
#include "Warrior.h"

#include "Character.h"

using namespace std;

Elf::Elf(string name, double health, double attackStrength, string familyName) :

	Character::Character(ELF, name, health, attackStrength),
	familyName(familyName)

{}

void Elf::attack(Character& target) {

	if (target.getType() == ELF) {

		Elf& targetConvert = dynamic_cast<Elf&>(target);

		if (targetConvert.familyName == this->familyName) {

			cout << "Elf " << this->getName() << " does not attack Elf " << targetConvert.getName() << "." << endl
				 << "They are both members of the " << this->familyName << " family." << endl;

			return;
		}

	}

	double attackDamage = ( (this->health * 1.0) / (MAX_HEALTH) ) * (this->attackStrength);

	target.damage(attackDamage);

	cout << "Elf " << this->getName() << " shoots an arrow at " << target.getName() << " --- TWANG!!" << endl
		 << target.getName() << " takes " << attackDamage << " damage." << endl;

}