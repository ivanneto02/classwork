#ifndef __FULLDRIVER_HPP__
#define __FULLDRIVER_HPP__

#include <set>
#include <vector>
#include "Subset.hpp"
#include "Graph.hpp"
#include "Dataset.hpp"

class FullDriver {

    private: // Members
        std::set<std::vector<int>> curr_subsets_v;
        std::set<Subset*> curr_subsets_s;

        int feature_size;
        double found_acc;
        double curr_acc;
        double next_acc;

        Dataset* data_subset;
        Dataset* data;

    public:
        /* Constructors */
        FullDriver();

        /* Accessors */

        /* Modifiers */
        void run();

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
        // Expands a Subset* forward (adding a feature)
        void expand_for(Subset*);
        // Expands a Subset* backward (subtracting a feature)
        void expand_bac(Subset*);

    private: // Helpers

};

#endif