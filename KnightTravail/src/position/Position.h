#pragma once

#include <iostream>
#include <string>
#include <memory>

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
		std::shared_ptr<Position> m_previousPosition;
		std::shared_ptr<Coordinate> coordinate;

		int m_distance;

	public:
		Position(std::shared_ptr<Coordinate> coordinate, std::shared_ptr<Position> previousPosition, const int& distance);
		Position(const int& x, const int& y);
		~Position();

		friend bool operator==(const Position& p1, const Position& p2);
		friend std::ostream& operator<<(std::ostream& out, const Position& p);
	};
}