#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    char a = 'a';
    int compare = 97;

    // == is the comparison operator!
    cout << boolalpha;
    cout << "a is the same as compare: ";
    cout << (a == compare) << endl;

    return 0;
}