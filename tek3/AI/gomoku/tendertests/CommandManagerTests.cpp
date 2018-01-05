#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/Engine.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GomokuTests
{
	TEST_CLASS(CommandManagerTests)
	{
	public:

		TEST_METHOD(Start)
		{
			Gomoku::Engine e;

			e.getCommandManager().parseAndRun("START 20");
			Assert::AreEqual(e.getBoardSize(), static_cast<const unsigned char>(20));
		}

		TEST_METHOD(Turn)
		{
			Gomoku::Engine e;

			e.getCommandManager().parseAndRun("START 20");
			e.getCommandManager().parseAndRun("TURN 2,3");
			unsigned char **board = e.getBoard().getBoard();
			int countStone = 0;
			Assert::AreEqual(board[3][2], Gomoku::Constants::ENEMY_STONE);
			for (int y = 0; y < 20; ++y) {
				for (int x = 0; x < 20; ++x) {
					if (board[y][x] != Gomoku::Constants::EMPTY_SQUARE)
						countStone += 1;
				}
			}
			Assert::AreEqual(countStone, 2);
		}

		TEST_METHOD(Begin)
		{
			Gomoku::Engine e;

			e.getCommandManager().parseAndRun("START 20");
			e.getCommandManager().parseAndRun("BEGIN");
			unsigned char **board = e.getBoard().getBoard();
			int countStone = 0;
			for (int y = 0; y < 20; ++y) {
				for (int x = 0; x < 20; ++x) {
					if (board[y][x] != Gomoku::Constants::EMPTY_SQUARE)
						countStone += 1;
				}
			}
			Assert::AreEqual(countStone, 1);
		}


		TEST_METHOD(End)
		{
			Gomoku::Engine e;

			e.getCommandManager().parseAndRun("START 20");
			Assert::IsFalse(e.isEnded());
			e.getCommandManager().parseAndRun("END");
			Assert::IsTrue(e.isEnded());
		}

		TEST_METHOD(Restart)
		{
			Gomoku::Engine e;

			e.getCommandManager().parseAndRun("START 20");
			e.getCommandManager().parseAndRun("TURN 2,3");
			e.getCommandManager().parseAndRun("RESTART");
			unsigned char **board = e.getBoard().getBoard();
			int countStone = 0;
			Assert::AreEqual(board[3][2], Gomoku::Constants::EMPTY_SQUARE);
			for (int y = 0; y < 20; ++y) {
				for (int x = 0; x < 20; ++x) {
					if (board[y][x] != Gomoku::Constants::EMPTY_SQUARE)
						countStone += 1;
				}
			}
			Assert::AreEqual(countStone, 0);
		}

		TEST_METHOD(Takeback)
		{
			Gomoku::Engine e;

			e.getCommandManager().parseAndRun("START 20");
			e.getCommandManager().parseAndRun("TURN 2,3");
			e.getCommandManager().parseAndRun("TAKEBACK 2,3");
			unsigned char **board = e.getBoard().getBoard();
			int countStone = 0;
			Assert::AreEqual(board[3][2], Gomoku::Constants::EMPTY_SQUARE);
			for (int y = 0; y < 20; ++y) {
				for (int x = 0; x < 20; ++x) {
					if (board[y][x] != Gomoku::Constants::EMPTY_SQUARE)
						countStone += 1;
				}
			}
			Assert::AreEqual(countStone, 1);
		}
	};
}