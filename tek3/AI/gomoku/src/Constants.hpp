#ifndef GOMOKU_CONSTANTS_HPP
#define GOMOKU_CONSTANTS_HPP

#include    <string>

namespace Gomoku {

    enum class Player : unsigned int {
        AI,
        Enemy
    };

    namespace Constants {

        const unsigned char     AI_STONE = 'O';
        const unsigned char     ENEMY_STONE = 'X';
        const unsigned char     EMPTY_SQUARE = '-';

        const unsigned char     MOVE_SYMBOL = 'Y';

        const unsigned char     BOARD_MAX_SIZE = 20;
        const unsigned int      MOVE_LIST_MAX_SIZE = 400;
        const unsigned int      LATE_MOVE_REDUCTOR = 5;

		const unsigned char		NEIGHBOR_DISTANCE = 2;
        const int               TERMINAL_MOVE_SCORE = 100000;

        const char * const      ABOUT_INFO = R"(name="TenderFlow", version="1.0", author="Ventinc/Gogo/Rubysh", country="FRA")";

        namespace Patterns {

            const unsigned char     PATTERN_LENGTH = 8;

            const char              HORIZONTAL_H_INCREMENT = 1;
            const char              HORIZONTAL_V_INCREMENT = 0;
            const char              HORIZONTAL_H_DELTA = 4;
            const char              HORIZONTAL_V_DELTA = 0;

            const char              VERTICAL_H_INCREMENT = 0;
            const char              VERTICAL_V_INCREMENT = 1;
            const char              VERTICAL_H_DELTA = 0;
            const char              VERTICAL_V_DELTA = 4;

            const char              LEFT_DIAGONAL_H_INCREMENT = 1;
            const char              LEFT_DIAGONAL_V_INCREMENT = 1;
            const char              LEFT_DIAGONAL_H_DELTA = 4;
            const char              LEFT_DIAGONAL_V_DELTA = 4;

            const char              RIGHT_DIAGONAL_H_INCREMENT = -1;
            const char              RIGHT_DIAGONAL_V_INCREMENT = 1;
            const char              RIGHT_DIAGONAL_H_DELTA = -4;
            const char              RIGHT_DIAGONAL_V_DELTA = 4;


        }
    }
}

#endif //GOMOKU_CONSTANTS_HPP
