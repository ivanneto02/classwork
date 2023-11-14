#include "../headers/NearestNeighbors.hpp"
#include <cmath>
#include <utility>
#include <random>
#include <iostream>

/* Constructors */

NearestNeighbors::NearestNeighbors() {}

NearestNeighbors::NearestNeighbors(Dataset* dataset) {}

/* Modifiers */

void NearestNeighbors::train(Dataset* trainset, int k) {
    this->_train = trainset;
    this->_k = k;
}

double NearestNeighbors::test(Point* point) const {

    std::vector<Point*> trainpoints = this->_train->dataset();

    std::vector<double> sortedD;
    std::vector<Point*> sortedP;

    // Check every training point
    for (int i = 0; i < trainpoints.size(); i++) {
        
        // Calculate distance
        Point* pointTr = trainpoints.at(i);

        double dist = this->euclidean(point, pointTr);

        // Make iterator to move through pairs
        int j = 0;
        while (j < sortedD.size()) {
            if (dist <= sortedD.at(j)) {
                break;
            }
            j++;
        }

        sortedD.insert(sortedD.begin() + j, dist);
        sortedP.insert(sortedP.begin() + j, pointTr);
    }

    // Find the nearest k points
    std::vector<Point*> nearest;
    for (int i = 0; i < this->_k; i++) {
        nearest.push_back(sortedP.at(i));
    }

    // Classify the current test point
    return this->eval(nearest);
}

// This does not work for now
std::vector<double> NearestNeighbors::test(Dataset* testset) const {
    
    // // Check every single train point for every test point
    // // If there are n training instances and m testing instances,
    // // this runs in O(m*n).

    // // Get pointer to vector of test points
    // std::vector<Point*>* testpoints = &testset->dataset();
    // std::vector<Point*>* trainpoints = &this->_train->dataset();

    // std::vector<std::pair<double, Point*>> sorted(this->_k);

    // // Iterate through every test point
    // for (int i = 0; i < testpoints->size(); i++) {

    //     // Check every training point
    //     for (int j = 0; j < trainpoints->size(); j++) {
            
    //         // Calculate distance
    //         Point* point = trainpoints->at(j);
    //         double dist = this->euclidean(testpoints->at(i), point);
    //         // Make iterator to move through pairs
    //         std::vector<std::pair<double, Point*>>::iterator it;
    //         for (it = sorted.begin(); it != sorted.end(); it++) {
    //             if (dist >= (*it).first) {
    //                 break;
    //             }
    //         }
    //         sorted.insert(it, std::make_pair(dist, point));
    //     }

    //     // Find the nearest k points
    //     std::vector<Point*> nearest;
    //     for (int j = 0; j < this->_k; j++) {
    //         nearest.push_back(sorted.at(i).second);
    //     }

    //     // Classify the current test point
    //     double classification = this->eval(nearest);


    //     sorted.clear();
    // }
    return std::vector<double>(0);

}

void NearestNeighbors::k(int k) {
    this->_k = k;
}

/* Accessors */

Dataset* NearestNeighbors::train() const {
    return this->_train;
}

int NearestNeighbors::k() const {
    return this->_k;
}

/* Helpers */

double NearestNeighbors::euclidean(Point* p1, Point* p2) const {

    // Sum of squares
    double sum = 0.00;
    // std::cout << "size1: " << p1->data.size() << std::endl;
    // std::cout << "size2: " << p2->data.size() << std::endl;
    for (int i = 1; i < p1->data.size(); i++) {
        double fir = p1->data.at(i);
        double sec = p2->data.at(i);
        sum += (fir - sec)*(fir - sec);
    }

    // Return the square root (euclidean distance).
    return std::sqrt(sum);
}

double NearestNeighbors::eval(std::vector<Point*> nearest) const {

    int one = 0;
    int two = 0;
    for (int i = 0; i < nearest.size(); i++) {
        int label = nearest.at(i)->data.at(0);
        switch (label) {
            case 1:
                one++;
                break;
            case 2:
                two++;
                break;
            default:
                std::cout << "Error." << std::endl;
                std::cout << label << std::endl;
                break;
        }
    }

    // std::cout << one << std::endl;
    // std::cout << two << "\n" << std::endl;

    if (one > two) { // more 1's
        return 1.00;
    }
    else if (two > one) { // more 2's
        return 2.00;
    }
    else {
        // Randomly choose 1 or 2.
        int sel = std::rand() % (2-1 + 1) + 1;
        return sel;
    }

}