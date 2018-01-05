#include    <algorithm>
#include    <iostream>
#include 	<future>
#include    "Brain.hpp"

std::atomic<bool> Gomoku::Brain::running;

Gomoku::Move Gomoku::Brain::getOpeningMove() {
    return Utils::Move::getMove(static_cast<unsigned char>(this->board.getSize() / 2),
                                static_cast<unsigned char>(this->board.getSize() / 2));
}

Gomoku::Move Gomoku::Brain::searchBestMove() {

	Gomoku::Brain::running = true;

	std::future<Move> future = std::async(std::launch::async, [this]() {
	  Move best = 0;
	  for (unsigned int index = 2; Gomoku::Brain::running && index < 20; ++index) {
		  auto ret = this->rootNegaMax(index);
		  if (Gomoku::Brain::running)
			  best = ret;
	  }
	  return best;
	});

	future.wait_for(std::chrono::seconds((this->board.getNbMovesPlayed() < 2) ? 3 : 4));
	Gomoku::Brain::running = false;
	return future.get();
}

Gomoku::Move Gomoku::Brain::rootNegaMax(unsigned int maxDepth) {
    bool                        set;
    int                         score;
    std::pair<MoveData, int>    bestMove;
    std::vector<MoveData>       moveList = this->board.getMoveGenerator().generateMoveList();

	std::cout << "DEBUG " << "depth:" << maxDepth << std::endl;
	std::flush(std::cout);
	if (!Gomoku::Brain::running)
		return 0;

    set = false;
    this->board.getEvaluator().evaluateMoveList(moveList, Player::AI);
    this->board.getEvaluator().sortMoveList(moveList);
    this->board.getMoveGenerator().applyLateMoveReduction(moveList);
    for (auto &&move: moveList) {
		if (!Gomoku::Brain::running)
			break;
        this->board.makeMove(move.position, Player::AI);
        score = this->negaMax(maxDepth - 1, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), static_cast<int>(ScoreFactor::ENEMY), move);
        if (!set || score > bestMove.second) {
            set = true;
            bestMove.first = move;
            bestMove.second = score;
        }
        this->board.unmakeMove(move.position);
    }
    return bestMove.first.position;
}

int Gomoku::Brain::negaMax(unsigned int maxDepth, int alpha, int beta, int scoreFactor, MoveData &moveData) {
	if (!Gomoku::Brain::running)
		return 0;

    if (moveData.isTerminal) {
        return Constants::TERMINAL_MOVE_SCORE * (scoreFactor * -1);
    }
    if (maxDepth == 0 || moveData.isTerminal) {
        return this->board.getEvaluator().evaluateBoard(scoreFactor);
    }

    int                     negaMaxValue;
    Player                  player = (scoreFactor == static_cast<int>(ScoreFactor::AI) ? Player::AI : Player::Enemy);
    int                     score = std::numeric_limits<int>::min();
    std::vector<MoveData>   moveList = this->board.getMoveGenerator().generateMoveList();

    this->board.getEvaluator().evaluateMoveList(moveList, player);
    this->board.getEvaluator().sortMoveList(moveList);
    this->board.getMoveGenerator().applyLateMoveReduction(moveList);
    for (auto &&move : moveList) {
		if (!Gomoku::Brain::running)
			break;
        this->board.makeMove(move.position, player);
        negaMaxValue = -this->negaMax(maxDepth - 1, -beta, -alpha, -scoreFactor, move);
        score = (std::max)(score, negaMaxValue);
        alpha = (std::max)(alpha, negaMaxValue);
        this->board.unmakeMove(move.position);
        if (alpha >= beta) { break; }
    }
    return score;
}

