#pragma once

#include "position/Position.h"

#include <vector>

namespace KnightTravail
{
	class Knight
	{
	private:
		int m_numberOfVisitedSquares;
		
		std::shared_ptr<Position> m_start;
		std::shared_ptr<Position> m_destination;

		std::vector<std::shared_ptr<Position>> m_knightPath;

		std::shared_ptr<Coordinate> MoveKnight(const std::shared_ptr<Coordinate>& currentCoordinate, const int& move);
		
		int FindDestination();
		int RetracePath(const std::shared_ptr<Position>& destination);
		int PrintPath();
		int EnterCoordinates();

	public:
		Knight(const Knight&) = delete;

		Knight();
		~Knight();
		
		int KnightTravail();
	};
}