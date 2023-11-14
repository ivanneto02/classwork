#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__

#include <set>
#include <vector>
#include "Subset.hpp"
#include "Graph.hpp"

/*
This class originally drover part1 of the project, which was the feature selection algorithms that we used
in order to select a subset of features that our NearestNeighbors algorithm would perform in the future.
The evaluation function that you see in this class simply returns a random double from 0.00 to 100.00, which
is interpreted as the accuracy by the feature selection algorithm. Since part2 is quite a separate algorithm,
I made a separate ClassifierDriver class that drives JUST part2. In the future, I will merge ClassifierDriver and
Driver to make a new `ClassifierDriver` that drives the entire project, including the feature selection.

**TLDR: This class is redundant in Part 2. Only needed for Part 1.
*/
class Driver {

    private:
        std::set<std::vector<int>> curr_subsets_v;
        std::set<Subset*> curr_subsets_s;

        int feature_size;
        double found_acc;
        double curr_acc;
        double next_acc;

    public:
        /* Constructors */

        // Default constructor
        Driver();

        /* Accessors */

        // Returns the evaluation of a Subset of features
        double evaluation(Subset*) const;
        // Outputs the choice for users to make in order to take in subset of features
        void outputChoices() const;

        /* Modifiers */

        // Performs Greedy Forward Selection algorithm for the feature subset
        Subset* forward(Graph*);
        // Performs Greedy Backward Selection algorithm for the feature subset
        Subset* backward(Graph*);
        // Runs the Driver
        void run();
        // Expands a Subset* forward (adding a feature)
        void expand_for(Subset*);
        // Expands a Subset* backward (subtracting a feature)
        void expand_bac(Subset*);
};

#endif