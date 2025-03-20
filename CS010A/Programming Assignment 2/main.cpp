#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Core functions - Prototypes
char getUserOption();
void promptInputs(vector<int>&, vector<int>&);

// Menu functions - Prototypes
void OutputRoster(const vector<int>&, const vector<int>&);
void AddPlayer(vector<int>&, vector<int>&);
void RemovePlayer(vector<int>&, vector<int>&);
void UpdatePlayerRating(const vector<int>&, vector<int>&);
void OutputPlayersAboveRating(const vector<int>&, const vector<int>&);

int main() {

    // Vector definitions
    vector<int> playersVector;
    vector<int> ratingsVector;
    char userChoice;

    promptInputs(playersVector, ratingsVector);
    OutputRoster(playersVector, ratingsVector);

    userChoice = tolower(getUserOption());
    while (userChoice != 'q') {

        // Execute depending on the menu choice
        switch(userChoice) {
            case 'o':
                OutputRoster(playersVector, ratingsVector);
                break;
            case 'a':
                AddPlayer(playersVector, ratingsVector);
                break;
            case 'd':
                RemovePlayer(playersVector, ratingsVector);
                break;
            case 'u':
                UpdatePlayerRating(playersVector, ratingsVector);
                break;
            case 'r':
                OutputPlayersAboveRating(playersVector, ratingsVector);
                break;
        }

        userChoice = tolower(getUserOption());
    }

    return 0;
}

// Asks user to input 5 players and their ratings
void promptInputs(vector<int>& players, vector<int>& ratings) {
    for (int i = 1; i < 6; i++) {
        int jersey; // jersey number of player
        int rating; // player rating

        // Prompt and add item to vector
        cout << "Enter player " << i << "'s jersey number: ";
        cin >> jersey;
        players.push_back(jersey);
        cout << endl;

        // Prompt and add item to vector
        cout << "Enter player " << i << "'s rating: ";
        cin >> rating;
        ratings.push_back(rating);
        cout << endl << endl;
    }
}

// Asks user to choose an option from the menu
char getUserOption() {
    char userChoice;

    // Display menu
    cout << endl << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option: ";

    // Input and return the option choice
    cin >> userChoice;
    cout << endl;
    return userChoice;
}

// Ouputs current roster
void OutputRoster(const vector<int>& players, const vector<int>& ratings) {
    cout << "ROSTER" << endl;
    
    // Iterate through every item in players; output.
    for (unsigned int i = 0; i < players.size(); i++) {
        cout << "Player " << i + 1 << " -- ";
        cout << "Jersey number: " << players.at(i) << ", ";
        cout << "Rating: " << ratings.at(i) << endl;
    }
}

// Adds a player to the roster
void AddPlayer(vector<int>& players, vector<int>& ratings) {
    int jersey;
    int rating;

    // Prompt and add item to vector
    cout << "Enter another player's jersey number: ";
    cin >> jersey;
    players.push_back(jersey);
    cout << endl;

    // Prompt and add item to vector
    cout << "Enter another player's rating: ";
    cin >> rating;
    ratings.push_back(rating);
    cout << endl;
}

// Deletes player from a roster
void RemovePlayer(vector<int>& players, vector<int>& ratings) {
    int indexAim; // The index of the jersey number;
    int jersey;

    cout << "Enter a jersey number: ";
    cin >> jersey;
    cout << endl;

    // Find the index of the player to remove
    for (unsigned int i = 0; i < players.size(); i++) {
        if (players.at(i) == jersey) {
            indexAim = i;
        }
    }

    // Move every item left starting from index of aim
    for (unsigned int i = indexAim; i < players.size() - 1; i++) {
        players.at(i) = players.at(i + 1);
        ratings.at(i) = ratings.at(i + 1);
    }

    // Remove last item
    players.pop_back();
    ratings.pop_back();
}

// Updates a player's rating
void UpdatePlayerRating(const vector<int>& players, vector<int>& ratings) {
    int jersey;         // Jersey number of player
    int aimIndex;       // Index where jersey number takes place
    int newRating;      // New rating of that player

    // Prompt to enter jersey number
    cout << "Enter a jersey number: ";
    cin >> jersey;
    cout << endl;
    
    // Prompt to enter new rating
    cout << "Enter a new rating for player: ";
    cin >> newRating;
    cout << endl;

    // Find aimIndex
    for (unsigned int i = 0; i < players.size(); i++) {
        if (players.at(i) == jersey) {
            aimIndex = i;
        }
    }

    // Change player rating
    ratings.at(aimIndex) = newRating;
}

// Outputs players above a certain specified rating
void OutputPlayersAboveRating(const vector<int>& players, const vector<int>& ratings) {
    int userRating;
    
    // Prompt user input
    cout << "Enter a rating: ";
    cin >> userRating;
    cout << endl << endl;

    // Iterate through the vectors, output only if the rating of
    // the player is more than specified.
    cout << "ABOVE " << userRating << endl;
    for (unsigned int i = 0; i < players.size(); i++) {
        if (ratings.at(i) > userRating) {
            cout << "Player " << i + 1 << " -- ";
            cout << "Jersey number: " << players.at(i) << ", ";
            cout << "Rating: " << ratings.at(i) << endl;
        }
    }
}