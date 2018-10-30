#include "Move.h"

Board::Move::Move(Board board, std::string strMove)
{
    originB = board;
    this->strMove = strMove;
    this->iDark = 0;
    possibleKinds = std::map<char, int>();
//    board.makeMove(strMove);
//    this->possibleBoards[board] = 1;
}

Board::Move::Move(Board board, std::string strMove, int iDark, std::map<char, int> possibleChar)
{
    originB = board;
    this->strMove = strMove+'-'+strMove;
    this->iDark = iDark;
    possibleKinds = possibleChar;
//    possibleChar = board.getDarkPieces();
//    for(std::map<char, int>::iterator it=possibleChar.begin(); it!=possibleChar.end(); it++)
//    {
//        Board possibleBoard(board);
//        possibleBoard.makeMove(strMove+'('+it->first+')');
//        this->possibleBoards[possibleBoard] = it->second;
//    }
}

Board::Move::~Move()
{
    //dtor
}

bool Board::Move::operator<(const Move& other) const
{
	if(iDark == other.iDark)
		if(possibleKinds == other.possibleKinds)
            return originB < other.originB;
        return possibleKinds < other.possibleKinds;
	return iDark < other.iDark;
}

Board Board::Move::GetOringinB()
{
    return originB;
}

std::string Board::Move::getStringMove()
{
    return strMove;
}

int Board::Move::GetiDark()
{
	return iDark;
}

std::map<char, int> Board::Move::GetpossibleKinds()
{
    return possibleKinds;
}

std::map<Board, int> Board::Move::GetpossibleBoards()
{
    std::map<Board, int> pos;
    Board board = originB;
    if(iDark)
    {
        for(std::map<char, int>::iterator it=possibleKinds.begin(); it!=possibleKinds.end(); it++)
        {
            Board possibleBoard(board);
            possibleBoard.makeMove(strMove+'('+it->first+')');
            pos[possibleBoard] = it->second;
        }
    }
    else
    {
        board.makeMove(strMove);
        pos[board] = 1;
    }
    return pos;
//	return possibleBoards;
}
