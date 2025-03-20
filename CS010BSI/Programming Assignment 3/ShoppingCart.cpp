#include <iostream>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;

// Constructors

// Constructor 1, no parameters
ShoppingCart::ShoppingCart() {

	this->_customerName = "none";
	this->_currentDate = "January 1, 2016";
}

// Constructor 2, two parameters
ShoppingCart::ShoppingCart(string name, string date) {

	this->_customerName = name;
	this->_currentDate = date;
}

// End of constructors

// Mutators

// Adds an item into the vector of items
void ShoppingCart::addItem(ItemToPurchase item) {

	this->_cartItems.push_back(item);
}

// Removes an item from the vector of items
void ShoppingCart::removeItem(string itemName) {

	for (unsigned int i = 0; i < this->_cartItems.size(); i++) {

		if (this->_cartItems.at(i).name() == itemName) {

			for (unsigned int j = i; j < this->_cartItems.size() - 1; j++) {

				this->_cartItems.at(j) = this->_cartItems.at(j + 1);
			}

			this->_cartItems.pop_back();

			return;
		}

	}

	cout << "Item not found in cart. Nothing removed." << endl;
}

// Modifies an item in the cart
void ShoppingCart::modifyItem(ItemToPurchase item) {

	for (unsigned int i = 0; i < this->_cartItems.size(); i++) {

		if (this->_cartItems.at(i).name() == item.name()) {

			if (item.name() != "none") {

				this->_cartItems.at(i).setName(item.name());
			}

			if (item.description() != "none") {

				this->_cartItems.at(i).setDescription(item.description());
			}
			
			if (item.price() != 0) {

				this->_cartItems.at(i).setPrice(item.price());
			}

			if (item.quantity() != 0) {

				this->_cartItems.at(i).setQuantity(item.quantity());
			}

			return;
		}

	}

	cout << "Item not found in cart. Nothing modified." << endl;
}

// End of mutators

// Accessors

// Returns the name of the customer
string ShoppingCart::customerName() const {

	return this->_customerName;
}

// Returns the current date
string ShoppingCart::date() const {

	return this->_currentDate;
}

// Returns the number of items inside the cart
int ShoppingCart::numItemsInCart() const {

	int total = 0;

	for (unsigned int i = 0; i < this->_cartItems.size(); i++) {

		total += this->_cartItems.at(i).quantity();
	}
	
	return total;
}

// Returns the cost of the cart
int ShoppingCart::costOfCart() const {

	int total = 0;

	for (unsigned int i = 0; i < this->_cartItems.size(); i++) {

		total += this->_cartItems.at(i).price() * this->_cartItems.at(i).quantity();
	}

	return total;
}

// Prints the total items and their respective costs
void ShoppingCart::printTotal() const {

	cout << this->_customerName << "'s Shopping Cart - " << this->_currentDate << endl;
	cout << "Number of Items: " << this->numItemsInCart() << endl << endl;

	for (unsigned int i = 0; i < this->_cartItems.size(); i++) {

		this->_cartItems.at(i).printItemCost();
		cout << endl;
	}

	if (this->numItemsInCart() == 0) {

		cout << "SHOPPING CART IS EMPTY" << endl;
	}

	cout << endl << "Total: $" << this->costOfCart() << endl;

}

// Prints the descriptions of each item
void ShoppingCart::printDescriptions() const {

	cout << this->_customerName << "'s Shopping Cart - " << this->_currentDate << endl << endl;
	cout << "Item Descriptions" << endl;
	
	for (unsigned int i = 0; i < this->_cartItems.size(); i++) {

		this->_cartItems.at(i).printItemDescription();
		cout << endl;
	}

}

// End of accessors