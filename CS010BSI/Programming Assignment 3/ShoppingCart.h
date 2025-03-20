#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>
#include <vector>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

class ShoppingCart {

	private:

		// Data members
		std::string _customerName;
		std::string _currentDate;
		std::vector<ItemToPurchase> _cartItems;

	public:

		// Constructors
		ShoppingCart();
		ShoppingCart(std::string, std::string);

		// Mutators
		void addItem(ItemToPurchase);
		void removeItem(std::string);
		void modifyItem(ItemToPurchase);

		// Accessors
		std::string customerName() const;
		std::string date() const;
		int numItemsInCart() const;
		int costOfCart() const;

		void printTotal() const;
		void printDescriptions() const;

};


#endif