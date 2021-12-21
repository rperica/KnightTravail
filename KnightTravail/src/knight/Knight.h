#pragma once

#include "position/Position.h"

#include <vector>

namespace KnightTravail
{
	class Knight
	{
	private:
		Position* m_start;
		Position* m_destination;

		std::vector<Position*> m_visitedPositions;

	public:
		Knight(const Knight&) = delete;

		Knight();
		~Knight();
		
		int KnightTravail();
	private:
		Coordinate* MoveKnight(Coordinate* currentCoordinate, const int& move);
		Position* FindDestination();
	};
}