#include "chessboard/Chessboard.h"

namespace KnightTravail
{
    ChessBoard::ChessBoard()
    {

    }

    bool ChessBoard::inRange(const Coordinate& coordinate)
    {
        if (coordinate.x > boardSize-1 || coordinate.x < 0)
        {
            return false;
        }

        if (coordinate.y > boardSize-1 || coordinate.y < 0)
        {
            return false;
        }

        return true;
    }
}

