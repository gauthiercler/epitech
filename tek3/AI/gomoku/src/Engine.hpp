#ifndef GOMOKU_ENGINE_HPP
#define GOMOKU_ENGINE_HPP

#include <functional>
#include "CommandManager.hpp"
#include "Brain.hpp"
#include "Board.hpp"

namespace Gomoku {

    class Engine {

    private:

        Board           board;
        CommandManager  commandManager;
        Brain           brain;
        bool            ended;

    public:

        Engine() : board(), commandManager(*this), brain(this->board), ended(false) {};
        ~Engine() = default;

        void    run();
        void    start(unsigned char size);
        void    makeMove(Move move, Player type);
		void	takeback(Move move);
        void    playTurn();
        void    end();
        const unsigned char &getBoardSize() const;
        void    debug();
		CommandManager &getCommandManager();
		Board		   &getBoard();
		bool	isEnded() const;
    };

}


#endif //GOMOKU_ENGINE_HPP
