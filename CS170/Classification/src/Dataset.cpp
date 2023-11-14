#include "../headers/Dataset.hpp"

#include <iostream> // testing
#include <cmath>

/* Accessors */

std::vector<Point*> Dataset::dataset() const {
    return this->_dataset;
}

std::vector<std::string> Dataset::column_names() const {
    return this->_column_names;
}

int Dataset::columns() const {
    return this->_columns;
}

int Dataset::rows() const {
    return this->_rows;
}

int Dataset::cells() const {
    return this->_cells;
}

/* Modifiers */

void Dataset::slice(int s, int e) { // Both inclusive
    
    std::vector<Point*> dataset;

    // Bounds
    if (s < 0) { s = 0; }
    if (e > this->_dataset.size() - 1) { e = this->_dataset.size() - 1; }

    for (int i = s; i <= e; i++) {
        std::vector<double> row = this->_dataset.at(i)->data;
        Point* pointO = new Point(row);
        dataset.push_back(pointO);
    }

    for (int i = 0; i < this->_dataset.size(); i++) {
        delete this->_dataset.at(i);
    }
    this->_dataset.clear();
    this->_dataset = dataset;
}

void Dataset::dataset(std::vector<std::vector<double>> data) {
    this->_dataset.clear();
    for (int i = 0; i < data.size(); i++) {
        Point* pointO = new Point(data.at(i));
        this->_dataset.push_back(pointO);
    }
}

void Dataset::addRow(Point* point) {
    this->_dataset.push_back(point);
    this->_rows++;
    this->_columns = point->data.size();
    this->_cells = this->_rows * this->_columns;
}

void Dataset::addRow(std::vector<double> vctr) {
    Point* pointO = new Point(vctr);
    this->_dataset.push_back(pointO);
    this->_rows++;
    this->_columns = pointO->data.size();
    this->_rows = this->_rows * this->_columns;
}

void Dataset::column_names(std::vector<std::string> names) {
    this->_column_names = names;
}

void Dataset::columns(int cols) {
    this->_columns = cols;
}

void Dataset::rows(int rows) {
    this->_rows = rows;
}

void Dataset::cells(int cells) {
    this->_cells = cells;
}

void Dataset::normalize() {
    /*
    We iterate through every point only once, keeping track
    of a rolling mean and a rolling standard deviation.

    This runs in O(2n). We run through the data once to get
    the mean and variance. Then we run through it again to
    normalize the values.
    */

    std::vector<double> rollingMeans(this->_columns - 1);
    for (int j = 0; j < rollingMeans.size(); j++) { // Initialize rolling means
        rollingMeans.at(j) = this->_dataset.at(0)->data.at(j+1);
    }

    std::vector<double> rollingVars(this->_columns - 1);
    for (int j = 0; j < rollingVars.size(); j++) {
        rollingVars.at(j) = 0;
    }

    // For every column except the label
    for (int i = 1; i < this->_rows; i++) {
        // Iterate through every column except the label column.
        Point* point = this->_dataset.at(i); // Current point
        int count = i + 1;
        for (int j = 0; j < rollingMeans.size(); j++) {
            double oldMean = rollingMeans.at(j);
            // Formula provided by @Henry https://math.stackexchange.com/questions/106700/incremental-averaging/106720#106720
            double newMean = oldMean + (point->data.at(j+1) - oldMean) / (count * 1.0);
            rollingMeans.at(j) = newMean;

            double oldVar = rollingVars.at(j);
            // Formula provided by @secfree https://math.stackexchange.com/questions/102978/incremental-computation-of-standard-deviation
            double newVar = (count - 2)/((count - 1)*1.0)*oldVar + (1/(count*1.0)) * (point->data.at(j+1) - oldMean) * (point->data.at(j+1) - oldMean);
            rollingVars.at(j) = newVar;
        }
    }

    // Actually normalize the data
    // For every column except the label
    for (int i = 0; i < this->_rows; i++) {
        // Iterate through every column except the label column.
        Point* point = this->_dataset.at(i); // Current point
        for (int j = 0; j < rollingMeans.size(); j++) {
            point->data.at(j+1) = (point->data.at(j+1) - rollingMeans.at(j)) / (std::sqrt(rollingVars.at(j))*1.0); 
        }
    }

}