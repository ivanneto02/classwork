#include "../headers/Board.hpp"
#include "../headers/HeuristicStrategy.hpp"
#include "../headers/Problem.hpp"

// Constructors
Board::Board() {
    this->width = 3;
    this->length = 3;
    this->area = this->width * this->length;
    
    this->matrix = std::vector<std::vector<int>>(this->length);

    this->curr_cost = 0;

    // Initialize every item to 0.
    // For every row
    for (int r = 0; r < this->length; r++) {
        this->matrix.at(r) = std::vector<int>(this->width);
        // For every item in each row...
        for (int i = 0; i < this->width; i++) {
            this->matrix.at(r).at(i) = 0;
        }
    }
}

Board::Board(int w, int l) {
    this->width = w;
    this->length = l;
    this->area = this->width * this->length;
    
    this->matrix = std::vector<std::vector<int>>(this->length);

    this->curr_cost = 0;

    // Initialize every item to 0.
    // For every row
    for (int r = 0; r < this->length; r++) {
        this->matrix.at(r) = std::vector<int>(this->width);
        // For every item in each row...
        for (int i = 0; i < this->width; i++) {
            this->matrix.at(r).at(i) = 0;
        }
    }
}

Board::Board(std::vector<std::vector<int>> mat) {

    this->width = mat.at(0).size();
    this->length = mat.size();
    this->area = this->width * this->length;
    
    this->matrix = std::vector<std::vector<int>>(this->length);

    this->curr_cost = 0;

    // Initialize every item to item value.
    // For every row
    for (int r = 0; r < this->length; r++) {
        this->matrix.at(r) = std::vector<int>(this->width);
        // For every item in each row...
        for (int i = 0; i < this->width; i++) {
            this->matrix.at(r).at(i) = mat.at(r).at(i);
        }
    }
}
// Endof constructors

/*
This function assigns the matrix that A* needs to search through a "game" stage.
*/
void Board::setStage(const std::vector<std::vector<int>> mat) {

    // Clear previous matrix
    this->matrix.clear();

    // Set matrix
    this->matrix = std::vector<std::vector<int>>(mat.size());

    // Set new board parameters
    this->width = mat.at(0).size();
    this->length = mat.size();
    this->area = this->width * this->length;

    // Initialize every item to item value.
    // For every row
    for (int r = 0; r < mat.size(); r++) {
        this->matrix.at(r) = std::vector<int>(this->width);
        // For every item in each row...
        for (int i = 0; i < mat.at(0).size(); i++) {
            this->matrix.at(r).at(i) = mat.at(r).at(i);
        }
    }
}

// Clears the board in Board object
void Board::clear() {
    // For every row
    for (int r = 0; r < this->matrix.size(); r++) {
        // For every item in each row...
        for (int i = 0; i < this->matrix.at(r).size(); i++) {

            this->matrix.at(r).at(i) = 0;
        }
    }
}

// Draws the board to out ostream
void Board::draw(std::ostream& out) {
    for (int i = 0; i < this->width; i++) { out << "-" << " "; }
    out << "\n";

    // For every row...
    for (int r = 0; r < this->matrix.size(); r++) {

        // For every item in row
        for (int i = 0; i < this->matrix.at(r).size(); i++) {
            out << matrix.at(r).at(i) << " ";
        }
        out << "\n";
    }

    for (int i = 0; i < this->width; i++) { out << "-" << " "; }
    out << "\n";
}

/*
This function is Board-specific, and it expands a Board node given a board of
arbitrary, unique positive integers, with a zero denoting the "empty" spot.

Assumptions for this function:
    - Single empty spot in entire board
    - Unique positive integers
    - Square n x n board, not n x m (rectangular)
*/
void Board::expand() {

    // Locate 0
    int row = 0;
    int col = 0;
    for (int r = 0; r < matrix.size(); r++) { // rows
        for (int i = 0; i < matrix.at(0).size(); i++) { // items in rows
            if (matrix.at(r).at(i) == 0) {
                row = r;
                col = i;
                break;
            }
        }
    } // finished locating 0

    // move left, add Board
    this->children.push_back( this->move_left(row, col) );

    // move right, add Board
    this->children.push_back( this->move_right(row, col) );

    // move up, add Board
    this->children.push_back( this->move_up(row, col) );

    // move down, add Board
    this->children.push_back( this->move_down(row, col) );
}

Board* Board::move_left(int r, int c) const {

    // Make a tmp vector
    std::vector<std::vector<int>> tmp = this->matrix;

    if (c == 0) {
        // circle-shift vector to the left
        int left = tmp.at(r).at(0);
        for (int i = 0; i < tmp.at(0).size() - 1; i++) {
            tmp.at(r).at(i) = tmp.at(r).at(i+1);
        }
        tmp.at(r).at(tmp.at(r).size() - 1) = 0;
    }
    else {
        int tmp_val = tmp.at(r).at(c-1);
        tmp.at(r).at(c-1) = 0;
        tmp.at(r).at(c) = tmp_val;
    }

    // Make and return child based on tmp vector
    Board* child = new Board(tmp);
    return child;
}

Board* Board::move_right(int r, int c) const {

    // Make a tmp vector
    std::vector<std::vector<int>> tmp = this->matrix;

    // circle-shift vector to the right
    if (c == tmp.at(0).size() - 1) {
        int right = tmp.at(r).at(tmp.at(r).size() - 1);
        for (int i = tmp.at(r).size() - 1; i > 0; i--) {
            tmp.at(r).at(i) = tmp.at(r).at(i-1);
        }
        tmp.at(r).at(0) = right;
    }
    else {
        int tmp_val = tmp.at(r).at(c+1);
        tmp.at(r).at(c+1) = 0;
        tmp.at(r).at(c) = tmp_val;
    }

    // Make and return child based on tmp vector
    Board* child = new Board(tmp);
    return child;
}

Board* Board::move_up(int r, int c) const {

    // Make a tmp vector
    std::vector<std::vector<int>> tmp = this->matrix;

    if (r == 0) {
        // circle-shift vector up
        int up = tmp.at(0).at(c);
        for (int i = 0; i < tmp.size() - 1; i++) {
            tmp.at(i).at(c) = tmp.at(i+1).at(c);
        }
        tmp.at(tmp.size() - 1).at(c) = up;
    }
    else {
        int tmp_val = tmp.at(r-1).at(c);
        tmp.at(r-1).at(c) = 0;
        tmp.at(r).at(c) = tmp_val;
    }

    // Make and return child based on tmp vector
    Board* child = new Board(tmp);
    return child;
}

Board* Board::move_down(int r, int c) const {

    // Make a tmp vector
    std::vector<std::vector<int>> tmp = this->matrix;

    if (r == tmp.size() - 1) {
        // circle-shift vector down
        int down = tmp.at(tmp.size() - 1).at(c);
        for (int i = tmp.size() - 1; i > 0; i--) {
            tmp.at(i).at(c) = tmp.at(i-1).at(c);
        }
        tmp.at(0).at(c) = down;    
    }
    else {
        int tmp_val = tmp.at(r+1).at(c);
        tmp.at(r+1).at(c) = 0;
        tmp.at(r).at(c) = tmp_val;
    }

    // Make and return child based on tmp vector
    Board* child = new Board(tmp);
    return child;
}

Board* Board::getChild(int i) const {
    return this->children.at(i);
};

// Overloading == operator for the GameDrive driver
bool operator==(Board& lhs, Board& rhs) {

    std::vector<std::vector<int>> lhs_mat = lhs.getMat();
    std::vector<std::vector<int>> rhs_mat = rhs.getMat();

    for (int r = 0; r < lhs_mat.size(); r++) { // For every row in mat
        for (int i = 0; i < lhs_mat.at(0).size(); i++) { // For every item in row
            if ( lhs_mat.at(r).at(i) != rhs_mat.at(r).at(i) ) {
                return false;
            }
        }
    }

    return true;
}

int Board::heuristic(Heuristic* ctx) const {

    return ctx->heuristic(this);
}

int Board::f_valueFrom() const {
    Heuristic* strat;
    // std::cout << "calculating f value..." << std::endl;

    if (this->ctx->getHeuristicChoice() == 1) {
        // std::cout << "uniform..." << std::endl;
        strat = new UniformCostHeuristic();
    }
    else if (this->ctx->getHeuristicChoice() == 2) {
        // std::cout << "misplaced..." << std::endl;
        strat = new MisplacedTileHeuristic();
    }
    else if (this->ctx->getHeuristicChoice() == 3) {
        // std::cout << "euclidean..." << std::endl;
        strat = new EuclideanHeuristic();
    }
    else {
        // std::cout << "uniform2..." << std::endl;
        strat = new UniformCostHeuristic();
    }
    // std::cout << "end of calculation..." << std::endl;

    return this->getCost() + this->heuristic(strat);
}

void Board::setContext(Problem* ctx) {
    this->ctx = ctx;
}