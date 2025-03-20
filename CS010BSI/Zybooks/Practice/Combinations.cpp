#include <iostream>
#include <vector>

using namespace std;

// Prototypes
void CombinationHelper(string, string);
void Combinations(string);

int main() {

	Combinations("abcdefg");

	return 0;
}

// Actually performs the combinations
void CombinationHelper(string word, string scramble) {

	string tmp;	

	// Base case, only passes if scramble has all the letters in word
	if (word.size() == 0) {

		cout << scramble << endl;
	}

	// For loop for each letter
	for (unsigned int i = 0; i < word.size(); i++) {

		// Save the letter at i in word
		tmp = word.substr(i, 1);

		// Erase the letter at i in word
		word.erase(i, 1);

		// Add the letter at i in word to scramble
		scramble += tmp;

		// Recursive call, will now have one less letter (at i)
		// in word, and one more letter (word at i) in scramble
		CombinationHelper(word, scramble);

		// Add the letter at i back to word (at i)
		word.insert(i, tmp);

		// Remove the letter at i from scramble
		scramble.erase(scramble.size() - 1, 1);

	}

}

// Main function to only pass a string
void Combinations(string base) {

	CombinationHelper(base, "");
}