#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

/*
// Place charCnt prototype (declaration) here
int charCnt(string, char);

int main() {
	// Variable names
	string filename;
	char ch;
	int chCnt = 0;
   
	// Take in file name
	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << endl;

	// Take in character
	cout << "Enter a character: ";

	cin.ignore(); // ignores newline left in stream after previous input statement
	cin.get(ch);
	cout << endl;

	// Call function
	chCnt = charCnt(filename, ch);   
	cout << "# of " << ch << "'s: " << chCnt << endl;
   
	return 0;
}

// Place charCnt implementation here
int charCnt(string filename, char chr) {

	// Variable names
	ifstream inFS;
	int count = 0;

	char tempChar;

	inFS.open(filename);

	if (!inFS.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(-1);
	}

	while (inFS >> noskipws >> tempChar) {
		if (tempChar == chr) {
			count++;
		}
	}

	inFS.close();

	return count;
}
*/

// Place charCnt prototype (declaration) here
int charCnt(string filename, char ch);

int main() {
	string filename;
	char ch;
	int chCnt = 0;

	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << endl;
	cout << "Enter a character: ";
	cin.ignore(); // ignores newline left in stream after previous input statement
	cin.get(ch);
	cout << endl;

	chCnt = charCnt(filename, ch);
	cout << "# of " << ch << "'s: " << chCnt << endl;

	return 0;
}

// Place charCnt implementation here
int charCnt(string filename, char ch) {
	ifstream file;
	int count = 0;
	char temp;
	file.open(filename);

	if (!file.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(1);
	}

	while (!file.eof()) {
		file.get(temp);

		if (file.fail()) {
			break;
		}

		if (temp == ch)
			++count;
	}

	file.close();
	return count;
}