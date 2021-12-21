#include "position/Position.h"

#include <assert.h>

namespace KnightTravail
{
	Position::Position(std::shared_ptr<Coordinate> coordinate, std::shared_ptr<Position> previous, const int& distance)
		:coordinate(coordinate), 
		m_previousPosition(previous),
		m_distance(distance) {}

	Position::Position(const int& x, const int& y):m_previousPosition(nullptr), m_distance(0) 
	{ 
		assert(coordinate = std::make_shared<Coordinate>(x, y)); 
	}

	Position::~Position() {}

	Coordinate::Coordinate(const int& x, const int& y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator==(const Position& p1, const Position& p2)
	{
		return p1.coordinate->x == p2.coordinate->x && p1.coordinate->y == p2.coordinate->y;
	}

	std::ostream& operator<<(std::ostream& out, const Position& p)
	{
		out << "Distance:" << p.m_distance << " X:" << p.coordinate->x << " Y:" << p.coordinate->y;
		return out;
	}
}