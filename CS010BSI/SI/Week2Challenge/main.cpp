#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

void outputToFile(const vector<int>&);

int main(int argc, char* argv[]) {
    ifstream inFS;

    string inputFile = argv[1];
    string outputFile = argv[2];

    vector<int> intVector;

    inFS.open(inputFile);

    if (!inFS.is_open()) {
        cout << "Something went wrong opening " << inputFile << endl;
        return -1;
    }

    int tempInt;
    string tempStr;

    int index = 0;

    while (!inFS.eof()) {
        if (index == 6) {

            getline(inFS, tempStr);
            tempInt = stoi(tempStr.c_str());

            if (inFS.fail()) {
                return -1;
            }

            intVector.push_back(tempInt);

            index = 0;

            continue;
        }

        getline(inFS, tempStr, ',');

        tempInt = stoi(tempStr.c_str());

        if (inFS.fail()) {
            return -1;
        }

        intVector.push_back(tempInt);

        index++;
    }

    inFS.close();

    return 0;
}

void outputToFile(string& outFile, const vector<int>& vctr) {
    ofstream outFS;

    outFS.open(outFile);

    if (!outFS.is_open()) {
        cout << "Something went wrong opening " << outFile << endl;
        exit(1);
    }

}