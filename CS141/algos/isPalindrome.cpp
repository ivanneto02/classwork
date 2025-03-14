#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int x) {

    if (x < 0) {
        return false;
    }

    if (reverse(x) == x) {
        return true;
    }

    return false;
}

string reverse(string x) {

    string final = "";

    for (int i = x.length() - 1; i >= 0; i--) {
        final += x.at(i);
    }

    return final;
}

int main() {

    string rev = reverse("reverse");

    cout << rev << endl;

    return 0;
}