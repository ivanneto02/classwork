#include <iostream>
#include <string>

#include "ItemToPurchase.h"

using namespace std;

// Constructors

ItemToPurchase::ItemToPurchase() {

	this->_name = "none";
	this->_description = "none";
	this->_price = 0;
	this->_quantity = 0;

}

ItemToPurchase::ItemToPurchase(string name, string description, int price = 0, int quantity = 0) {

	this->_name = name;
	this->_description = description;
	this->_price = price;
	this->_quantity = quantity;

}

// End of constructors

// Mutators

void ItemToPurchase::setName(string name) {

	this->_name = name;
}

void ItemToPurchase::setPrice(int price) {

	this->_price = price;
}

void ItemToPurchase::setQuantity(int quantity) {

	this->_quantity = quantity;
}

void ItemToPurchase::setDescription(string description) {

	this->_description = description;
}

// End of mutators

// Accessors

string ItemToPurchase::name() const {

	return this->_name;
}

int ItemToPurchase::price() const {
	
	return this->_price;
}

int ItemToPurchase::quantity() const {

	return this->_quantity;
}

string ItemToPurchase::description() const {
	
	return this->_description;
}

void ItemToPurchase::printItemCost() const {

	cout << this->_name << " ";
	cout << this->_quantity << " ";
	cout << "@ $" << this->_price << " = ";
	cout << "$" << (this->_quantity * this->_price);
}

void ItemToPurchase::printItemDescription() const {

	cout << this->_name << ": ";
	cout << this->_description;
}