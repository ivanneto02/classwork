#include "../headers/ClassifierDriver.hpp"
#include "../headers/Dataset.hpp"
#include "../headers/NearestNeighbors.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>

ClassifierDriver::ClassifierDriver() {

}

void ClassifierDriver::run() {
    std::cout << "=============================================================\n"
              << "Welcome to the Nearest Neighbor Classifier part of Project 2.\n\n"
              << "This project is meant for Part 2 of Project 2. Essentially what\n"
              << "this program can do is take in a dataset given by the format of\n"
              << "the project, and both (1) train a Nearest Neighbors classifier,\n"
              << "based on some number of data points, then (2) test the classifier\n"
              << "with some test samples.\n";

    // Variables
    std::string data;
    int rows;

    std:srand(std::time(0));

    // Taking in user input
    std::cout << "\nInput the name of the dataset: ";
    std::cin >> data;
    std::cout << "\n(purposely redundant for Part2) Input the number of rows to train (rest will be used for testing later on): ";
    std::cin >> rows;
    std::cout << std::endl;

    // Creating dataset
    Dataset* dataset = new Dataset();

    /* Gathering dataset */

    std::ifstream infil; // input file stream
    std::istringstream instr; // input string stream

    infil.open(data); // Open file

    // Problem reading in data
    if (!infil.is_open()) {
        std::cout << "Problem reading in file \"" << data << ".\"" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infil, line)) { // While able to read in line
        double num;
        std::vector<double> point;
        // Set stringstream to have line as its string
        instr.str(line);
        // Iterate through instr and get every double.
        while (instr >> num) {
            // Add to point vector
            point.push_back(num);
        }
        Point* pointO = new Point(point);
        pointO->label = point.at(0);
        pointO->num_features = point.size() - 1;

        dataset->addRow(pointO);
        instr.clear();
    }

    std::cout << "\"" << data << "\"" << " information:\n"
              << "  - rows: " << dataset->rows() << "\n"
              << "  - cols: " << dataset->columns() << "\n"
              << "  - cells: " << dataset->cells() << "\n"
              << "  - features: " << dataset->columns() - 1 << std::endl; 

    dataset->normalize();

    // Create feature subset, for now we have just given features.
    // later we allow the user to pick the feature subset, and
    // also are able to search for best feature subsets ourselves.
    int featureNum = 0;

    std::cout << "Input the number of features you would like to test (min=1, max=" << (dataset->columns() - 1) << "): ";
    std::cin >> featureNum;
    std::cout << std::endl;

    std::vector<int> features(featureNum);

    std::cout << "Input the features (min=1, max=" << (dataset->columns() - 1) << ")." << std::endl;
    std::cout << "Enter separated by \" \": ";
    for (int i = 0; i < featureNum; i++) {
        std::cin >> features.at(i);
    }
    std::cout << std::endl;

    NearestNeighbors* classifier = new NearestNeighbors(dataset);
    classifier->train(dataset, 1);
    Validator* validator = new Validator(features, classifier, dataset);

    std::cout << "* Evaluating..." << std::endl;

    std::cout << "Accuracy of the model using features \{";
    for (int i = 0; i < features.size(); i++) {
        if (i == features.size() - 1) {
            std::cout << features.at(i);
            break;
        }
        std::cout << features.at(i) << " ";
    }

    std::cout << "}: " << std::fixed << std::setprecision(4) << validator->accuracy() << std::endl;

    std::cout << "=============================================================\n";

    return;
}