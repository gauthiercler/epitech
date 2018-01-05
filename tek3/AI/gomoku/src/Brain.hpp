#ifndef GOMOKU_BRAIN_HPP
#define GOMOKU_BRAIN_HPP

#include <atomic>
#include "Board.hpp"
#include "Move.hpp"

namespace Gomoku {

  enum class ScoreFactor : int {
        AI = 1,
        ENEMY = -1
    };

    class Brain {

    private:

        Board       &board;

    public:

	  	static std::atomic<bool> running;

        explicit Brain(Board &board) : board(board) {};
        ~Brain() = default;

        Move    	getOpeningMove();
        Move    	searchBestMove();
        Move		rootNegaMax(unsigned int maxDepth);
        int     	negaMax(unsigned int maxDepth, int alpha, int beta, int scoreFactor, MoveData &moveData);
    };
}



#endif //GOMOKU_BRAIN_HPP
