#ifndef __DATASET_HPP__
#define __DATASET_HPP__

#include <vector>
#include <string>
#include "Point.hpp"

/*
    Dataset class stores a spreadsheet. The member that includes the actual data is `dataset`, which stores many
    pointers to all of the rows in the spreadsheet.
*/
class Dataset {

    private: // Members
        std::vector<Point*> _dataset;
        std::vector<std::string> _column_names;
        int _columns;
        int _rows;
        int _cells;

    public:
        /* Constructors */

        // Default Constructor
        Dataset() :
            _dataset(std::vector<Point*>(0)),
            _column_names(std::vector<std::string>(0)),
            _columns(0),
            _rows(0),
            _cells(0*0) {};

        /* Accessors */

        /* Returns member _dataset : vector<Point*> */
        std::vector<Point*> dataset() const;
        /* Returns member _column_names : vector<std::string> */
        std::vector<std::string> column_names() const;
        /* Returns member _columns : int */
        int columns() const;
        /* Returns member _rows : int */
        int rows() const;
        /* Returns member _cells : int */
        int cells() const;

        /* Modifiers */

        // int : start, int : end
        void slice(int, int);
        // Modifies _dataset
        void dataset(std::vector<std::vector<double>>); // Might be redundant
        // Adds a row to dataset based on a Point*
        void addRow(Point*);
        // Adds a row to dataset based on a vector of doubles (label + features)
        void addRow(std::vector<double>);
        // Modifies the column names
        void column_names(std::vector<std::string>);
        // Modifies the number of columns
        void columns(int);
        // Modifies the number of rows
        void rows(int);
        // Modifies the number of cells
        void cells(int);
        // Normalizes the data
        void normalize();
};

#endif