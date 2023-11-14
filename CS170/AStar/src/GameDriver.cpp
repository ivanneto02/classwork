#include "../headers/GameDriver.hpp"

GameDriver::GameDriver() {
    this->goal = nullptr;
    this->count = 0;
     
}

/* Can run AStar and Uniform Cost Search */
Board* GameDriver::graphSearch(Problem* problem) {

    // Initialize the frontier using the initial state of problem
    this->frontier.push(problem->getRoot());
    this->frontier_set.insert(problem->getRoot()->getMat());

    // Tracking max frontier length
    if (this->frontier.size() > this->maxFrontierLength) {
        this->maxFrontierLength = this->frontier.size();
    }

    // loop do
    while (true) {

        // If frontier is empty, then return failure
        if (this->frontier.size() == 0) { return nullptr; }

        // Pick the smallest leaf, based on algorithm
        Board* leaf = this->frontier.top();

        this->frontier.pop();
        this->frontier_set.erase(leaf->getMat());

        // If leaf is the goal, return it
        if ((*(this->goal) == *leaf)) { 
            return leaf;
        } // Overloaded==

        // Add to explored set if not
        this->explored.insert(leaf->getMat());

        // If not in explored, expand
        std::cout << "==============================================================\nCurrent expanding node with g(n) = "
                  << leaf->getCost() << ", h(n) = " << problem->heuristicOf(leaf) << ", and f(n) = " << leaf->f_valueFrom() << "\n";
        leaf->draw(std::cout);
        problem->expand(leaf);
        this->count++;
        std::cout << "Expanding node " << this->count << "...\n";
        std::cout << "Size: " << this->frontier_set.size() << "\n\n";

        // Add the children to the frontier if not there or in explored
        for (int i = 0; i < 4; i++) {

            // Child is not in frontier
            bool in_frontier = ( this->frontier_set.find(leaf->getChild(i)->getMat()) != this->frontier_set.end() );

            // Child is not in explored
            bool in_explored = ( this->explored.find(leaf->getChild(i)->getMat()) != this->explored.end() );

            // If both conditions are met, push into frontier
            if ( !in_frontier && !in_explored ) {
                this->frontier.push( leaf->getChild(i) );
                this->frontier_set.insert( leaf->getChild(i)->getMat() );

                // Tracking maximum frontier length
                if (this->frontier.size() > this->maxFrontierLength) {
                    this->maxFrontierLength = this->frontier.size();
                }
            }

        }
    } 
}

// Control
void GameDriver::beginGame() {

    int pChoice;
    int aChoice;

    std::cout << "Welcome to 862228249 8 puzzle solver.\n";
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
    std::cin >> pChoice;
    std::cout << "\n";

    int rows = 3;
    int cols = 3;

    std::vector<std::vector<int>> mat(rows);

    if (pChoice == 2) {
        std::cout << "Enter your puzzle, use a zero to represent the blank\n";

        // Iterate through the rows
        for (int r = 0; r < rows; r++) {

            std::cout << "Enter row " << r + 1 << ", use space or tabs between numbers: ";

            mat.at(r) = std::vector<int>(cols); // make a row

            // Collect integer items
            for (int i = 0; i < cols; i++) {
                std::cin >> mat.at(r).at(i);
            }

        }
    }
    else if (pChoice == 1) {

        this->defaultTest();
        return;
    }
    else {
        std::cout << "invalid." << std::endl;
        return;
    }

    int heur;

    std::cout << "\nEnter your choice of algorithm\n"
              << "1. Uniform Cost Search\n"
              << "2. A* with the Misplaced Tile heuristic\n"
              << "3. A* with the Eucledian Distance heuristic\n";
    
    std::cin >> heur;
    std::cout << "\n" << std::endl;

    // Set the goal vector
    std::vector<std::vector<int>> goalVector(rows);

    // Iterate through the rows
    int cnt = 1;
    for (int r = 0; r < rows; r++) {
        goalVector.at(r) = std::vector<int>(cols); // make a row

        for (int i = 0; i < cols; i++) { // enter items
            goalVector.at(r).at(i) = cnt++;
        }
    }
    cnt = 0;
    goalVector.at(rows-1).at(cols-1) = cnt++; // set empty tile

    // Set the goal state
    this->goal = new Board(goalVector);

    // Root Board, start state
    Board* root = new Board(mat);

    // Problem that we pass onto the graph search
    Problem* myProblem = new Problem(root);

    root->setContext(myProblem);

    std::cout << "Setting heuristic to: " << heur << std::endl;
    // Set the heuristic
    myProblem->setHeuristic(heur);

    // Graph search algorithm
    Board* solution = this->graphSearch(myProblem);
    if (solution != nullptr) {
        std::cout << "Goal!!!" << std::endl;
        solution->draw(std::cout);
        std::cout << "\n"
                  << "To solve this problem the search algorithm expanded a total of " << this->count << " nodes.\n"
                  << "The maximum number of nodes in the queue at any one time: " << this->maxFrontierLength << "\n"
                  << "The depth of the goal node was: " << solution->getDepth() << std::endl;

        std::cout << "\n";
        this->printPath(std::cout, solution, solution->getDepth());
    }
    else {
        std::cout << "Failure!!!\n\n"
                  << "No answer was found. :(" << std::endl;
        std::cout << "The maximum queue size was: " << this->maxFrontierLength << std::endl; 
    }

}

void GameDriver::printPath(std::ostream& out, Board* leaf, int i) {

    if (leaf == nullptr) {
        return;
    }

    printPath(out, leaf->getParent(), i - 1);
    out << i << ")\n";
    leaf->draw(std::cout);
}

void GameDriver::defaultTest() {

    int heur;

    std::cout << "\nEnter your choice of algorithm\n"
              << "1. Uniform Cost Search\n"
              << "2. A* with the Misplaced Tile heuristic\n"
              << "3. A* with the Eucledian Distance heuristic\n";
    
    std::cin >> heur;
    std::cout << "\n" << std::endl;

    std::vector<std::vector<int>> goalVector(3);

    // Iterate through the rows
    int cnt = 1;
    for (int r = 0; r < 3; r++) {
        goalVector.at(r) = std::vector<int>(3); // make a row

        for (int i = 0; i < 3; i++) { // enter items
            goalVector.at(r).at(i) = cnt++;
        }
    }
    cnt = 0;
    goalVector.at(3-1).at(3-1) = cnt++; // set empty tile

    // Set the goal state
    this->goal = new Board(goalVector);

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 0, 5}, {7, 8, 6}};
    Board* board = new Board(mat);
    Problem* problem = new Problem(board);

    std::cout << "Setting heuristic to " << heur << ".\n";
    problem->setHeuristic(heur);
    board->setContext(problem);

    // Graph search algorithm
    Board* solution = this->graphSearch(problem);
    if (solution != nullptr) {
        std::cout << "Goal!!!" << std::endl;
        solution->draw(std::cout);
        std::cout << "\n"
                  << "To solve this problem the search algorithm expanded a total of " << this->count << " nodes.\n"
                  << "The maximum number of nodes in the queue at any one time: " << this->maxFrontierLength << "\n"
                  << "The depth of the goal node was: " << solution->getDepth() << std::endl;

        std::cout << "\n";
        this->printPath(std::cout, solution, solution->getDepth());
    }
    else {
        std::cout << "Failure!!!\n\n"
                  << "No answer was found. :(" << std::endl;
    }

}