#pragma once
#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED
#include <vector>
#include <set>
#include "types.h"
// Base class for other kinds of pieces in the chessboard
class Piece {
protected:
	enum type {
		PAWN,
		KNIGHT,
		BISHOP,
		ROOK,
		QUEEN,
		KING
	};
	type myType;
	double point;
	virtual void move(Piece*** chessboardMap);
	void checkMove(std::vector<xyTuple> tupleVector, Piece*** chessboardMap);
	blockType checkBlock(xyTuple tuple, Piece*** chessboardMap);
	bool underThreat;
	color myColor; // 0 => WHITE, 1 => BLACK
	int x; // Represents x coordinates in the chessboard
	int y; // Represents y coordinates in the chessboard
public:
	color getMyColor();
	bool isUnderThreat();
	void setUnderThreat();
	void setMyColor(int);
	void checkThreats(Piece*** chessboardMap);
	double getPoint();
};

#endif // !PIECE_H_INCLUDED