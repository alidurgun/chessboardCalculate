#include "king.h"

King::King(int x, int y)
{
	this->myColor = color::WHITE;
	this->myType = KING;
	this->x = x;
	this->y = y;
	this->underThreat = false;
	this->point = 100.0;
}

void King::move(Piece*** chessboardMap)
{

	// No need to implement because it will be ignored.


	/*int tempx = this->x;
	int tempy = this->y;
	std::vector<xyTuple> xyTupleVector;
	xyTuple tuple;
	for (int i = tempy - 1; i <= tempy + 1; i++)
	{
		for (int j = tempx - 1; j <= tempx + 1; j++)
		{
			if (i == tempy && j == tempx)
				continue;
			tuple.y = i;
			tuple.x = j;
			xyTupleVector.push_back(tuple);
		}
	}

	checkMove(xyTupleVector, chessboardMap);*/
}