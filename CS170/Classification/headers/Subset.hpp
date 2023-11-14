#ifndef __SUBSET_HPP__
#define __SUBSET_HPP__

#include <string>

/*
This class acts as the node class for our Graph class. It contains the feature subset, as well as its
children. The children are dependent on what exact algorithm (and thus expand function) we are using.
The forward expansion function makes the children be nodes with exactly ONE more feature from all
available features. And the backward expansion function makes the children be nodes with exactly ONE less
feature from the current node's features.

TLDR: This class is redundant for Part 2. We only need it for Part 1.
*/
struct Subset {
    /* Members */

    std::vector<int> subset;
    std::vector<Subset*> children;

    /* Constructors */

    // Default constructor
    Subset() : subset(std::vector<int>(0)), eval(-1.00) {};

    // Constructor that takes in the subset as a vector
    Subset(std::vector<int> s) : subset(s), eval(-1.00) {};

    // Evaluation of the current Subset*
    double eval;
};

#endif