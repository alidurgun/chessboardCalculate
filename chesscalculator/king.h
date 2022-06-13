#pragma once
#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED
#include "piece.h"
class King :public Piece
{
public:
	King(int x, int y);
	void move(Piece*** chessboardMap);
};
#endif // !KING_H_INCLUDED
