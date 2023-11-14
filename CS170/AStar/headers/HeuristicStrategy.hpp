#ifndef __HEURISTIC_STRATEGY_HPP__
#define __HEURISTIC_STRATEGY_HPP__

#include <cmath>

class Board;

class Heuristic {

    public:
        Heuristic();
        virtual int heuristic(const Board*) const = 0;
};

class MisplacedTileHeuristic : public Heuristic {

    public:
        MisplacedTileHeuristic();
        virtual int heuristic(const Board*) const override;
};

class EuclideanHeuristic : public Heuristic {

    public:
        EuclideanHeuristic();
        virtual int heuristic(const Board*) const override;
};

class UniformCostHeuristic : public Heuristic {

    public:
        UniformCostHeuristic();
        virtual int heuristic(const Board*) const override;
};

#endif