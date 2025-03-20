#include <iostream>
#include <string>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

// Prototypes
void printMenu(ShoppingCart);
void outputCartItems(ShoppingCart&);
void outputCartDescriptions(ShoppingCart&);
void addItem(ShoppingCart&);
void removeItem(ShoppingCart&);
void changeItemQuantity(ShoppingCart&);

void outputOptions();

int main() {

	string customerName;
	string currentDate;

	cout << "Enter customer's name: ";
	getline(cin, customerName);
	cout << endl;

	cout << "Enter today's date: ";
	getline(cin, currentDate);
	cout << endl << endl;

	cout << "Customer name: " << customerName << endl;
	cout << "Today's date: " << currentDate << endl;

	ShoppingCart newCart1(customerName, currentDate);

	printMenu(newCart1);

	// g++ main.cpp ItemToPurchase.cpp ShoppingCart.cpp -Wall -Wuninitialized -o a.out
}

// Prints the menu and implements options
void printMenu(ShoppingCart currentCart) {
	
	string choice = "x";

	outputOptions();

	while (choice != "q") {

		cout << "Choose an option: " << endl;
		cin >> choice;

		if (choice == "a") {

			addItem(currentCart);
			outputOptions();
		}
		else if (choice == "d") {

			removeItem(currentCart);
			outputOptions();
		}
		else if (choice == "c") {

			changeItemQuantity(currentCart);
			outputOptions();
		}
		else if (choice == "i") {

			outputCartDescriptions(currentCart);
			outputOptions();
		}
		else if (choice == "o") {

			outputCartItems(currentCart);
			outputOptions();
		}
		else if (choice == "q") {

			break;
		}

	}

}

// Outputs every item in the cart and their price
void outputCartItems(ShoppingCart& currentCart) {

	cout << "\nOUTPUT SHOPPING CART" << endl;

	currentCart.printTotal();
}

// Outputs the description of each item in the cart
void outputCartDescriptions(ShoppingCart& currentCart) {

	cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;

	currentCart.printDescriptions();
}

// Adds an item into the cart
void addItem(ShoppingCart& currentCart) {

	ItemToPurchase newItem;

	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuantity;

	cout << "ADD ITEM TO CART" << endl;

	cout << "Enter the item name: " << endl;
	cin.ignore();
	getline(cin, itemName);

	cout << "Enter the item description: " << endl;
	getline(cin, itemDescription);

	cout << "Enter the item price: " << endl;
	cin >> itemPrice;

	cout << "Enter the item quantity: " << endl;
	cin >> itemQuantity;

	newItem.setName(itemName);
	newItem.setDescription(itemDescription);
	newItem.setPrice(itemPrice);
	newItem.setQuantity(itemQuantity);

	currentCart.addItem(newItem);

}

// Removes an item from a cart
void removeItem(ShoppingCart& currentCart) {

	string itemName;

	cout << "REMOVE ITEM FROM CART" << endl;

	cout << "Enter name of item to remove: " << endl;
	cin.ignore();
	getline(cin, itemName);

	currentCart.removeItem(itemName);
}

// Changes the quantity of a given item in the cart
void changeItemQuantity(ShoppingCart& currentCart) {

	ItemToPurchase newItem;

	string itemName;
	int itemQuantity;

	cout << "CHANGE ITEM QUANTITY" << endl;

	cout << "Enter the item name: " << endl;
	cin.ignore();
	getline(cin, itemName);

	cout << "Enter the new quantity: " << endl;
	cin >> itemQuantity;

	newItem.setName(itemName);
	newItem.setQuantity(itemQuantity);

	currentCart.modifyItem(newItem);
}

// Option menu
void outputOptions() {

	cout << endl << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl << endl;
}