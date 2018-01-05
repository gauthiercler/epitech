#include <iostream>
#include "src/Engine.hpp"
#include "src/Constants.hpp"

int main() {

/*    Gomoku::Board board;

    board.generate(20);

	board.makeMove(6, 7, Gomoku::Player::AI);
	board.makeMove(6, 8, Gomoku::Player::AI);
	board.makeMove(5, 9, Gomoku::Player::AI);
	board.makeMove(4, 9, Gomoku::Player::AI);
    board.dump();
    Gomoku::Move move = Gomoku::Utils::Move::getMove(5, 9);
    std::cout << "Score move : " << board.getEvaluator().evaluateMove(move, Gomoku::Player::AI) << std::endl;
    std::cout << "Board score : " << board.getEvaluator().evaluateBoard(static_cast<int>(Gomoku::ScoreFactor::AI)) << std::endl;
    return 0; */
  Gomoku::Engine engine;

  try {
    engine.run();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}