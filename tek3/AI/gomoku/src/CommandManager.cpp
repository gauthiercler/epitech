#include    <string>
#include    <sstream>
#include    <iostream>
#include    "Engine.hpp"
#include    "Constants.hpp"

Gomoku::CommandManager::CommandManager(Engine &engine) : engine(engine) {
    this->commands = {
            {std::regex("^START [0-9]+$"), std::bind(&Gomoku::CommandManager::start, *this, std::placeholders::_1)},
            {std::regex("^TURN [0-9]+,[0-9]+$"), std::bind(&Gomoku::CommandManager::turn, *this, std::placeholders::_1)},
            {std::regex("^TAKEBACK [0-9]+,[0-9]+$"), std::bind(&Gomoku::CommandManager::takeback, *this, std::placeholders::_1)},
            {std::regex("^BEGIN$"), std::bind(&Gomoku::CommandManager::begin, *this, std::placeholders::_1)},
            {std::regex("^BOARD$"), std::bind(&Gomoku::CommandManager::board, *this, std::placeholders::_1)},
            {std::regex("^INFO (?:timeout_turn|timeout_match|max_memory|time_left|game_type|rule|evaluate|folder) \\S+$"),
					std::bind(&Gomoku::CommandManager::info, *this, std::placeholders::_1)},
            {std::regex("^END$"), std::bind(&Gomoku::CommandManager::end, *this, std::placeholders::_1)},
            {std::regex("^ABOUT$"), std::bind(&Gomoku::CommandManager::about, *this, std::placeholders::_1)},
            {std::regex("^RESTART$"), std::bind(&Gomoku::CommandManager::restart, *this, std::placeholders::_1)}
    };
}

void Gomoku::CommandManager::send(const std::string &value) {
    std::cout << value << std::endl;
    std::flush(std::cout);
}

void Gomoku::CommandManager::sendError(const std::string &value) {
    this->send("ERROR " + value);
}

void Gomoku::CommandManager::sendOk() {
    this->send("OK");
}

bool Gomoku::CommandManager::start(const std::string &value) {
    int     boardSize = std::stoi(value.substr(6));

    if (boardSize < 0 || boardSize > Constants::BOARD_MAX_SIZE) {
        boardSize = 0;
    }
    this->engine.start(static_cast<unsigned char>(boardSize));
    return true;
}

bool Gomoku::CommandManager::turn(const std::string &value) {
    std::istringstream token(value.substr(5));
    std::string delimiter;
    int x;
    int y;

    getline(token, delimiter, ',');
    x = std::stoi(delimiter);
    getline(token, delimiter, ',');
    y = std::stoi(delimiter);

    if (x < 0 || x >= this->engine.getBoardSize() || y < 0 || y >= this->engine.getBoardSize()) {
        this->sendError("Can't add enemy stone on the board");
    } else {
        this->engine.makeMove(Utils::Move::getMove(static_cast<unsigned char>(x), static_cast<unsigned char>(y)), Player::Enemy);
        this->engine.debug();
    }
    this->engine.playTurn();
    return true;
}

bool Gomoku::CommandManager::begin(const std::string &value) {
    this->engine.playTurn();
    return true;
}

bool Gomoku::CommandManager::board(const std::string &value) {
    std::string boardLine;
    std::string delimiter;
    int x;
    int y;
    int player;

    while (std::getline(std::cin, boardLine)) {
        this->sendDebug(boardLine);
        if (boardLine == "DONE")
            break;
        if (!std::regex_match(boardLine, this->boardRegex)) {
            this->sendError("Line in board feed is not correct");
            break;
        } else {
            std::istringstream token(boardLine);

            getline(token, delimiter, ',');
            x = std::stoi(delimiter);
            getline(token, delimiter, ',');
            y = std::stoi(delimiter);
            getline(token, delimiter, ',');
            player = std::stoi(delimiter);

            if (x < 0 || x >= this->engine.getBoardSize() ||
                y < 0 || y >= this->engine.getBoardSize() || (player != 1 && player != 2 && player != 3)) {
                this->sendError("Line in board feed is not correct");
                break;
            }
            this->engine.makeMove(Utils::Move::getMove(static_cast<unsigned char>(x), static_cast<unsigned char>(y)), player == 1 ? Player::AI : Player::Enemy);
        }
    }
    this->engine.playTurn();
    return true;
}

bool Gomoku::CommandManager::info(const std::string &value) {
    return true;
}

bool Gomoku::CommandManager::end(const std::string &value) {
    this->engine.end();
    return true;
}

bool Gomoku::CommandManager::about(const std::string &value) {
    this->sendAbout();
    return true;
}

bool Gomoku::CommandManager::restart(const std::string &value) {
    this->engine.start(this->engine.getBoardSize());
    return true;
}

void Gomoku::CommandManager::parseAndRun(const std::string &command) {
    this->sendDebug("Command : " + command);
    for (auto &&currentCommand : this->commands)
        if (std::regex_match(command, currentCommand.first)) {
            currentCommand.second(command);
        }
    this->engine.debug();
}

void Gomoku::CommandManager::sendAbout() {
    this->send(Constants::ABOUT_INFO);
}

void Gomoku::CommandManager::sendMove(Move move) {
    auto x = Utils::Move::getPosX(move);
    auto y = Utils::Move::getPosY(move);

    this->send(std::to_string(x) + "," + std::to_string(y));
}

void Gomoku::CommandManager::sendDebug(const std::string &value) {
    this->send("DEBUG " + value);
}

bool Gomoku::CommandManager::takeback(const std::string &value) {
	std::istringstream token(value.substr(9));
	std::string delimiter;
	int x;
	int y;

	getline(token, delimiter, ',');
	x = std::stoi(delimiter);
	getline(token, delimiter, ',');
	y = std::stoi(delimiter);

	if (x < 0 || x >= this->engine.getBoardSize() || y < 0 || y >= this->engine.getBoardSize()) {
		this->sendError("Can't remove stone at this position : " + std::to_string(x) + "," + std::to_string(y));
	} else {
		this->engine.takeback(Utils::Move::getMove(static_cast<unsigned char>(x), static_cast<unsigned char>(y)));
	}
	return true;
}
