#include "position/Position.h"

#include <assert.h>

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
		if (chessNotation.size() != 2)
		{
			this->x = 99;
			this->y = 99;

			return 1;
		}

		switch (chessNotation[0])
		{
		case 'a':
			this->y = 0;
			break;
		case 'b':
			this->y = 1;
			break;
		case 'c':
			this->y = 2;
			break;
		case 'd':
			this->y = 3;
			break;
		case 'e':
			this->y = 4;
			break;
		case 'f':
			this->y = 5;
			break;
		case 'g':
			this->y = 6;
			break;
		case 'h':
			this->y = 7;
			break;
		default:
			this->y = 99;
			break;
		}

		switch (chessNotation[1])
		{
		case '1':
			this->x = 7;
			break;
		case '2':
			this->x = 6;
			break;
		case '3':
			this->x = 5;
			break;
		case '4':
			this->x = 4;
			break;
		case '5':
			this->x = 3;
			break;
		case '6':
			this->x = 2;
			break;
		case '7':
			this->x = 1;
			break;
		case '8':
			this->x = 0;
			break;
		default:
			this->y = 99;
			break;
		}

		return 0;
	}

	int Coordinate::ConvertToChessNotation()
	{
		switch (this->y)
		{
		case 0:
			chessNotation += 'a';
			break;
		case 1:
			chessNotation += 'b';
			break;
		case 2:
			chessNotation += 'c';
			break;
		case 3:
			chessNotation += 'd';
			break;
		case 4:
			chessNotation += 'e';
			break;
		case 5:
			chessNotation += 'f';
			break;
		case 6:
			chessNotation += 'g';
			break;
		case 7:
			chessNotation += 'h';
			break;
		default:
			break;
		}

		switch (this->x)
		{
		case 0:
			chessNotation += '8';
			break;
		case 1:
			chessNotation += '7';
			break;
		case 2:
			chessNotation += '6';
			break;
		case 3:
			chessNotation += '5';
			break;
		case 4:
			chessNotation += '4';
			break;
		case 5:
			chessNotation += '3';
			break;
		case 6:
			chessNotation += '2';
			break;
		case 7:
			chessNotation += '1';
			break;
		default:
			break;
		}

		return 0;
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