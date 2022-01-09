#include "Knight/Knight.h"
#include "chessboard/Chessboard.h"
#include "dts/Queue.h"
#include "dts/Stack.h"
#include "utility/Timer.h"

#include <iostream>
#include <assert.h>

namespace KnightTravail
{
	Knight::Knight() : m_numberOfVisitedSquares(0)
	{
		EnterCoordinates();
	}

	Knight::~Knight() {}

	int Knight::KnightTravail()
	{
		utility::Timer t;

		FindDestination();
		PrintPath();

		std::cout << "Number of visited squares: " << m_numberOfVisitedSquares << std::endl;
		std::cout << "Time: " << t.elapsed() << std::endl;

		return 0;
	}

	int Knight::FindDestination()
	{
		dts::Queue<std::shared_ptr<Position>> queue;
		bool isVisited[ChessBoard::boardSize][ChessBoard::boardSize] = { false };
		std::shared_ptr<Position> currentPosition;
		
		queue.Enqueue(m_start);

		while (!queue.isEmpty())
		{
			currentPosition = queue.Dequeue();
			isVisited[currentPosition->GetCordinate()->x][currentPosition->GetCordinate()->y] = true;

			if (*currentPosition == *m_destination)
			{
				RetracePath(currentPosition);
				return 0;
			}

			for (int move = 0; move < 8; move++)
			{
				std::shared_ptr<Coordinate> movedCoordinate = MoveKnight(currentPosition->GetCordinate(), move);

				if (ChessBoard::inRange(*movedCoordinate) && !isVisited[movedCoordinate->x][movedCoordinate->y])
				{
					isVisited[movedCoordinate->x][movedCoordinate->y] = true;
					queue.Enqueue(std::make_shared<Position>(movedCoordinate, currentPosition, currentPosition->GetDistance()+1));
					m_numberOfVisitedSquares++;
				}
			}
		}

		return 1;
	}

	std::shared_ptr<Coordinate> Knight::MoveKnight(const std::shared_ptr<Coordinate>& currentCoordinate, const int& move)
	{
		std::shared_ptr<Coordinate> newCoordinate;
		
		const int moveX[8] = { 2,2,-2,-2,1,1,-1,-1 };
		const int moveY[8] = { 1,-1,1,-1,2,-2,2,-2 };

		int x = currentCoordinate->x + moveX[move];
		int y = currentCoordinate->y + moveY[move];

		assert(newCoordinate = std::make_shared<Coordinate>(x, y));
		return newCoordinate;
	}

	int Knight::RetracePath(const std::shared_ptr<Position>& destination)
	{
		if (!m_knightPath.empty())
		{
			m_knightPath.clear();
		}

		dts::Stack<std::shared_ptr<Position>> stack;
		for (std::shared_ptr<Position> temp = destination; temp != nullptr; temp = temp->GetPreviousPosition())
		{
			stack.Push(temp);
		}

		std::shared_ptr<Position> tempPosition;
		while (!stack.isEmpty())
		{
			tempPosition = stack.Pop();
			m_knightPath.push_back(tempPosition);
		}

		return 0;
	}

	int Knight::PrintPath()
	{
		if (m_knightPath.empty())
		{
			std::cout << "Not on board" << std::endl;
			return 1;
		}

		for (auto it = m_knightPath.begin(); it != m_knightPath.end(); it++)
		{
			std::cout << *(*it) << std::endl;
		}

		return 0;
	}

	int Knight::EnterCoordinates()
	{
		std::string start;
		std::string destination;

		bool checkStart = false;
		bool checkDest = false;

		do
		{
			std::cout << "Use chess notation in range (a-h)(1-8); example: e4" << std::endl;

			if (!checkStart)
			{
				std::cout << "Enter start: ";
				std::cin >> start;
			}

			if (!checkDest)
			{
				std::cout << "Enter destination: ";
				std::cin >> destination;
			}

			checkStart = ChessBoard::isValidChessNotation(start);
			checkDest = ChessBoard::isValidChessNotation(destination);

			if (!checkStart)
			{
				std::cout << "Start position is invalid, please renter!" << std::endl;
			}

			if (!checkDest)
			{
				std::cout << "Destination position is invalid, please renter!" << std::endl;
			}

		} while (!(checkStart && checkDest));

		assert(m_start = std::make_shared<Position>(start));
		assert(m_destination = std::make_shared<Position>(destination));

		return 0;
	}
}