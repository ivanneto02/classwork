#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
void removeEvens(const vector<int>& nums, vector<int> &odds);

int main() {

    // Vector 1
	vector<int> input(9);
	input.at(0) = 1;
	input.at(1) = 2;
	input.at(2) = 3;
	input.at(3) = 4;
	input.at(4) = 5;
	input.at(5) = 6;
	input.at(6) = 7;
	input.at(7) = 8;
	input.at(8) = 9;

    // Vector 2
	vector<int> result;

    // Calls remove evens function
	removeEvens(input, result); // Should return result with [1, 3, 5, 7, 9]

    // Prints each element to make sure it is correct
	for (size_t i = 0; i < result.size(); ++i) {
		cout << result.at(i);
	}
	cout << endl;

	return 0;
}

// Given two vectors, removeEvens identifies odd numbers within the first parameter, and places
// them inside the second parameter.
void removeEvens(const vector<int>& nums, vector<int>& odds) {
    for (unsigned int i = 0; i < nums.size(); i++) {
        if (nums.at(i)%2 != 0) {
            odds.push_back(nums.at(i));
        }
    }
}