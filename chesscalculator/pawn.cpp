#include "pawn.h"

Pawn::Pawn(int x, int y)
{
	this->myColor = color::WHITE;
	this->myType = PAWN;
	this->x = x;
	this->y = y;
	this->underThreat = false;
	this->point = 1.0;
}

void Pawn::move(Piece*** chessboardMap)
{
	int tempx = this->x;
	int tempy = this->y;
	std::vector<xyTuple> xyTupleVector;
	xyTuple tuple;
	switch (myColor)
	{
	case WHITE:
		tuple.y = tempy + 1; 
		tuple.x = tempx - 1;
		xyTupleVector.push_back(tuple); // Add possible move for white pawn
		tuple.y = tempy - 1;
		xyTupleVector.push_back(tuple);
		break;
	case BLACK:
		tuple.y = tempy + 1;
		tuple.x = tempx + 1;
		xyTupleVector.push_back(tuple); // Add possible move for black pawn
		tuple.y = tempy - 1;
		xyTupleVector.push_back(tuple);
		break;
	default: // No need for default but just you know the rule.
		break;
	}
	// Check there is any piece under threat by the Pawn
	checkMove(xyTupleVector, chessboardMap); 
}