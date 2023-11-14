#include "../headers/Problem.hpp"
#include "../headers/HeuristicStrategy.hpp"

Problem::Problem() {

    // Default node
    this->root = new Board();
    this->_height = 1;
    this->_size = 1;
    this->_heuristic = 1;
}

Problem::Problem(Board* root) {

    this->root = root;
    this->_height = 1;
    this->_size = 1;
    this->_heuristic = 1;
}

/*
This function expands a Board node given a board of arbitrary, unique positive
integers, with a zero denoting the "empty" spot.

Assumptions for this function:
    - Single empty spot in entire board
    - Unique positive integers
    - Square n x n board, not n x m (rectangular)
*/
void Problem::expand(Board* node) {
    
    // expand the node
    node->expand();

    for (int i = 0; i < 4; i++) {
        node->getChild(i)->setParent(node);
        node->getChild(i)->setDepth(node->getDepth() + 1);
        node->getChild(i)->setCost(node->getCost() + 1);
        node->getChild(i)->setContext(this);
    }
	
}

int Problem::depthOf(Board* board) const {
    return board->getDepth();
}

int Problem::heightOf(Board* board) const {
    return -999;
}

int Problem::heuristicOf(Board* board) const {

    Heuristic* strat;
    // std::cout << "calculating heuristic..." << std::endl;

    if(this->_heuristic == 1) {
        // std::cout << "uniform..." << std::endl;
        strat = new UniformCostHeuristic();
    }
    else if (this->_heuristic == 2) {
        // std::cout << "misplaced..." << std::endl;
        strat = new MisplacedTileHeuristic();
    }
    else if (this->_heuristic == 3) {
        // std::cout << "euclidean..." << std::endl;
        strat = new EuclideanHeuristic();

    }
    else {
        // std::cout << "uniform2..." << std::endl;
        strat = new UniformCostHeuristic();
    }

    return board->heuristic(strat);
}