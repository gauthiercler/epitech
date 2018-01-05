#include    <cstdlib>
#include    <cstring>
#include    <stdexcept>
#include    <iostream>
#include    "Board.hpp"
#include    "Constants.hpp"

void Gomoku::Board::generate(unsigned char size) {
    if (this->board) {
        this->clean();
    }
    this->allocate(size);
    this->setSize(size);
}

void Gomoku::Board::clean() {
    for (int index = 0; this->board[index]; index++)
        delete[] this->board[index];
    delete[] this->board;
    this->board = nullptr;
}

void Gomoku::Board::allocate(unsigned char size) {
    this->empty = true;
    this->board = new unsigned char *[size + 1];
    for (int index = 0; index < size; index++) {
        this->board[index] = new unsigned char[size + 1];
        std::memset(this->board[index], Constants::EMPTY_SQUARE, size);
        this->board[index][size] = '\0';
    }
    this->board[size] = nullptr;
}

void Gomoku::Board::dump() const {
    for (int index = 0; this->board[index]; index++)
        std::cout << this->board[index] << std::endl;
}

void Gomoku::Board::setSize(const unsigned char &size) {
    this->size = size;
}

const unsigned char &Gomoku::Board::getSize() const {
    return this->size;
}

unsigned char **Gomoku::Board::getBoard() const {
    return this->board;
}

void Gomoku::Board::makeMove(unsigned char x, unsigned char y, Gomoku::Player player) {
    this->board[y][x] = (player == Player::AI) ? Constants::AI_STONE : Constants::ENEMY_STONE;
}

void Gomoku::Board::makeMove(Gomoku::Move move, Gomoku::Player player) {
    this->board[Utils::Move::getPosY(move)][Utils::Move::getPosX(move)] = (player == Player::AI) ? Constants::AI_STONE : Constants::ENEMY_STONE;
}

void Gomoku::Board::unmakeMove(unsigned char x, unsigned char y) {
    this->board[y][x] = Constants::EMPTY_SQUARE;
}

void Gomoku::Board::unmakeMove(Gomoku::Move move) {
    this->board[Utils::Move::getPosY(move)][Utils::Move::getPosX(move)] = Constants::EMPTY_SQUARE;
}

bool Gomoku::Board::isEmpty() {
    if (!this->empty) { return false; }
    else {
        for (unsigned char y = 0 ; y < this->size ; ++y) {
            for (unsigned char x = 0 ; x < this->size ; ++x) {
                if (this->board[y][x] != Constants::EMPTY_SQUARE) {
                    this->empty = !this->empty;
                    return false;
                }
            }
        }
    }
    return true;
}

const Gomoku::MoveGenerator &Gomoku::Board::getMoveGenerator() {
    return this->moveGenerator;
}

Gomoku::BoardEvaluator &Gomoku::Board::getEvaluator() {
    return this->boardEvaluator;
}

int Gomoku::Board::getNbMovesPlayed() {
	int count = 0;

	for (int y = 0; y < this->size; ++y) {
		for (int x = 0; x < this->size; ++x) {
			if (this->board[y][x] != Constants::EMPTY_SQUARE)
				count++;
		}
	}
	return count;
}

bool Gomoku::Board::isGenerated() const {
	return this->board != nullptr;
}
