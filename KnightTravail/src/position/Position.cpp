#include "position/Position.h"

#include <assert.h>

namespace KnightTravail
{
	Position::Position(Coordinate* coordinate, Position* previous, const int& distance)
		:coordinate(coordinate), 
		m_previousPosition(previous),
		m_distance(distance) {}

	Position::Position(const int& x, const int& y):m_previousPosition(nullptr), m_distance(0) 
	{ 
		assert(coordinate = new Coordinate(x, y)); 
	}

	Position::~Position()
	{
		delete coordinate;
	}

	Coordinate::Coordinate(const int& x, const int& y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator==(const Position& p1, const Position& p2)
	{
		return p1.coordinate->x == p2.coordinate->x && p1.coordinate->y == p2.coordinate->y;
	}
}