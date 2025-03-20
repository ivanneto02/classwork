#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
bool inOrder(const vector<int> &nums);

int main() {
    
    // Vector 1
	vector<int> nums1(5);
	nums1.at(0) = 5;
	nums1.at(1) = 6;
	nums1.at(2) = 7;
	nums1.at(3) = 8;
	nums1.at(4) = 3;

    // Check first vector
	if (inOrder(nums1)) {
		cout << "In order" << endl;
	}
	else {
		cout << "Not in order" << endl;
	}

    // Vector 2
	vector<int> nums2(5);
	nums2.at(0) = 5;
	nums2.at(1) = 6;
	nums2.at(2) = 7;
	nums2.at(3) = 8;
	nums2.at(4) = 10;

    // Check second vector
	if (inOrder(nums2)) {
		cout << "In order" << endl;
	}
	else {
		cout << "Not in order" << endl;
	}

	return 0;
}

bool inOrder(const vector<int>& nums) {

    // Assume sorted unless for loops find instance of non-sorted
    for (unsigned int i = 0; i < nums.size() - 1; ++i) {

        if (nums.at(i) != nums.at(i + 1)) {

            return false;
        }
    }

    return true; 
}

/*
bool inOrder(const vector<int>& nums) {

    // Assume sorted unless for loops find instance of non-sorted
    for (unsigned int i = 0; i < nums.size() - 1; i++) {
        if (nums.at(i + 1) < nums.at(i)) {
            return false;
        }
    }

    return true; 
}
*/