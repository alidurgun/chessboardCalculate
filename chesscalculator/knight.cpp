#include "knight.h"

Knight::Knight(int x, int y)
{
	this->myColor = color::WHITE;
	this->myType = KNIGHT;
	this->x = x;
	this->y = y;
	this->underThreat = false;
	this->point = 3.0;
}

void Knight::move(Piece*** chessboardMap)
{
	int tempx = this->x;
	int tempy = this->y;
	std::vector<xyTuple> xyTupleVector;
	xyTuple tuple;

	// Add all possible moves for the knight
	tuple.x = tempx + 1;
	tuple.y = tempy + 2;
	xyTupleVector.push_back(tuple);
	tuple.y = tempy - 2;
	xyTupleVector.push_back(tuple);
	tuple.x = tempx + 2;
	tuple.y = tempy + 1;
	xyTupleVector.push_back(tuple);
	tuple.y = tempy - 1;
	xyTupleVector.push_back(tuple);
	tuple.x = tempx - 1;
	tuple.y = tempy + 2;
	xyTupleVector.push_back(tuple);
	tuple.y = tempy - 2;
	xyTupleVector.push_back(tuple);
	tuple.x = tempx - 2;
	tuple.y = tempy + 1;
	xyTupleVector.push_back(tuple);
	tuple.y = tempy - 1;
	xyTupleVector.push_back(tuple);

	// Check there is any piece under threat by the Knight
	checkMove(xyTupleVector, chessboardMap);
}