#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <vector>

/*
    Point class stores a single point with a vector of data that stores a "row" in an encompassing dataset. It
    can be thought of as a row in a spreadsheet.
*/
struct Point {

    /* Add some members */

    std::vector<double> data; // Stores the features
    int label;                    // Stores the label of the point, the actual target label
    int num_features;             // Stores the number of features

    /* Constructors */

    Point() :
        data(std::vector<double>(0)),
        label(-1.00),
        num_features(-1.00) {};
    Point(std::vector<double> vctr) :
        data(vctr),
        label(vctr.at(0)),
        num_features(data.size()) {};
};

#endif