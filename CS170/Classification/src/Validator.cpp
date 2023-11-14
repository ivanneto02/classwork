#include "../headers/Validator.hpp"

#include <iostream>
#include <iomanip>

/* Constructors */

Validator::Validator() {
    this->_dataset = nullptr;
    this->_features = std::vector<int>(0);
    this->_classifier = nullptr;
}

Validator::Validator(
    std::vector<int> features,
    NearestNeighbors* classifier,
    Dataset* dataset)
{

    this->_dataset = dataset;
    this->_features = features;
    this->_classifier = classifier;
}

/* Modifiers */

void Validator::features(std::vector<int> features) {
    this->_features = features;
}

void Validator::classifier(NearestNeighbors* classifier) {
    this->_classifier = classifier;
}

void Validator::dataset(Dataset* dataset) {
    this->_dataset = dataset;
}

/* Accessors */

double Validator::accuracy() const {

    // Separate by features
    Dataset* train = this->_classifier->train();
    // std::cout << "here5" << std::endl;

    Dataset* newtrain = new Dataset();
    // std::cout << "here6" << std::endl;

    // Iterate through every point
    for (int i = 0; i < train->dataset().size(); i++) {
        // std::cout << " here-" << i << std::endl;
        std::vector<double> relevant;
        int feature;
        Point* point = train->dataset().at(i);
        relevant.push_back(point->data.at(0));

        // Iterate through the point itself
        for (int j = 0; j < point->data.size(); j++) {
            // Iterate through features
            for (int k = 0; k < this->_features.size(); k++) {
                // Check if feature of point is in feature vector to slice
                if (j == this->_features.at(k)) {
                    relevant.push_back(point->data.at(j));
                    break;
                }
            }
        }

        Point* newPoint = new Point(relevant);
        // std::cout << "here7" << std::endl;
        newtrain->addRow(newPoint);
        // std::cout << "here8" << std::endl;
    }

    int cor = 0;
    int total = 0;

    // Perform leave one out validation
    for (int i = 0; i < newtrain->dataset().size(); i++) {
        // Test point
        // std::cout << "here9" << std::endl;
        Point* test = newtrain->dataset().at(i);

        // std::cout << "here10" << std::endl;

        Dataset* trainset = new Dataset();
        // std::cout << "here11" << std::endl;
        for (int j = 0; j < newtrain->dataset().size(); j++) {
            if (j == i) {
                continue;
            }
            Point* toAdd = new Point(newtrain->dataset().at(j)->data);
            // std::cout << "here12" << std::endl;
            trainset->addRow(toAdd);
            // std::cout << "here13" << std::endl;
        }

        this->_classifier->train(trainset, this->_classifier->k());
        // std::cout << "here14" << std::endl;

        double classification = this->_classifier->test(test);
        // std::cout << "here15" << std::endl;

        if (classification == test->data.at(0)) {
            cor++;
        }
        // std::cout << "here16" << std::endl;

        total++;
    }
    // std::cout << "here17" << std::endl;
    return cor / (total*1.00);
}

std::vector<int> Validator::features() const {
    return this->_features;
}

NearestNeighbors* Validator::classifier() const {
    return this->_classifier;
}

Dataset* Validator::dataset() const {
    return this->_dataset;
}