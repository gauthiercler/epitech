#ifndef GOMOKU_BOARDEVALUATOR_HPP
#define GOMOKU_BOARDEVALUATOR_HPP

#include <vector>
#include <functional>
#include <unordered_map>
#include "Move.hpp"
#include "Constants.hpp"

namespace Gomoku {

    class Board;

    class BoardEvaluator {

	public:
	  struct MovePositions {
		std::pair<size_t, size_t> horizontalPositions;
		std::pair<size_t, size_t> verticalPositions;
		std::pair<size_t, size_t> leftDiagonalPositions;
		std::pair<size_t, size_t> rightDiagonalPositions;
	  };

    private:

        struct  MovePatterns {
            std::pair<std::string, std::string> horizontalPatterns;
            std::pair<std::string, std::string> verticalPatterns;
            std::pair<std::string, std::string> leftDiagonalPatterns;
            std::pair<std::string, std::string> rightDiagonalPatterns;
        };

        struct  Pattern {
            int                 id;
            std::string         representation;
            int                 score;
            bool                reversible;
            bool                hasSubPatterns;
            std::vector<int>    fatherPatterns;

            inline bool         hasFathers() { return !this->fatherPatterns.empty(); }
        };

        struct CompositePattern {
            Pattern                 first;
            Pattern                 second;
            std::pair<int, int>     patternIndexes;
		  	int						score;
        };

        enum class OrientationLine : int {
            HORIZONTAL,
            VERTICAL,
            LEFT_DIAGONAL,
            RIGHT_DIAGONAL
        };


        Board                           							&board;
        std::vector<Pattern>            							simplePatterns;
        std::vector<CompositePattern>   							compositePatterns;
        std::unordered_map<int, std::vector<std::pair<int, int>>>   patternOccurrences;
        std::unordered_map<OrientationLine, std::vector<int>>       compositePatternOccurences;

        size_t          getMovePosition(const std::string &move) const;
	  	MovePositions	getMovePositions(MovePatterns &patterns) const;
	  	void			replaceMoveToken(MovePatterns &patterns, unsigned char token) const;


        Pattern         &getPattern(const std::string &representation);
        void            updatePatterns(std::string &ownPattern, std::string &enemyPattern, unsigned char ownStone, unsigned char boardStone) const;

        std::pair<std::string, std::string>     generatePattern(Move move, unsigned char ownStone, char hIncrement, char vIncrement, char hDelta, char vDelta) const;
        MovePatterns    generateMovePatterns(Move move, unsigned char stone) const;

        int             getSimplePatternScore(std::string &movePattern) ;
        bool            hasCompositePattern(const std::string &firstPattern,
											const std::string &secondPattern,
											size_t firstPatternPosition,
											size_t secondPatternPosition);

        std::pair<int, int> getSimpleMoveScore(std::pair<std::string, std::string> &move);
	  	int             	getCompositePatternScores(MovePatterns &movePatterns, Move &move, Player player);
	  	std::pair<int, int> getCompositePatternMoveScores(MovePatterns &patterns, Move &move);

        int             scoreMovePatterns(MovePatterns &movePatterns, Move &move);

        inline void     updatePatterns(std::string &ownPattern, std::string &enemyPattern, unsigned char stone) const {
            if (stone == Constants::AI_STONE) {
                ownPattern += 'X';
                enemyPattern += 'O';
            } else if (stone == Constants::ENEMY_STONE) {
                ownPattern += 'O';
                enemyPattern += 'X';
            } else {
                ownPattern += '-';
                enemyPattern += '-';
            }
        }
        inline void     clearPatternOccurrence() {
            for (auto &&occurrence : this->patternOccurrences) {
                occurrence.second.clear();
            }
        }

        bool            patternIsInvalidChild(Pattern &patternData, size_t found_index) const;
        int             scoreOrientedPattern(Pattern &patternData, const std::string &pattern, bool reversed);
        int             scorePattern(const std::string &pattern);
        int             scoreRowPatterns();
        int             scoreColumnPatterns();
        int             scoreLeftDiagonalPatterns();
        int             scoreRightDiagonalPatterns();


	  int getCompositePatternScore(const std::string &movePattern,
								   size_t movePosition,
								   OrientationLine orientation, Move &move, Player player);
	  bool findCompositePattern(const MovePatterns &patterns, const MovePositions &positions, Player player);


    public:

        explicit BoardEvaluator(Board &board);
        ~BoardEvaluator() = default;

        int     evaluateBoard(int scoreFactor);
        void    evaluateMoveList(std::vector<MoveData> &moveList, Player player);
        void    sortMoveList(std::vector<MoveData> &moveList) const;
        int     evaluateMove(Move &move, Player player);

    };

}

#endif //GOMOKU_BOARDEVALUATOR_HPP
