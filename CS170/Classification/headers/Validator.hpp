#ifndef __VALIDATOR_HPP__
#define __VALIDATOR_HPP__

#include "Dataset.hpp"
#include "NearestNeighbors.hpp"

class NearestNeighbors;

/*
This class is purposed towards creating both (1) the evaluation function that determines what accuracy
certain features subsets have on the training data, and (2) the accuracy of the NN-classifier given
a specific feature subset. (1) is meant for the search function, whereas (2) is only specific for
Part 2, since we won't be implementing feature search yet.

*/
class Validator {

    private: // Members
        std::vector<int> _features;
        Dataset* _dataset;
        NearestNeighbors* _classifier;

    public:
        /* Constructors */
        
        // Default constructor
        Validator();
        // Constructor based on inputs to the validator.
        Validator(std::vector<int>, NearestNeighbors*, Dataset*);

        /* Accessors */

        // Returns the accuracy, main method
        double accuracy() const;
        // Returns the features
        std::vector<int> features() const;
        // Returns the classifier
        NearestNeighbors* classifier() const;
        // Returns the dataset
        Dataset* dataset() const;

        /* Modifiers */

        // Modifies the _accuracy member
        void features(std::vector<int>);
        // Modifies the classifier
        void classifier(NearestNeighbors*);
        // Modifies the dataset
        void dataset(Dataset*);
};

#endif