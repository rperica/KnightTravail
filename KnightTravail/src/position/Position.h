#pragma once

#include <iostream>
#include <string>

namespace KnightTravail
{
	struct Coordinate
	{
		int x;
		int y;

		Coordinate(const int& x, const int& y);
	};

	class Position
	{
	public:
		Position* m_previousPosition;
		Coordinate* coordinate;
		int m_distance;

	public:
		Position(Coordinate* coordinate, Position* previousPosition,const int& distance);
		Position(const int& x, const int& y);
		~Position();

		friend bool operator==(const Position& p1, const Position& p2);
		friend std::ostream& operator<<(std::ostream& out, const Position& p);
	};
}