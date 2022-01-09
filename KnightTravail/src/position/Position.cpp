#include "position/Position.h"
#include "chessboard/Chessboard.h"

#include <assert.h>
#include <vector>

namespace KnightTravail
{
	Position::Position(std::shared_ptr<Coordinate> coordinate, std::shared_ptr<Position> previous, const int& distance)
		:m_coordinate(coordinate), 
		m_previousPosition(previous),
		m_distance(distance) {}

	Position::Position(const int& x, const int& y):m_previousPosition(nullptr), m_distance(0) 
	{ 
		assert(m_coordinate = std::make_shared<Coordinate>(x, y)); 
	}

	Position::Position(const std::string& coordinate) : m_previousPosition(nullptr), m_distance(0)
	{
		assert(m_coordinate = std::make_shared<Coordinate>(coordinate));
	}

	Position::~Position() {}

	Coordinate::Coordinate(const int& x, const int& y)
	{
		this->x = x;
		this->y = y;

		ConvertToChessNotation();
	}

	Coordinate::Coordinate(const std::string& coordinate):chessNotation(coordinate)
	{
		ConvertFromChessNotation();
	}

	int Coordinate::ConvertFromChessNotation()
	{
		const int coordinateY[8] = { 0,1,2,3,4,5,6,7 };
		const int coordinateX[8] = { 7,6,5,4,3,2,1,0 };

		this->y = coordinateY[chessNotation[0] - 97]; // ASCII 'a' => 97 
		this->x = coordinateX[chessNotation[1] - 49]; // ASCII '1' => 49

		return 0;
	}

	int Coordinate::ConvertToChessNotation()
	{
		const char letterNotation[8] = { 'a','b','c','d','e','f','g','h' };
		const char numberNotation[8] = { '8','7','6','5','4','3','2','1' };
	
		if (ChessBoard::inRange(*this))
		{
			chessNotation += letterNotation[this->y];
			chessNotation += numberNotation[this->x];

			return 0;
		}	

		return 1;
	}

	bool operator==(const Position& p1, const Position& p2)
	{
		return p1.m_coordinate->x == p2.m_coordinate->x && p1.m_coordinate->y == p2.m_coordinate->y;
	}

	std::ostream& operator<<(std::ostream& out, const Position& p)
	{
		if (p.GetDistance() == 0)
		{
			out << "Start: " << p.GetCordinate()->chessNotation;
		}
		else
		{
			out << "Move " << p.m_distance << ": N" << p.GetCordinate()->chessNotation;
		}

		return out;
	}
}