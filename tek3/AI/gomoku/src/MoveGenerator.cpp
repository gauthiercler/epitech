#include <iostream>
#include    "MoveGenerator.hpp"
#include    "Constants.hpp"
#include    "Board.hpp"

std::vector<Gomoku::MoveData> Gomoku::MoveGenerator::generateMoveList() const {
    const unsigned char     boardSize = this->board.getSize();
    unsigned char           **boardTable = this->board.getBoard();
    std::vector<MoveData>       moveList;

    moveList.reserve(Constants::MOVE_LIST_MAX_SIZE);
    for (unsigned char y = 0; y < boardSize; ++y) {
        for (unsigned char x = 0; x < boardSize; ++x) {
            if (boardTable[y][x] == Constants::EMPTY_SQUARE && this->hasNeighbor(boardTable, boardSize, x, y)) {
                MoveData move{Utils::Move::getMove(x, y), 0, false};
                moveList.emplace_back(move);
            }
        }
    }
    return moveList;
}


bool Gomoku::MoveGenerator::hasNeighbor(unsigned char **boardTable, const unsigned char boardSize, unsigned char x, unsigned char y) const {
	char    lowerXBound = x - static_cast<char>(Constants::NEIGHBOR_DISTANCE);
	char    lowerYBound = y - static_cast<char>(Constants::NEIGHBOR_DISTANCE);
	char    upperXBound = x + static_cast<char>(Constants::NEIGHBOR_DISTANCE);
	char    upperYBound = y + static_cast<char>(Constants::NEIGHBOR_DISTANCE);

	if (lowerXBound < 0) { lowerXBound = 0; }
	if (lowerYBound < 0) { lowerYBound = 0; }
	if (upperXBound >= boardSize) { upperXBound = boardSize - static_cast<unsigned char>(1); }
	if (upperYBound >= boardSize) { upperYBound = boardSize - static_cast<unsigned char>(1); }

	for (char i = lowerYBound ; i <= upperYBound ; ++i) {
		for (char j = lowerXBound ; j <= upperXBound ; ++j) {
			if (boardTable[i][j] != Constants::EMPTY_SQUARE) {
				return true;
			}
		}
	}
	return false;
}

void Gomoku::MoveGenerator::applyLateMoveReduction(std::vector<Gomoku::MoveData> &moveList) const {
    moveList.resize((moveList.size() < Constants::LATE_MOVE_REDUCTOR) ? moveList.size() : Constants::LATE_MOVE_REDUCTOR);
}
