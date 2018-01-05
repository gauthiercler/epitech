#include    <iostream>
#include    "Engine.hpp"
#include    "Constants.hpp"

void Gomoku::Engine::run() {
    std::string command;

    while (!this->ended && std::getline(std::cin, command)) {
        if (!command.empty() && command[command.size() - 1] == '\r')
            command.erase(command.size() - 1);
        this->commandManager.parseAndRun(command);
    }
}

void Gomoku::Engine::start(unsigned char size) {
    if (size == 0 || size > Constants::BOARD_MAX_SIZE)
        this->commandManager.sendError("Size is too big");
    else {
        this->board.generate(size);
        this->commandManager.sendOk();
    }
}

void Gomoku::Engine::end() {
    this->ended = true;
}

const unsigned char &Gomoku::Engine::getBoardSize() const {
    return this->board.getSize();
}

void Gomoku::Engine::playTurn() {
    Move    move;

	if (!this->board.isGenerated())
		return ;
    if (this->board.isEmpty()) {
        move = this->brain.getOpeningMove();
    } else {
        move = this->brain.searchBestMove();
    }
    this->makeMove(move, Player::AI);
    this->commandManager.sendMove(move);
}

void Gomoku::Engine::debug() {
	//this->board.dump();
}

void Gomoku::Engine::makeMove(Gomoku::Move move, Gomoku::Player type) {
    this->board.makeMove(move, type);
}

void Gomoku::Engine::takeback(Gomoku::Move move) {
	if (!this->board.isGenerated())
		return ;
	this->board.unmakeMove(move);
	this->commandManager.sendOk();
}

Gomoku::CommandManager &Gomoku::Engine::getCommandManager() {
	return this->commandManager;
}

Gomoku::Board &Gomoku::Engine::getBoard() {
	return this->board;
}

bool Gomoku::Engine::isEnded() const {
	return this->ended;
}