#pragma once
#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED
#include "piece.h"
class Rook :public Piece
{
public:
	Rook(int x, int y);
	void move(Piece*** chessboardMap);
	std::vector<xyTuple> possibleMoves(Piece*** chessboardMap);
};
#endif // !ROOK_H_INCLUDED