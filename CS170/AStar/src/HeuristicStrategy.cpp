#include "../headers/HeuristicStrategy.hpp"
#include "../headers/Board.hpp"
#include <math.h>

Heuristic::Heuristic() {}

MisplacedTileHeuristic::MisplacedTileHeuristic() : Heuristic() {}
int MisplacedTileHeuristic::heuristic(const Board* board) const {
    int cnt = 0;
    for (int r = 0; r < board->getMat().size(); r++) {
        for (int i = 0; i < board->getMat().at(0).size(); i++) {
            if (i+1 != board->getMat().at(r).at(i)) { cnt++; }
        }
    }
    return cnt;
}

EuclideanHeuristic::EuclideanHeuristic() : Heuristic() {}
int EuclideanHeuristic::heuristic(const Board* board) const {
    int cnt = 0;

    int c_x = 0;
    int c_y = 0;
    int m_x = 0;
    int m_y = 0;

    int d_x = 0;
    int d_y = 0;

    std::vector<std::vector<int>> mat = board->getMat();

    for (int r = 0; r < mat.size(); r++) {
        for (int i = 0; i < mat.at(0).size(); i++) {
            
            if (mat.at(r).at(i) == 0) {
                continue;
            }

            c_x = i;
            c_y = r;

            m_x = ((int)mat.at(r).at(i) - 1) % ((int)mat.at(r).size());
            m_y = ((int)mat.at(r).at(i) - 1) / ((int)mat.at(r).size());

            d_x = c_x > m_x ? (int)c_x - (int)m_x : (int)m_x - (int)c_x;
            d_y = c_y > m_y ? (int)c_y - (int)m_y : (int)m_y - (int)c_y;

            // Add it to the count
            cnt += (d_x + d_y);
        }
    }

    return cnt;
}

UniformCostHeuristic::UniformCostHeuristic() : Heuristic() {}
int UniformCostHeuristic::heuristic(const Board* board) const {
    return 0;
}