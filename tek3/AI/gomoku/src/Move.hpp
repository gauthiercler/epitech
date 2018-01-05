#ifndef GOMOKU_MOVE_HPP
#define GOMOKU_MOVE_HPP

namespace Gomoku {

    typedef unsigned short  Move;
    struct  MoveData {
        Move    position;
        int     score;
        bool    isTerminal;
    };

    namespace Utils {

        namespace Move {

            inline unsigned char    getPosX(Gomoku::Move move) {
                return static_cast<unsigned char>(move);
            }

            inline unsigned char    getPosY(Gomoku::Move move) {
                return static_cast<unsigned char>(move >> 8);
            }

            inline Gomoku::Move     getMove(unsigned char x, unsigned char y) {
                return static_cast<unsigned short>(y) << 8 | x;
            }

        }
    }
}

#endif //GOMOKU_MOVE_HPP
