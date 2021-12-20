#pragma once

#include "position/Position.h"

namespace KnightTravail
{
	class Knight
	{
	public:
		Position* m_start;
		Position* m_destination;

		Knight(const Knight&) = delete;

		Knight();
		~Knight();
		
		int KnightTravail();
	private:
		Coordinate* MoveKnight(Coordinate* currentCoordinate, const int& move);
		Position* FindDestination();
	};
}