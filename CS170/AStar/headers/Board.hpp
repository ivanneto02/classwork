#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>
#include <vector>
#include <ostream>

class Heuristic;
class Problem;

class Board {

    /* This class acts as a "node" class */
    private:
        // Variables
        int width;
        int length;
        int area;
        std::vector<std::vector<int>> matrix;

        // For AStar
        int curr_cost;
        int depth;

        // Keep track of parent node
        Board* parent;
        Problem* ctx;

        // Children nodes
        std::vector<Board*> children;

    public:
        // Constructors
        Board();
        Board(int, int);
        Board(std::vector<std::vector<int>>);

        // Common functions
        int getArea() const { return this->area; }
        int getWidth() const { return this->width; }
        int getLength() const { return this->length; }
        int getDepth() const { return this->depth; }
        int getCost() const { return this->curr_cost; }
        std::vector<std::vector<int>> getMat() const { return this->matrix; }
        Board* getChild(int) const;
        int heuristic(Heuristic*) const;
        Board* getParent() const { return this->parent; }

        // Functionality
        void setStage(const std::vector<std::vector<int>>);
        void clear();
        void draw(std::ostream&);
        void setParent(Board* parent) { this->parent = parent; }
        void setDepth(int dep) { this->depth = dep; }
        void setCost(int cost) { this->curr_cost = cost; }
        void setContext(Problem*);
        void expand();
        
        // Overloading == operator for the GameDrive driver
        friend bool operator==(Board& lhs, Board& rhs);

        // To move the board
        Board* move_left(int, int) const;
        Board* move_right(int, int) const;
        Board* move_up(int, int) const;
        Board* move_down(int, int) const;

        int f_valueFrom() const;
};

#endif