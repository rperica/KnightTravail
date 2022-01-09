#pragma once

#include "position/Position.h"

namespace KnightTravail
{
	//Singleton class
	class ChessBoard
	{
	public:
		static constexpr int boardSize=8;

		ChessBoard(const ChessBoard&) = delete;
		ChessBoard& operator=(const ChessBoard&) = delete;

		static ChessBoard& Get()
		{
			static ChessBoard instance;
			return instance;
		}

		static bool inRange(const Coordinate& coordinate) { return Get().inRangeInternal(coordinate); }
		static bool isValidChessNotation(const std::string& chessNotation) { return Get().isValidChessNotationInternal(chessNotation); }

	private:
		ChessBoard();

		bool inRangeInternal(const Coordinate& coordinate);
		bool isValidChessNotationInternal(const std::string& chessNotation);
	};
}