#pragma once
#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED
#include "piece.h"
class Queen :public Piece
{
public:
	Queen(int x, int y);
	void move(Piece*** chessboardMap);
};
#endif // !QUEEN_H_INCLUDED