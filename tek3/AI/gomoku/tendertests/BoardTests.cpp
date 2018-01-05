#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/Board.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GomokuTests
{		
	TEST_CLASS(BoardTests)
	{
	public:
		
		TEST_METHOD(Generate)
		{
			Gomoku::Board b;

			b.generate(10);
			Assert::AreEqual(b.getSize(), static_cast<unsigned char>(10));
		}

		TEST_METHOD(MakeAI)
		{
			Gomoku::Board b;

			b.generate(10);
			b.makeMove(2, 2, Gomoku::Player::AI);
			unsigned char **board = b.getBoard();
			Assert::AreEqual(board[2][2], Gomoku::Constants::AI_STONE);
		}

		TEST_METHOD(MakeEnemy)
		{
			Gomoku::Board b;

			b.generate(10);
			b.makeMove(2, 2, Gomoku::Player::Enemy);
			unsigned char **board = b.getBoard();
			Assert::AreEqual(board[2][2], Gomoku::Constants::ENEMY_STONE);
		}

		TEST_METHOD(UnMake)
		{
			Gomoku::Board b;

			b.generate(10);
			b.makeMove(2, 2, Gomoku::Player::AI);
			b.unmakeMove(2, 2);
			unsigned char **board = b.getBoard();
			Assert::AreEqual(board[2][2], Gomoku::Constants::EMPTY_SQUARE);
		}
	};
}