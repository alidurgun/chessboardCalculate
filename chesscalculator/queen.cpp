#include "queen.h"
#include "rook.h"
#include "bishop.h"

Queen::Queen(int x, int y)
{
	this->myColor = color::WHITE;
	this->myType = QUEEN;
	this->x = x;
	this->y = y;
	this->underThreat = false;
	this->point = 9.0;
}

// Queen's move is combined moves of rook and bishop
void Queen::move(Piece*** chessboardMap)
{
	// Bishop + Rook
	Bishop bishop = Bishop(this->x, this->y);
	bishop.setMyColor(this->myColor);
	Rook rook = Rook(this->x, this->y);
	rook.setMyColor(this->myColor);
	std::vector<xyTuple> xyTupleVector;
	std::vector<xyTuple> tempxyTupleVector;

	xyTupleVector = bishop.possibleMoves(chessboardMap);
	tempxyTupleVector = rook.possibleMoves(chessboardMap);

	// Concatenate 2 possible moves
	xyTupleVector.insert(xyTupleVector.end(), 
		tempxyTupleVector.begin(), 
		tempxyTupleVector.end());

	// Check there is any piece under threat by the Queen
	checkMove(xyTupleVector, chessboardMap);
}