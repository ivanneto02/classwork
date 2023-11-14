#include "../headers/FullDriver.hpp"
#include "../headers/Subset.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include "../headers/NearestNeighbors.hpp"
#include "../headers/Validator.hpp"
#include "../headers/Dataset.hpp"
#include <sstream>
#include <fstream>

FullDriver::FullDriver() {}

Subset* FullDriver::backward(Graph* problem) {
    Subset* next = nullptr;
    Subset* curr = problem->getRoot();

    int max_accuracy = 0.00;

    // std::cout << "here4" << std::endl;

    // Iterate until we find the needed subset
    while(true) {

        std::vector<int> empty = {};
        if (curr->subset == empty) {
            return nullptr;
        }

        double curr_node_eval;
        if (curr->eval == -1.00) {
            // std::cout << "here5" << std::endl;
            curr_node_eval = this->evaluation(curr);
        }
        else {
            curr_node_eval = curr->eval;
        }

        // Output current node's subset
        std::cout << std::setprecision(4);
        std::cout << "curr: {";
        for (int i = 0; i < curr->subset.size(); i++) {
            if (i == curr->subset.size() - 1) {
                std::cout << curr->subset.at(i);
                break;
            }
            std::cout << curr->subset.at(i) << ", ";
        }
        std::cout << "} _acc: (" << curr_node_eval << "%)" << std::endl;

        int curr_layer_len = curr->subset.size();

        double max_val = 0;

        // std::cout << "here6" << std::endl;

        this->expand_bac(curr);

        // std::cout << "here7" << std::endl;

        for (int i = 0; i < curr->subset.size(); i++) {
            double curr_eval = this->evaluation(curr->children.at(i));
            // std::cout << " - here" << i << std::endl;

            if (curr_eval > max_val) {
                max_val = curr_eval;
                next = curr->children.at(i);
            }
        }
        // print out highest next
        // std::cout << "here8" << std::endl;
        std::cout << "  next: {"; 
        for (int i = 0; i < next->subset.size(); i++) {
            if (i == next->subset.size()-1) {
                std::cout << next->subset.at(i);
                break;
            }
            std::cout << next->subset.at(i) << ", ";
        }
        // std::cout << "here9" << std::endl;
        std::cout << "} _acc: (" << max_val << "%)" << " - [";

        if (max_val < curr_node_eval) {
            std::cout << "DONE]\n" << std::endl;
            max_accuracy = curr_node_eval;
            this->found_acc = max_accuracy;
            return curr;
        }
        std::cout << "MOVING]\n" << std::endl;
        curr = next;
        max_accuracy = max_val;
        curr->eval = max_val;
    }

    return nullptr;
}

Subset* FullDriver::forward(Graph* problem) {
    // std::cout << "here-1" << std::endl;
    Subset* next = nullptr;
    Subset* curr = problem->getRoot();

    int total_layer_len = problem->getFeatureSize();
    double max_accuracy = 0.00;

    // std::cout << "here-2" << std::endl;

    // Iterate until we find the needed subset
    while(true) {

        double curr_node_eval;
        if (curr->eval == -1.00) {
            curr_node_eval = this->evaluation(curr);
            // std::cout << "here3" << std::endl;
        }
        else {
            // std::cout << "*here" << std::endl;
            curr_node_eval = curr->eval;
        }
        // Output current node's subset
        std::cout << std::setprecision(4);
        std::cout << "curr: {";
        for (int i = 0; i < curr->subset.size(); i++) {
            if (i == curr->subset.size() - 1) {
                std::cout << curr->subset.at(i);
                break;
            }
            std::cout << curr->subset.at(i) << ", ";
        }
        std::cout << "} _acc: (" << curr_node_eval << "%)" << std::endl;

        // std::cout << "here4" << std::endl;

        int curr_layer_len = curr->subset.size();

        // std::cout << "here5" << std::endl;

        double max_val = 0;
        // Try every operator
        this->expand_for(curr);

        // std::cout << "here6" << std::endl;

        for (int i = 0; i < total_layer_len - curr_layer_len; i++) {
            
            // std::cout << "here7" << std::endl; std::cout << "" << std::endl;

            double curr_eval = this->evaluation(curr->children.at(i));
            // std::cout << "here8" << std::endl;

            if (curr_eval > max_val) {
                max_val = curr_eval;
                next = curr->children.at(i);
            }
        }

        std::cout << std::endl;

        // print out highest next
        std::cout << "  next: {"; 
        for (int i = 0; i < next->subset.size(); i++) {
            if (i == next->subset.size()-1) {
                std::cout << next->subset.at(i);
                break;
            }
            std::cout << next->subset.at(i) << ", ";
        }
        std::cout << "} _acc: (" << max_val << "%)" << " - [";

        if (max_val < curr_node_eval) {
            std::cout << "DONE]\n" << std::endl;
            max_accuracy = curr_node_eval;
            this->found_acc = max_accuracy;
            return curr;
        }
        std::cout << "MOVING]\n" << std::endl;
        // std::cout << "here9" << std::endl;
        curr = next;
        max_accuracy = max_val;
        curr->eval = max_val;
    }

    return nullptr;
}

double FullDriver::evaluation(Subset* curr) const {
    // Function stub pretty much, later will actually be a NN
    // evaluation.

    NearestNeighbors* classifier = new NearestNeighbors(this->data);
    // std::cout << "evalhere1" << std::endl;
    classifier->train(this->data, 1);
    // std::cout << "evalhere2" << std::endl;
    Validator* validator = new Validator(curr->subset, classifier, this->data);
    // std::cout << "evalhere3" << std::endl;

    // This part is taking a while
    double acc = validator->accuracy();
    // std::cout << "evalhere4" << std::endl;

    return acc;
}

void FullDriver::outputChoices() const {\
    std::cout << "  (1) - Greedy Forward Selection\n"
              << "  (2) - Greedy Backward Selection\n"
              << "  (3) - Custom ((secret)) Algorithm\n";
}

void FullDriver::run() {
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

    std::cout << "\nNormalizing data...\n" << std::endl;
    dataset->normalize();

    // Set the dataset
    this->data = dataset;

    // Ask for the algorithm to use
    this->outputChoices();

    int choice;

    std::cout << "\nInput your desired feature selection algorithm: ";
    std::cin >> choice;
    std::cout << std::endl;

    this->feature_size = dataset->columns() - 1;

    std::cout << "Evaluating..." << std::endl;
    // Make problem based on choice
    Graph* myProblem = new Graph(this->feature_size);
    std::vector<int> probRoot = {};
    switch (choice) {
        case 1:
            myProblem->setRoot(new Subset(probRoot));
            break;
        case 2:
            for (int i = 1; i < feature_size + 1; i++) {
                probRoot.push_back(i);
            }
            myProblem->setRoot(new Subset(probRoot));
            break;
        default:
            myProblem->setRoot(new Subset(probRoot));
            break;
    }

    // Create result based on user choice
    Subset* result;
    switch (choice) {
        case 1:
            result = this->forward(myProblem);
            break;
        case 2:
            result = this->backward(myProblem);
            break;
        default:
            result = this->forward(myProblem);
            break;
    }

    // Check if we found result
    if (result != nullptr) {
        std::cout << "Solution found!\n\n";
        std::cout << "The ideal feature subset is {";
        // Print the subet
        for (int i = 0; i < result->subset.size(); i++) {
            if (i == result->subset.size() - 1) {
                std::cout << result->subset.at(i);
                break;
            }
            std::cout << result->subset.at(i) << ", ";
        }
        // Move along
        std::cout << "}" << std::endl;
        std::cout << "- Accuracy: " << this->found_acc << "%" << std::endl;
    }
    else {
        std::cout << "No solution was found.\n";
        std::cout << "We shouldn't be here..." << std::endl;
    }

    std::cout << "=============================================================\n";

    return;;
}

void FullDriver::expand_for(Subset* curr) {

    for (int i = 1; i < this->feature_size + 1; i++) {

        // Check in curr
        bool isin = false;
        for (int j = 0; j < curr->subset.size(); j++) {
            if (curr->subset.at(j) == i) {
                isin = true;
                break;
            }
        }
        // If we find this number in curr
        if (isin) {
            continue;
        }

        // If we haven't found i in curr
        std::vector<int> toAdd = curr->subset;
        // Add the feature
        toAdd.push_back(i);
        // Sort the vector
        std::sort(toAdd.begin(), toAdd.end());

        // If we don't find this subset in curr_subsets
        std::set<std::vector<int>>::iterator find_in_curr = this->curr_subsets_v.find(toAdd);
        if (find_in_curr == this->curr_subsets_v.end()) {
            // Push toAdd onto the seen subset vectors
            this->curr_subsets_v.insert(toAdd);
            // Make new Subset of vector to add
            Subset* toAddSub = new Subset(toAdd);
            // Pushback new Subset
            curr->children.push_back(toAddSub);
            // Push toAddSub onto the seen Subset objects
            this->curr_subsets_s.insert(toAddSub);
        }
        else { // We HAVE found this subset in curr_subsets
            // Find it in the actual vector of Subset*s
            for (std::set<Subset*>::iterator it = this->curr_subsets_s.begin(); it != this->curr_subsets_s.end(); it++) {
                if ((*it)->subset == toAdd) {
                    curr->children.push_back(*it);
                    break;
                }
            }

        }

    }

    // std::cout << "done expanding" << std::endl; 
}

void FullDriver::expand_bac(Subset* curr) {

    // Iterate through features currently in vector
    for (int i = 0; i < curr->subset.size(); i++) {
        std::vector<int> pos_child = {};
        // Add every number but i
        for (int j = 0; j < curr->subset.size(); j++) {
            if (j == i) {
                continue;
            }
            pos_child.push_back(j+1);
        }
        // Check if possible child is in subset
        std::set<std::vector<int>>::iterator it = this->curr_subsets_v.find(pos_child);
        // We have found this child in the vector subsets, so we don't add
        if (it != this->curr_subsets_v.end()) {
            continue;
        }
        // We have NOT found this child in the vector subsets, so we add
        // Create new subset
        Subset* child = new Subset(pos_child);
        curr->children.push_back(child);
        this->curr_subsets_s.insert(child);
        this->curr_subsets_v.insert(pos_child);
    }

}