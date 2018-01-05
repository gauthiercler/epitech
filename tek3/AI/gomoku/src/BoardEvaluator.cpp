#include <iostream>
#include <algorithm>
#include "BoardEvaluator.hpp"
#include "Board.hpp"
#include "Constants.hpp"
#include "Brain.hpp"

Gomoku::BoardEvaluator::BoardEvaluator(Gomoku::Board &board) : board(board) {

    this->simplePatterns = {
            {1, "XXXXX", Constants::TERMINAL_MOVE_SCORE, false, false, {}},
            {2, "-XXXX-", 25000, false, true, {}},
            {3, "XXXX-", 9959, true, false, {2}},
            {4, "XXX-X", 9944, true, false, {}},
            {5, "-XXX--", 1014, true, true, {}},
            {6, "-XX-X-", 959, true, false, {}},
            {7, "XXX--", 944, true, false, {5}},
            {8, "-XX---", 52, true, true, {}},
            {9, "--X-X-", 44, true, false, {}},
            {10, "--XX--", 38, false, false, {}},
            {11, "X-X--", 30, true, false, {}},
            {12, "XX---", 20, true, false, {8}},
            {13, "X---X", 10, false, false, {}}
    };

    for (auto &&pattern : this->simplePatterns) {
        if (pattern.hasSubPatterns) {
            this->patternOccurrences.insert({pattern.id, {}});
        }
    }

    this->compositePatterns = {
            {this->getPattern("XXX--"), this->getPattern("-XXX--"), {1, 2}, 9953},
            {this->getPattern("-XXX--"), this->getPattern("-XXX--"), {3, 3}, 9947},
            {this->getPattern("XXX--"), this->getPattern("XX---"), {0, 1}, 9944},
            {this->getPattern("-XX-X-"), this->getPattern("XXXX-"), {4, 3}, 9942},
            {this->getPattern("-XXX--"), this->getPattern("XXX--"), {1, 2}, 9942},
            {this->getPattern("-XXX--"), this->getPattern("--X-X-"), {1, 2}, 9938},
            {this->getPattern("-XX---"), this->getPattern("XX---"), {1, 0}, 957},
            {this->getPattern("--X-X-"), this->getPattern("-XX---"), {4, 1}, 953},
            {this->getPattern("-XX---"), this->getPattern("XXX--"), {2, 1}, 952},
            {this->getPattern("--XX--"), this->getPattern("XX---"), {2, 0}, 951},
            {this->getPattern("--XX--"), this->getPattern("XX---"), {3, 0}, 950},
            {this->getPattern("-XX---"), this->getPattern("-XX---"), {3, 3}, 947},
            {this->getPattern("XX---"), this->getPattern("XX---"), {0, 1}, 944},
            {this->getPattern("--X-X-"), this->getPattern("X---X"), {4, 0}, 942},
            {this->getPattern("--X-X-"), this->getPattern("-XXX--"), {2, 3}, 942},
            {this->getPattern("-XX---"), this->getPattern("XXX--"), {4, 3}, 942},
            {this->getPattern("-XX---"), this->getPattern("X-X--"), {4, 3}, 942},
            {this->getPattern("--XX--"), this->getPattern("XX---"), {4, 2}, 942},
            {this->getPattern("--XX--"), this->getPattern("XXXX-"), {3, 2}, 938},
            {this->getPattern("--XX--"), this->getPattern("XXX--"), {3, 2}, 938}
    };

}

void Gomoku::BoardEvaluator::updatePatterns(std::string &ownPattern, std::string &enemyPattern, unsigned char ownStone,
                                            unsigned char boardStone) const {
    if (boardStone == Constants::EMPTY_SQUARE) {
        ownPattern += '-';
        enemyPattern += '-';
    } else if (boardStone == ownStone) {
        ownPattern += 'X';
        enemyPattern += 'O';
    } else {
        ownPattern += 'O';
        enemyPattern += 'X';
    }
}

std::pair<std::string, std::string>
Gomoku::BoardEvaluator::generatePattern(Gomoku::Move move, unsigned char ownStone,
                                        char hIncrement, char vIncrement,
                                        char hDelta, char vDelta) const {
    const unsigned char boardSize = this->board.getSize();
    unsigned char **boardTable = this->board.getBoard();
    unsigned char hMovePosition = Utils::Move::getPosX(move);
    unsigned char vMovePosition = Utils::Move::getPosY(move);
    char hPosition = hMovePosition - hDelta;
    char vPosition = vMovePosition - vDelta;
    std::string ownPattern;
    std::string enemyPattern;
    unsigned char boardStone;

    ownPattern.reserve(Constants::Patterns::PATTERN_LENGTH + static_cast<unsigned char>(1));
    enemyPattern.reserve(Constants::Patterns::PATTERN_LENGTH + static_cast<unsigned char>(1));

    for (unsigned char step = 0; step <= Constants::Patterns::PATTERN_LENGTH; ++step) {
        if (hPosition >= 0 && hPosition < boardSize && vPosition >= 0 && vPosition < boardSize) {
            if (hPosition == hMovePosition && vPosition == vMovePosition) {
                ownPattern += Constants::MOVE_SYMBOL;
                enemyPattern += Constants::MOVE_SYMBOL;
            } else {
                boardStone = boardTable[vPosition][hPosition];
                this->updatePatterns(ownPattern, enemyPattern, ownStone, boardStone);
            }
        }
        hPosition += hIncrement;
        vPosition += vIncrement;
    }
    return {ownPattern, enemyPattern};
}

Gomoku::BoardEvaluator::MovePatterns
Gomoku::BoardEvaluator::generateMovePatterns(Gomoku::Move move, unsigned char stone) const {

    auto h = this->generatePattern(move, stone, Constants::Patterns::HORIZONTAL_H_INCREMENT,
                                   Constants::Patterns::HORIZONTAL_V_INCREMENT, Constants::Patterns::HORIZONTAL_H_DELTA,
                                   Constants::Patterns::HORIZONTAL_V_DELTA);

    auto v = this->generatePattern(move, stone, Constants::Patterns::VERTICAL_H_INCREMENT,
                                   Constants::Patterns::VERTICAL_V_INCREMENT, Constants::Patterns::VERTICAL_H_DELTA,
                                   Constants::Patterns::VERTICAL_V_DELTA);

    auto ld = this->generatePattern(move, stone, Constants::Patterns::LEFT_DIAGONAL_H_INCREMENT,
                                    Constants::Patterns::LEFT_DIAGONAL_V_INCREMENT,
                                    Constants::Patterns::LEFT_DIAGONAL_H_DELTA,
                                    Constants::Patterns::LEFT_DIAGONAL_V_DELTA);

    auto rd = this->generatePattern(move, stone, Constants::Patterns::RIGHT_DIAGONAL_H_INCREMENT,
                                    Constants::Patterns::RIGHT_DIAGONAL_V_INCREMENT,
                                    Constants::Patterns::RIGHT_DIAGONAL_H_DELTA,
                                    Constants::Patterns::RIGHT_DIAGONAL_V_DELTA);

    return {
            h, v, ld, rd
    };
}


int Gomoku::BoardEvaluator::getSimplePatternScore(std::string &movePattern) {

	auto match_iterator = std::find_if(this->simplePatterns.begin(),
                                       this->simplePatterns.end(),
                                       [&movePattern](const Pattern &pattern) {
                                           size_t straightIndex = movePattern.find(pattern.representation);
                                           if (straightIndex != std::string::npos) { return true; }
                                           std::string reversedMovePattern(movePattern.rbegin(), movePattern.rend());
                                           return reversedMovePattern.find(pattern.representation) != std::string::npos;
                                       });
    if (match_iterator != this->simplePatterns.end()) {
        return match_iterator->score;
    }
    return 0;
}

std::pair<int, int> Gomoku::BoardEvaluator::getSimpleMoveScore(std::pair<std::string, std::string> &move) {
    return {this->getSimplePatternScore(move.first), this->getSimplePatternScore(move.second)};

}


bool Gomoku::BoardEvaluator::hasCompositePattern(
  const std::string &firstPattern,
  const std::string &secondPattern,
  size_t firstPatternPosition,
  size_t secondPatternPosition) {

    for (auto &&pattern : this->compositePatterns) {
        size_t firstPosition = firstPattern.find(pattern.first.representation);
        size_t secondPosition = secondPattern.find(pattern.second.representation);


        if (firstPosition != std::string::npos && secondPosition != std::string::npos) {


            auto firstRelativePosition = static_cast<int>(firstPatternPosition - firstPosition);
            auto secondRelativePosition = static_cast<int>(secondPatternPosition - secondPosition);

            if (firstRelativePosition == pattern.patternIndexes.first
                && secondRelativePosition == pattern.patternIndexes.second) {
				return true;
            }
        }
    }
    return false;
}

bool Gomoku::BoardEvaluator::findCompositePattern(
  const Gomoku::BoardEvaluator::MovePatterns &patterns,
  const Gomoku::BoardEvaluator::MovePositions &positions, Player player) {
    return (player == Player::AI) ?
           (this->hasCompositePattern(patterns.horizontalPatterns.first, patterns.verticalPatterns.first, positions.horizontalPositions.first, positions.verticalPositions.first)
            || this->hasCompositePattern(patterns.horizontalPatterns.first, patterns.leftDiagonalPatterns.first, positions.horizontalPositions.first, positions.leftDiagonalPositions.first)
            || this->hasCompositePattern(patterns.horizontalPatterns.first, patterns.rightDiagonalPatterns.first, positions.horizontalPositions.first, positions.rightDiagonalPositions.first)
            || this->hasCompositePattern(patterns.verticalPatterns.first, patterns.leftDiagonalPatterns.first, positions.verticalPositions.first, positions.leftDiagonalPositions.first)
            || this->hasCompositePattern(patterns.verticalPatterns.first, patterns.rightDiagonalPatterns.first, positions.verticalPositions.first, positions.rightDiagonalPositions.first)
            || this->hasCompositePattern(patterns.leftDiagonalPatterns.first, patterns.rightDiagonalPatterns.first, positions.leftDiagonalPositions.first, positions.rightDiagonalPositions.first))
                                  :
           (this->hasCompositePattern(patterns.horizontalPatterns.second, patterns.verticalPatterns.second, positions.horizontalPositions.second, positions.verticalPositions.second)
            || this->hasCompositePattern(patterns.horizontalPatterns.second, patterns.leftDiagonalPatterns.second, positions.horizontalPositions.second, positions.leftDiagonalPositions.second)
            || this->hasCompositePattern(patterns.horizontalPatterns.second, patterns.rightDiagonalPatterns.second, positions.horizontalPositions.second, positions.rightDiagonalPositions.second)
            || this->hasCompositePattern(patterns.verticalPatterns.second, patterns.leftDiagonalPatterns.second, positions.verticalPositions.second, positions.leftDiagonalPositions.second)
            || this->hasCompositePattern(patterns.verticalPatterns.second, patterns.rightDiagonalPatterns.second, positions.verticalPositions.second, positions.rightDiagonalPositions.second)
            || this->hasCompositePattern(patterns.leftDiagonalPatterns.second, patterns.rightDiagonalPatterns.second, positions.leftDiagonalPositions.second, positions.rightDiagonalPositions.second));
	  ;
}

int Gomoku::BoardEvaluator::getCompositePatternScore(
  const std::string &movePattern,
  size_t movePosition,
  Gomoku::BoardEvaluator::OrientationLine orientation,
  Gomoku::Move &move, Player player) {


	for (auto &&pattern : this->compositePatterns) {
		size_t position = movePattern.find(pattern.first.representation);
		if (position != std::string::npos) {


			auto nbToMove = static_cast<int>(pattern.patternIndexes.first - (movePosition - position));


			unsigned char x = Utils::Move::getPosX(move);
			unsigned char y = Utils::Move::getPosY(move);

			switch (orientation) {
				case OrientationLine::HORIZONTAL:
					x += nbToMove;
					break;
				case OrientationLine::VERTICAL:
					y += nbToMove;
					break;
				case OrientationLine::LEFT_DIAGONAL:
					x += nbToMove;
					y += nbToMove;
					break;
				case OrientationLine::RIGHT_DIAGONAL:
					x -= nbToMove;
					y += nbToMove;
					break;
			}
			Move newMove = Utils::Move::getMove(x, y);

			if (this->board.getBoard()[y][x] != Constants::EMPTY_SQUARE)
				continue;

			MovePatterns newMovePatterns = this->generateMovePatterns(newMove, Constants::AI_STONE);

			MovePositions positions = this->getMovePositions(newMovePatterns);

			this->replaceMoveToken(newMovePatterns, '-');

			if (this->findCompositePattern(newMovePatterns, positions, player)) {
				return pattern.score;
			}
		}
	}
	return 0;
}

int Gomoku::BoardEvaluator::getCompositePatternScores(MovePatterns &movePatterns, Move &move, Player player) {

	MovePositions positions = this->getMovePositions(movePatterns);

	auto horizontal = (player == Player::AI) ? std::ref(movePatterns.horizontalPatterns.first) : std::ref(movePatterns.horizontalPatterns.second);
	auto vertical = (player == Player::AI) ? std::ref(movePatterns.verticalPatterns.first) : std::ref(movePatterns.verticalPatterns.second);
	auto leftDiagonal = (player == Player::AI) ? std::ref(movePatterns.leftDiagonalPatterns.first) : std::ref(movePatterns.leftDiagonalPatterns.second);
	auto rightDiagonal = (player == Player::AI) ? std::ref(movePatterns.rightDiagonalPatterns.first) : std::ref(movePatterns.rightDiagonalPatterns.second);

	auto horizontalPosition = (player == Player::AI) ? positions.horizontalPositions.first : positions.horizontalPositions.second;
	auto verticalPosition = (player == Player::AI) ? positions.verticalPositions.first : positions.verticalPositions.second;
	auto leftDiagonalPosition = (player == Player::AI) ? positions.leftDiagonalPositions.first : positions.leftDiagonalPositions.second;
	auto rightDiagonalPosition = (player == Player::AI) ? positions.rightDiagonalPositions.first : positions.rightDiagonalPositions.second;

	this->replaceMoveToken(movePatterns, 'X');

	auto firstPatternScore = std::max({
										this->getCompositePatternScore(horizontal, horizontalPosition, OrientationLine::HORIZONTAL, move, player),
										this->getCompositePatternScore(vertical, verticalPosition, OrientationLine::VERTICAL, move, player),
										this->getCompositePatternScore(leftDiagonal, leftDiagonalPosition, OrientationLine::LEFT_DIAGONAL, move, player),
										this->getCompositePatternScore(rightDiagonal, rightDiagonalPosition, OrientationLine::RIGHT_DIAGONAL, move, player)
									  });

	this->replaceMoveToken(movePatterns, '-');

	auto secondPatternScore = std::max({
										this->getCompositePatternScore(horizontal, horizontalPosition, OrientationLine::HORIZONTAL, move, player),
										this->getCompositePatternScore(vertical, verticalPosition, OrientationLine::VERTICAL, move, player),
										this->getCompositePatternScore(leftDiagonal, leftDiagonalPosition, OrientationLine::LEFT_DIAGONAL, move, player),
										this->getCompositePatternScore(rightDiagonal, rightDiagonalPosition, OrientationLine::RIGHT_DIAGONAL, move, player)
									  });


    movePatterns.horizontalPatterns.first.at(positions.horizontalPositions.first) = Constants::MOVE_SYMBOL;
    movePatterns.horizontalPatterns.second.at(positions.horizontalPositions.second) = Constants::MOVE_SYMBOL;
    movePatterns.verticalPatterns.first.at(positions.verticalPositions.first) = Constants::MOVE_SYMBOL;
    movePatterns.verticalPatterns.second.at(positions.verticalPositions.second) = Constants::MOVE_SYMBOL;
    movePatterns.leftDiagonalPatterns.first.at(positions.leftDiagonalPositions.first) = Constants::MOVE_SYMBOL;
    movePatterns.leftDiagonalPatterns.second.at(positions.leftDiagonalPositions.second) = Constants::MOVE_SYMBOL;
    movePatterns.rightDiagonalPatterns.first.at(positions.rightDiagonalPositions.first) = Constants::MOVE_SYMBOL;
    movePatterns.rightDiagonalPatterns.second.at(positions.rightDiagonalPositions.second) = Constants::MOVE_SYMBOL;
	return std::max(firstPatternScore, secondPatternScore);
}



std::pair<int, int> Gomoku::BoardEvaluator::getCompositePatternMoveScores(Gomoku::BoardEvaluator::MovePatterns &patterns,
																		  Gomoku::Move &move) {
	return {this->getCompositePatternScores(patterns, move, Player::AI), this->getCompositePatternScores(patterns, move, Player::Enemy)};
}


int Gomoku::BoardEvaluator::scoreMovePatterns(Gomoku::BoardEvaluator::MovePatterns &movePatterns, Move &move) {


//	auto compositeScore = this->getCompositePatternMoveScores(movePatterns, move);

	this->replaceMoveToken(movePatterns, 'X');

    std::pair<int, int> horizontalScore = this->getSimpleMoveScore(movePatterns.horizontalPatterns);
    std::pair<int, int> verticalScore = this->getSimpleMoveScore(movePatterns.verticalPatterns);
    std::pair<int, int> leftDiagonalScore = this->getSimpleMoveScore(movePatterns.leftDiagonalPatterns);
    std::pair<int, int> rightDiagonalScore = this->getSimpleMoveScore(movePatterns.rightDiagonalPatterns);

    return
        horizontalScore.first + horizontalScore.second +
        verticalScore.first + verticalScore.second +
        leftDiagonalScore.first + leftDiagonalScore.second +
        rightDiagonalScore.first + rightDiagonalScore.second;
//		compositeScore.first + compositeScore.second;
}

int Gomoku::BoardEvaluator::evaluateMove(Gomoku::Move &move, Player player) {
    unsigned char stone = (player == Player::AI ? Constants::AI_STONE : Constants::ENEMY_STONE);
    MovePatterns movePatterns = this->generateMovePatterns(move, stone);

    return this->scoreMovePatterns(movePatterns, move);
}

bool
Gomoku::BoardEvaluator::patternIsInvalidChild(Gomoku::BoardEvaluator::Pattern &patternData, size_t found_index) const {
    if (patternData.hasFathers()) {
        for (auto &&fatherId : patternData.fatherPatterns) {
            auto occIt = this->patternOccurrences.find(fatherId);
            if (occIt != this->patternOccurrences.end()) {
                for (auto &&fatherPosition : occIt->second) {
                    if (static_cast<int>(found_index) >= fatherPosition.first && static_cast<int>((found_index + patternData.representation.length() - 1)) <= fatherPosition.second) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int Gomoku::BoardEvaluator::scoreOrientedPattern(Pattern &patternData, const std::string &pattern, bool reverse) {

    size_t  search_position;
    size_t  found_index;
    int     score;

    score = 0;
    search_position = 0;
    found_index = std::string::npos;
    if (reverse) { std::reverse(patternData.representation.begin(), patternData.representation.end()); }
    do {
        found_index = pattern.find(patternData.representation, search_position);
        if (found_index != std::string::npos) {
            if (!this->patternIsInvalidChild(patternData, found_index)) {
                if (patternData.hasSubPatterns) {
                    auto occIt = this->patternOccurrences.find(patternData.id);
                    if (occIt != this->patternOccurrences.end()) {
                        occIt->second.emplace_back(std::make_pair<int, int>(static_cast<int &&>(std::move(found_index)),
                                                                            static_cast<int &&>(found_index + patternData.representation.length() - 1)));
                    }
                }
                score += patternData.score;
            }
            search_position = found_index + patternData.representation.length() - 1;
        }
    } while (found_index != std::string::npos);
    if (reverse) { std::reverse(patternData.representation.begin(), patternData.representation.end()); }
    return score;

}

int Gomoku::BoardEvaluator::scorePattern(const std::string &pattern) {
    int     score;

    score = 0;
    this->clearPatternOccurrence();
    for (auto &&patternData : this->simplePatterns) {

        score += this->scoreOrientedPattern(patternData, pattern, true);
        if (patternData.reversible) {
            score += this->scoreOrientedPattern(patternData, pattern, false);
        }
    }
    return score;

}

int Gomoku::BoardEvaluator::scoreRowPatterns() {
    const unsigned char boardSize = this->board.getSize();
    unsigned char **boardTable = this->board.getBoard();
    unsigned char stone;
    std::string ownPattern;
    std::string enemyPattern;
    int score = 0;

    for (unsigned char row = 0; row < boardSize; ++row) {
        ownPattern.clear();
        enemyPattern.clear();
        for (unsigned char column = 0; column < boardSize; ++column) {
            stone = boardTable[row][column];
            this->updatePatterns(ownPattern, enemyPattern, stone);
        }
        score += this->scorePattern(ownPattern) * static_cast<int>(ScoreFactor::AI);
        score += this->scorePattern(enemyPattern) * static_cast<int>(ScoreFactor::ENEMY);
    }
    return score;
}

int Gomoku::BoardEvaluator::scoreColumnPatterns() {
    const unsigned char boardSize = this->board.getSize();
    unsigned char **boardTable = this->board.getBoard();
    unsigned char stone;
    std::string ownPattern;
    std::string enemyPattern;
    int score = 0;

    for (unsigned char column = 0; column < boardSize; ++column) {
        ownPattern.clear();
        enemyPattern.clear();
        for (unsigned char row = 0; row < boardSize; ++row) {
            stone = boardTable[row][column];
            this->updatePatterns(ownPattern, enemyPattern, stone);
        }
        score += this->scorePattern(ownPattern) * static_cast<int>(ScoreFactor::AI);
        score += this->scorePattern(enemyPattern) * static_cast<int>(ScoreFactor::ENEMY);
    }
    return score;
}

int Gomoku::BoardEvaluator::scoreLeftDiagonalPatterns() {
    const unsigned char boardSize = this->board.getSize();
    unsigned char **boardTable = this->board.getBoard();
    unsigned char stone;
    std::string ownPattern;
    std::string enemyPattern;
    int score = 0;

    for (char row = boardSize - static_cast<unsigned char>(1); row >= 0; --row) {
        ownPattern.clear();
        enemyPattern.clear();
        for (unsigned char column = 0; column <= (boardSize - static_cast<unsigned char>(1) - row); ++column) {
            stone = boardTable[row + column][column];
            this->updatePatterns(ownPattern, enemyPattern, stone);
        }
        score += this->scorePattern(ownPattern) * static_cast<int>(ScoreFactor::AI);
        score += this->scorePattern(enemyPattern) * static_cast<int>(ScoreFactor::ENEMY);
    }

    for (unsigned char row = 0; row < boardSize - static_cast<unsigned char>(1); ++row) {
        ownPattern.clear();
        enemyPattern.clear();
        for (unsigned char column = (row + static_cast<unsigned char>(1)); column < boardSize; ++column) {
            stone = boardTable[column - (row + static_cast<unsigned char>(1))][column];
            this->updatePatterns(ownPattern, enemyPattern, stone);
        }
        score += this->scorePattern(ownPattern) * static_cast<int>(ScoreFactor::AI);
        score += this->scorePattern(enemyPattern) * static_cast<int>(ScoreFactor::ENEMY);
    }
    return score;
}

int Gomoku::BoardEvaluator::scoreRightDiagonalPatterns() {
    const unsigned char boardSize = this->board.getSize();
    unsigned char **boardTable = this->board.getBoard();
    unsigned char stone;
    std::string ownPattern;
    std::string enemyPattern;
    int score = 0;

    for (unsigned char row = 0; row < boardSize; ++row) {
        ownPattern.clear();
        enemyPattern.clear();
        for (unsigned char column = 0; column <= row; ++column) {
            stone = boardTable[row - column][column];
            this->updatePatterns(ownPattern, enemyPattern, stone);
        }
        score += this->scorePattern(ownPattern) * static_cast<int>(ScoreFactor::AI);
        score += this->scorePattern(enemyPattern) * static_cast<int>(ScoreFactor::ENEMY);
    }

    for (char row = boardSize - static_cast<unsigned char>(2); row >= 0; --row) {
        ownPattern.clear();
        enemyPattern.clear();
        for (unsigned char column = 0; column <= row; ++column) {
            stone = boardTable[(boardSize - static_cast<unsigned char>(1)) - column][
                    (boardSize - static_cast<unsigned char>(1)) - (row - column)];
            this->updatePatterns(ownPattern, enemyPattern, stone);
        }
        score += this->scorePattern(ownPattern) * static_cast<int>(ScoreFactor::AI);
        score += this->scorePattern(enemyPattern) * static_cast<int>(ScoreFactor::ENEMY);
    }
    return score;
}

int Gomoku::BoardEvaluator::evaluateBoard(int scoreFactor) {
    int     rowsScore = this->scoreRowPatterns();

    int     columnsScore = this->scoreColumnPatterns();

    int     leftDiagonalsScore = this->scoreLeftDiagonalPatterns();

    int     rightDiagonalsScore = this->scoreRightDiagonalPatterns();
    int     totalScore;

    totalScore = rowsScore + columnsScore + leftDiagonalsScore + rightDiagonalsScore;
    return totalScore * scoreFactor;
}

void Gomoku::BoardEvaluator::evaluateMoveList(std::vector<Gomoku::MoveData> &moveList, Player player) {
    for (auto &&move : moveList) {
		if (!Gomoku::Brain::running)
			return ;
        this->board.makeMove(move.position, player);
        move.score = this->evaluateMove(move.position, player);
        if (move.score >= Constants::TERMINAL_MOVE_SCORE) {
            move.isTerminal = true;
        }
        this->board.unmakeMove(move.position);
    }
}

void Gomoku::BoardEvaluator::sortMoveList(std::vector<Gomoku::MoveData> &moveList) const {
    std::sort(moveList.begin(), moveList.end(), [](const MoveData &lhs, const MoveData &rhs) {
        return lhs.score > rhs.score;
    });
}

Gomoku::BoardEvaluator::Pattern &Gomoku::BoardEvaluator::getPattern(const std::string &representation) {
    for (auto &&pattern : this->simplePatterns) {
        if (pattern.representation == representation)
            return pattern;
    }
    throw std::runtime_error("Learn to code buddy");
}

size_t Gomoku::BoardEvaluator::getMovePosition(const std::string &move) const {
    return move.find(Constants::MOVE_SYMBOL);
}

Gomoku::BoardEvaluator::MovePositions Gomoku::BoardEvaluator::getMovePositions(Gomoku::BoardEvaluator::MovePatterns &patterns) const {
	return MovePositions {
	  {this->getMovePosition(patterns.horizontalPatterns.first), this->getMovePosition(patterns.horizontalPatterns.second)},
	  {this->getMovePosition(patterns.verticalPatterns.first), this->getMovePosition(patterns.verticalPatterns.second)},
	  {this->getMovePosition(patterns.leftDiagonalPatterns.first), this->getMovePosition(patterns.leftDiagonalPatterns.second)},
	  {this->getMovePosition(patterns.rightDiagonalPatterns.first), this->getMovePosition(patterns.rightDiagonalPatterns.second)}
	};
}

void Gomoku::BoardEvaluator::replaceMoveToken(Gomoku::BoardEvaluator::MovePatterns &patterns, unsigned char token) const {

	std::replace(patterns.horizontalPatterns.first.begin(), patterns.horizontalPatterns.first.end(), Constants::MOVE_SYMBOL, token);
	std::replace(patterns.horizontalPatterns.second.begin(), patterns.horizontalPatterns.second.end(), Constants::MOVE_SYMBOL, token);
	std::replace(patterns.verticalPatterns.first.begin(), patterns.verticalPatterns.first.end(), Constants::MOVE_SYMBOL, token);
	std::replace(patterns.verticalPatterns.second.begin(), patterns.verticalPatterns.second.end(), Constants::MOVE_SYMBOL, token);
	std::replace(patterns.leftDiagonalPatterns.first.begin(), patterns.leftDiagonalPatterns.first.end(), Constants::MOVE_SYMBOL, token);
	std::replace(patterns.leftDiagonalPatterns.second.begin(), patterns.leftDiagonalPatterns.second.end(), Constants::MOVE_SYMBOL, token);
	std::replace(patterns.rightDiagonalPatterns.first.begin(), patterns.rightDiagonalPatterns.first.end(), Constants::MOVE_SYMBOL, token);
	std::replace(patterns.rightDiagonalPatterns.second.begin(), patterns.rightDiagonalPatterns.second.end(), Constants::MOVE_SYMBOL, token);
}












