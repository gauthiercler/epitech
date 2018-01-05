#ifndef GOMOKU_MOVEGENERATOR_HPP
#define GOMOKU_MOVEGENERATOR_HPP

#include <vector>
#include <string>
#include "Move.hpp"

namespace Gomoku {

    class Board;

    class MoveGenerator {

    private:

        const Board &board;

        bool            hasNeighbor(unsigned char **boardTable, unsigned char boardSize, unsigned char x, unsigned char y) const;

    public:

        explicit MoveGenerator(const Board &board) : board(board) {};
        ~MoveGenerator() = default;


        std::vector<MoveData>   generateMoveList() const;
        void    applyLateMoveReduction(std::vector<MoveData> &moveList) const;

    };

}


#endif //GOMOKU_MOVEGENERATOR_HPP
