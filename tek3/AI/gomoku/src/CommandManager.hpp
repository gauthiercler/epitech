#ifndef GOMOKU_COMMANDMANAGER_HPP
#define GOMOKU_COMMANDMANAGER_HPP

#include    <regex>
#include    "Move.hpp"

namespace Gomoku {

    class Engine;

    class CommandManager {

    private:

        Engine  &engine;
        std::vector<std::pair<std::regex, std::function<bool(const std::string &value)>>> commands;
        const std::regex boardRegex = std::regex("^[0-9]{1,3},[0-9]{1,3},[1-3]$");

        void    send(const std::string &value);
        bool    start(const std::string &value);
        bool    turn(const std::string &value);
        bool    begin(const std::string &value);
        bool    board(const std::string &value);
        bool    info(const std::string &value);
        bool    end(const std::string &value);
        bool    about(const std::string &value);
        bool    restart(const std::string &value);
		bool	takeback(const std::string &value);

    public:

        explicit    CommandManager(Engine &engine);
        ~CommandManager() = default;

        void        parseAndRun(const std::string &value);
        void        sendError(const std::string &value);
        void        sendAbout();
        void        sendMove(Move move);
        void        sendDebug(const std::string &value);
        void        sendOk();
    };

}

#endif //GOMOKU_COMMANDMANAGER_HPP
