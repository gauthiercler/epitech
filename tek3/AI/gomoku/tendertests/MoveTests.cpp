#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/Move.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GomokuTests
{
	TEST_CLASS(MoveTests)
	{
	public:

		TEST_METHOD(Convert)
		{
			unsigned int pos = static_cast<unsigned int>(Gomoku::Utils::Move::getMove(2, 3));
			Assert::AreEqual(pos, static_cast<unsigned int>(770));
		}

		TEST_METHOD(GetX)
		{
			unsigned int pos = static_cast<unsigned int>(Gomoku::Utils::Move::getMove(2, 3));
			Assert::AreEqual(Gomoku::Utils::Move::getPosX(pos), static_cast<unsigned char>(2));
		}

		TEST_METHOD(GetY)
		{
			unsigned int pos = static_cast<unsigned int>(Gomoku::Utils::Move::getMove(2, 3));
			Assert::AreEqual(Gomoku::Utils::Move::getPosY(pos), static_cast<unsigned char>(3));
		}
	};
}