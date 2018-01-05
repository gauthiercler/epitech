#ifndef GOMOKU_BOARD_HPP
#define GOMOKU_BOARD_HPP

#include <vector>
#include "Move.hpp"
#include "MoveGenerator.hpp"
#include "BoardEvaluator.hpp"

namespace Gomoku {

    class Board {

    private:

        MoveGenerator   moveGenerator;
        BoardEvaluator  boardEvaluator;

        unsigned char   size = 0;
        unsigned char   **board = nullptr;
        bool            empty = true;

        void allocate(unsigned char size);
        void clean();

    public:

        Board() : moveGenerator(*this), boardEvaluator(*this) {};
        ~Board() = default;

	  	int getNbMovesPlayed();
        void setSize(const unsigned char &size);
        const unsigned char &getSize() const;
        bool    isEmpty();
        unsigned char **getBoard() const;
        void generate(unsigned char size);
        void dump() const;
        void makeMove(unsigned char x, unsigned char y, Player player);
        void makeMove(Move move, Player player);
        void unmakeMove(unsigned char x, unsigned char y);
        void unmakeMove(Move move);

	  	bool isGenerated() const;

        const MoveGenerator     &getMoveGenerator();
        BoardEvaluator          &getEvaluator();
    };
}

#endif //GOMOKU_BOARD_HPP
