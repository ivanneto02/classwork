#include <iostream>
#include <vector>
#include <map>

using namespace std;

int romanToInt(string s) {

    map<string, int> components;

    // Iterate through the string and put each char and
    // counter in hash table
    int s_i = 0;
    int e_i = 0;

    int i = 0;
    while(i < s.length()) {
        
        // Check if there is a separation
        if (s.at(i) != s.at(i + 1)) {
            
            components[s.substr(s_i, e_i - s_i)] = e_i - s_i;
        }

        e_i++;
        i++;
    }

    return 0;
}

int main() {
 
    int answer = romanToInt("IIIX");

    return 0;
}