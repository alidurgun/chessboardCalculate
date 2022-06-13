#pragma once
#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED
#include "piece.h"
class Knight :public Piece
{
public:
	Knight(int x, int y);
	void move(Piece*** chessboardMap);
};

#endif // !KNIGHT_H_INCLUDED