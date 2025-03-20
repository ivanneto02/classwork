#include <iostream>
#include <vector>

using namespace std;

class Business {
	private:
		string description;
		
	public:
		
		string getDescription() const { return this->description; };
		virtual void printDescription() const {
			
			cout << "Business description: " << this->getDescription() << endl;
		};
	
};

class Restaurant : public Business {
	
	public:

		void printDescription() const override {
			
			
			cout << "Restaurant description: " << this->getDescription() << endl;
		};
	
};

int main() {
	
	vector<Business*> businessList;
	
	Business business1;
	Business business2;
	Restaurant restaurant1;
	Restaurant restaurant2;
	
	Business* ptr1 = &business1;
	Business* ptr2 = &business2;
	Restaurant* ptr3 = &restaurant1;
	Restaurant* ptr4 = &restaurant2;
	
	businessList.push_back(ptr1);
	businessList.push_back(ptr2);
	businessList.push_back(ptr3);
	businessList.push_back(ptr4);
	
	for (unsigned int i = 0; i < businessList.size(); i++) {
		
		businessList.at(i)->printDescription();
		
	}
	
	return 0;
}