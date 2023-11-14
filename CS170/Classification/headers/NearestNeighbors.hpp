#ifndef __NEARESTNEIGHBORS_HPP__
#define __NEARESTNEIGHBORS_HPP__

#include "Dataset.hpp"
#include "Validator.hpp"
#include "Point.hpp"

class Validator;

/*
This class stores the performance of the NearestNeighbors classifier for the dataset.
*/
class NearestNeighbors {

    private: // Members
        Dataset* _train;
        int _k;

    public:
        /* Constructors */

        NearestNeighbors();
        NearestNeighbors(Dataset*);

        /* Accessors */

        // Returns the training dataset
        Dataset* train() const;
        // Test the classifier based on entire dataset
        std::vector<double> test(Dataset*) const;
        // Test the classifier based on single point
        double test(Point*) const;
        // Returns k
        int k() const;

        /* Modifiers */

        // Trains the NearestNeighbors model
        void train(Dataset*, int);
        // Modifies k
        void k(int);

    private: // Helpers
        // Euclidean distance between two points
        double euclidean(Point*, Point*) const;
        // Evaluates which class wins
        double eval(std::vector<Point*>) const;
};

#endif