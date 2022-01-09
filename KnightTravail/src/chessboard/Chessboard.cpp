#include "chessboard/Chessboard.h"

namespace KnightTravail
{
    ChessBoard::ChessBoard() {}
     
    bool ChessBoard::inRangeInternal(const Coordinate& coordinate)
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

    bool ChessBoard::isValidChessNotationInternal(const std::string& chessNotation)
    {
        if (chessNotation.size() != 2)
            return false;

        const char letterNotation[8] = { 'a','b','c','d','e','f','g','h' };
        const char numberNotation[8] = { '8','7','6','5','4','3','2','1' };

        bool isValidLetter=false;
        bool isValidNumber=false;

        for (int i = 0; i < 8; i++)
        {
            if(!isValidLetter)
                isValidLetter = chessNotation[0] == letterNotation[i];

            if (!isValidNumber)
                isValidNumber = chessNotation[1] == numberNotation[i];

            if (isValidLetter && isValidNumber)
                return true;
        }

        return false;
    }
}

