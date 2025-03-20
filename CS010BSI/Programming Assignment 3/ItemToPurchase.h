#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>

class ItemToPurchase {

	private:

		// Data members
		std::string _name;
		std::string _description;
		int _price;
		int _quantity;

	public:

		// Constructors
		ItemToPurchase();
		ItemToPurchase(std::string, std::string, int, int);

		// Mutators
		void setName(std::string);
		void setPrice(int);
		void setQuantity(int);
		void setDescription(std::string);

		// Accessors
		std::string name() const;
		int price() const; 
		int quantity() const;
		std::string description() const;

		void printItemCost() const;
		void printItemDescription() const;

};

#endif