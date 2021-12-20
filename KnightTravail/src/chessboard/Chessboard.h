#pragma once

#include "position/Position.h"

namespace KnightTravail
{
	class ChessBoard
	{
	public:
		static constexpr int boardSize=8;

		ChessBoard(const ChessBoard&) = delete;
		ChessBoard();

		static bool inRange(const Coordinate& coordinate);

	};
}