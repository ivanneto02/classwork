#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>
#include "Subset.hpp"

/*
I originally made this class for the feature selection algorithm. It acts as the "Graph" of features
that we are using to execute one of our two greedy hill-climb search algorithms.

TLDR: This class is redundant in Part 2. Only needed in Part 1.
*/
class Graph {

    private: // Members
        int size;
        int height;
        int feature_size;

        Subset* root;

    public:
        /* Constructors*/

        // Default constructor
        Graph();
        // Constructor taking number of features
        Graph(int);

        /* Accessors */
        
        // Returns the size
        int getSize() const { return this->size; }
        // Returns the height
        int getHeight() const { return this->height; }
        // Returns the number of features
        int getFeatureSize() const { return this->feature_size; }
        // Returns the root Subset*
        Subset* getRoot() const { return this->root; }

        /* Modifiers */

        // Changes the root Subset*
        void setRoot(Subset* root) { this->root = root; }
};

#endif