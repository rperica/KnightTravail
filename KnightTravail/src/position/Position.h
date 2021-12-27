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
		
		std::string chessNotation;

		Coordinate(const int& x, const int& y);
		Coordinate(const std::string& coordinate);

		int ConvertFromChessNotation();
		int ConvertToChessNotation();
	};

	class Position
	{
	private:
		std::shared_ptr<Position> m_previousPosition;
		std::shared_ptr<Coordinate> m_coordinate;

		int m_distance;

	public:
		Position(std::shared_ptr<Coordinate> coordinate, std::shared_ptr<Position> previousPosition, const int& distance);
		Position(const int& x, const int& y);
		Position::Position(const std::string& coordinate);
		~Position();

		friend bool operator==(const Position& p1, const Position& p2);
		friend std::ostream& operator<<(std::ostream& out, const Position& p);

		inline int GetDistance() const { return m_distance;  }
		inline std::shared_ptr<Coordinate> GetCordinate() const { return m_coordinate;  }
		inline std::shared_ptr<Position> GetPreviousPosition() const { return m_previousPosition; }
	};
}