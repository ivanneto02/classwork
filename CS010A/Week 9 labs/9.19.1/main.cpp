#include <iostream>
#include <vector> 
#include <string>
using namespace std;

// Prototypes
void populateVector(vector<string>&);
void displayFinal(const vector<string>&);
int GetFrequencyOfWord(vector<string>, string);

int main() {
    int NUM_ELEMENTS;
    vector<string> wordVector;

    cin >> NUM_ELEMENTS;

    // Set size of vector
    wordVector.resize(NUM_ELEMENTS);

    populateVector(wordVector);     // Call to fill vector with values
    displayFinal(wordVector);       // Call to display final result

    return 0;
}

// Fill vector with string values
void populateVector(vector<string>& vctr) {
    for (unsigned int i = 0; i < vctr.size(); i++) {
        cin >> vctr.at(i);
    }
}

// Count the instances of the word in the vector
int GetFrequencyOfWord(vector<string> wordsList, string currWord) {
    int counter = 0;
    for (unsigned int i = 0; i < wordsList.size(); i++) {
        if (wordsList.at(i) == currWord) {
            counter++;
        }
    }
    return counter;
}

// Display the final result
void displayFinal(const vector<string>& vctr) {
    for (unsigned int i = 0; i < vctr.size(); i++) {
        cout << vctr.at(i) << " " << GetFrequencyOfWord(vctr, vctr.at(i)) << endl;
    }
}