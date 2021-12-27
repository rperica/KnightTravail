#pragma once

#include "position/Position.h"

#include <vector>

namespace KnightTravail
{
	class Knight
	{
	private:
		std::shared_ptr<Position> m_start;
		std::shared_ptr<Position> m_destination;

		std::vector<std::shared_ptr<Position>> m_visitedPositions;

	public:
		Knight(const Knight&) = delete;

		Knight();
		~Knight();
		
		int KnightTravail();
	private:
		std::shared_ptr<Position> FindDestination();
		std::shared_ptr<Coordinate> MoveKnight(std::shared_ptr<Coordinate> currentCoordinate, const int& move);
	};
}