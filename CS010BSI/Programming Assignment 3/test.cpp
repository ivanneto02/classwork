#include <iostream>
#include <vector>

using namespace std;

void removeItem(vector<int>&, int);

int main() {

	vector<int> ints = { 1, 2, 3, 4, 5 };

	removeItem(ints, 2);

	for (unsigned int i = 0; i < ints.size(); i++) {
	
		cout << ints.at(i) << " ";
	}
	cout << endl;

	return 0;
}

void removeItem(vector<int>& vctr, int num) {

	for (unsigned int i = 0; i < vctr.size(); i++) {

		if (vctr.at(i) == num) {

			for (unsigned int j = i; j < vctr.size() - 1; j++) {

				vctr.at(j) = vctr.at(j + 1);

			}

			vctr.pop_back();

			return;
		}

	}

}