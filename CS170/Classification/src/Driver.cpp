#include "../headers/Driver.hpp"
#include "../headers/Subset.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

Driver::Driver() {}

Subset* Driver::backward(Graph* problem) {
    Subset* next = nullptr;
    Subset* curr = problem->getRoot();

    int max_accuracy = 0.00;

    // Iterate until we find the needed subset
    while(true) {

        std::vector<int> empty = {};
        if (curr->subset == empty) {
            return nullptr;
        }

        double curr_node_eval;
        if (curr->eval == -1.00) {
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

        this->expand_bac(curr);

        for (int i = 0; i < curr->subset.size(); i++) {
            double curr_eval = this->evaluation(curr->children.at(i));

            if (curr_eval > max_val) {
                max_val = curr_eval;
                next = curr->children.at(i);
            }
        }
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
        curr = next;
        max_accuracy = max_val;
        curr->eval = max_val;
    }

    return nullptr;
}

Subset* Driver::forward(Graph* problem) {
    Subset* next = nullptr;
    Subset* curr = problem->getRoot();

    int total_layer_len = problem->getFeatureSize();
    double max_accuracy = 0.00;

    // Iterate until we find the needed subset
    while(true) {

        double curr_node_eval;
        if (curr->eval == -1.00) {
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
        // Try every operator
        this->expand_for(curr);

        for (int i = 0; i < total_layer_len - curr_layer_len; i++) {
            
            double curr_eval = this->evaluation(curr->children.at(i));

            if (curr_eval > max_val) {
                max_val = curr_eval;
                next = curr->children.at(i);
            }
        }
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
        curr = next;
        max_accuracy = max_val;
        curr->eval = max_val;
    }

    return nullptr;
}

double Driver::evaluation(Subset* curr) const {
    // Function stub pretty much, later will actually be a NN
    // evaluation.
    return std::sqrt((double)rand() / RAND_MAX) * 100;
}

void Driver::outputChoices() const {\
    std::cout << "  (1) - Greedy Forward Selection\n"
              << "  (2) - Greedy Backward Selection\n";
}

void Driver::run() {
    srand(time(0));
    // Prompt the user
    int features;
    int choice;
    std::cout << "============================================================================" << std::endl;
    std::cout << "Welcome to Project 2 Part 1!" << std::endl;

    std::cout << "\nInput the number of features: ";
    std::cin >> features;
    std::cout << std::endl;

    this->outputChoices();

    std::cout << "\nInput your desired feature selection algorithm: ";
    std::cin >> choice;
    std::cout << std::endl;

    // Set number of features
    this->feature_size = features;

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

    std::cout << "============================================================================" << std::endl;
}

void Driver::expand_for(Subset* curr) {

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

}

void Driver::expand_bac(Subset* curr) {

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