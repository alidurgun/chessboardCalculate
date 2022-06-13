#pragma once
#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED
#include "piece.h"
class Bishop :public Piece
{
public:
	Bishop(int x, int y);
	void move(Piece*** chessboardMap);
	std::vector<xyTuple> possibleMoves(Piece*** chessboardMap);
};
#endif // !BISHOP_H_INCLUDED