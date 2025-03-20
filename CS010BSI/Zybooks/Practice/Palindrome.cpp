#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string myStr);

int main() {

	string pal = "racecar";
	string nonpal = "carrace";

	cout << boolalpha;

	cout << "\"racecar\": " << isPalindrome(pal) << endl;
	cout << "\"carrace\": " << isPalindrome(nonpal) << endl;

	return 0;
}

bool isPalindrome(string myStr) {

	if (myStr.size() == 1 || myStr.size() == 0) {

		return true;
	}

	if (myStr.at(0) == myStr.at(myStr.size() - 1)) {

		return true;
	}
	else {

		return false;
	}

	return isPalindrome(myStr.substr(1, myStr.size() - 2));
}