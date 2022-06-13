#pragma once
#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED
#include "piece.h"
class Pawn :public Piece
{
public:
	Pawn(int x, int y);
	void move(Piece*** chessboardMap);
};

#endif // !PAWN_H_INCLUDED