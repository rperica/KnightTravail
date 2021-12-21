#include "Knight/Knight.h"
#include "chessboard/Chessboard.h"
#include "dts/Queue.h"
#include "dts/Stack.h"

#include <iostream>
#include <assert.h>

namespace KnightTravail
{
	Knight::Knight()
	{
		int sx, sy, dx, dy; 

		std::cout << "Enter starting square: ";
		std::cin >> sx >> sy;
		std::cout << "Enter destination: ";
		std::cin >> dx >> dy;

		assert(m_start = std::make_shared<Position>(sx,sy));
		assert(m_destination = std::make_shared<Position>(dx, dy));
	}

	Knight::~Knight() {}

	int Knight::KnightTravail()
	{
		std::shared_ptr<Position> search = FindDestination();
		if (search)
		{
			std::cout << "Founded at distance: " << search->m_distance<<std::endl;
		}
		else
		{
			std::cout << "Not on a board" << std::endl;
		}

		dts::Stack<std::shared_ptr<Position>> stack;
		for (std::shared_ptr<Position> temp = search; temp != nullptr; temp=temp->m_previousPosition)
		{
			stack.Push(temp);
		}
		
		std::shared_ptr<Position> temp;
		while(!stack.isEmpty())
		{
			temp = stack.Pop();
			std::cout <<*temp<<std::endl;
		}

		std::cout<<"Number of visited squares: " << m_visitedPositions.size() << std::endl;

		return 0;
	}

	std::shared_ptr<Coordinate> Knight::MoveKnight(std::shared_ptr<Coordinate> currentCoordinate, const int& move)
	{
		std::shared_ptr<Coordinate> newCoordinate;

		int x = currentCoordinate->x;
		int y = currentCoordinate->y;

		switch (move)
		{
		case 1:
			x += 2;
			y += 1;
			assert(newCoordinate = std::make_shared<Coordinate>(x, y));
			return newCoordinate;
			break;

		case 2:
			x += 2;
			y += -1;
			assert(newCoordinate = std::make_shared<Coordinate>(x, y));
			return newCoordinate;
			break;

		case 3:
			x += -2;
			y += 1;
			assert(newCoordinate = std::make_shared<Coordinate>(x, y));
			return newCoordinate;
			break;

		case 4:
			x += -2;
			y += -1;
			assert(newCoordinate = std::make_shared<Coordinate>(x, y));
			return newCoordinate;
			break;

		case 5:
			x += 1;
			y += 2;
			assert(newCoordinate = std::make_shared<Coordinate>(x, y));
			return newCoordinate;
			break;

		case 6:
			x += 1;
			y += -2;
			assert(newCoordinate = std::make_shared<Coordinate>(x, y));
			return newCoordinate;
			break;

		case 7:
			x += -1;
			y += 2;
			assert(newCoordinate = std::make_shared<Coordinate>(x, y));
			return newCoordinate;
			break;

		case 8:
			x += -1;
			y += -2;
			assert(newCoordinate = std::make_shared<Coordinate>(x, y));
			return newCoordinate;
			break;
		}

		return nullptr;
	}

	std::shared_ptr<Position> Knight::FindDestination()
	{
		dts::Queue<std::shared_ptr<Position>> queue;
		bool isVisited[ChessBoard::boardSize][ChessBoard::boardSize] = { false };
		std::shared_ptr<Position> currentPosition;
		
		queue.Enqueue(m_start);

		while (!queue.isEmpty())
		{
			currentPosition = queue.Dequeue();
			isVisited[currentPosition->coordinate->x][currentPosition->coordinate->y] = true;

			if (*currentPosition==*m_destination)
				return currentPosition;

			for (int move = 1; move <= 8; move++)
			{
				std::shared_ptr<Coordinate> movedCoordinate = MoveKnight(currentPosition->coordinate, move);

				if (ChessBoard::inRange(*movedCoordinate) && !isVisited[movedCoordinate->x][movedCoordinate->y])
				{
					isVisited[movedCoordinate->x][movedCoordinate->y] = true;
					queue.Enqueue(std::make_shared<Position>(movedCoordinate, currentPosition, currentPosition->m_distance+1));
					m_visitedPositions.push_back(currentPosition);
				}
			}
		}

		return nullptr;
	}
}