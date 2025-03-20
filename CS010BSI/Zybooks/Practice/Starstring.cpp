#include <iostream>

using namespace std;

string printStars(int);

int main() {
	
	cout << printStars(3) << endl;

	return 0;
}

string printStars(int num) {

	if (num == 0) {

		return "*";
	}

	string half1 = printStars(num - 1);
	string half2 = printStars(num - 1);

	string together = half1 + half2;

	return together;
}