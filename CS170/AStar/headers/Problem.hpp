#ifndef __PROBLEM_HPP__
#define __PROBLEM_HPP__

#include "Board.hpp"

class Problem {

    private:
        Board* root;
        int _height;
        int _size;
        int _heuristic; 

    public:
        // Constructors
        Problem();
        Problem(Board*);

        // Accessors
        int height()  const { return this->_height; }
        int size() const { return this->_size; }
        
        int depthOf(Board*) const;
        int heightOf(Board*) const;
        int heuristicOf(Board*) const;
        int getHeuristicChoice() const { return this->_heuristic; }
        int f_valueOf(Board*) const;

        Board* getRoot() const { return this->root; }

        // Modifiers
        void expand(Board*);
        void setHeuristic(int heuristic) { this->_heuristic = heuristic; }
};

#endif