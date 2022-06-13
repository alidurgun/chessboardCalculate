#include "bishop.h"

Bishop::Bishop(int x, int y)
{
	this->myColor = color::WHITE;
	this->myType = BISHOP;
	this->x = x;
	this->y = y;
	this->underThreat = false;
	this->point = 3.0;
}

void Bishop::move(Piece*** chessboardMap)
{
	// No need to implement because this move will be ignored!
}

// Add all possible Moves for bishop Queen will use it
std::vector<xyTuple> Bishop::possibleMoves(Piece*** chessboardMap)
{
	int tempx = this->x;
	int tempy = this->y;
	blockType direction_1 = blockType::NONE; // 4 different directions in total 2 for upper 2 for lower side.
	blockType direction_2 = blockType::NONE;
	int counter = 1;
	std::vector<xyTuple> xyTupleVector;
	xyTuple tuple;

	for (int i = tempy - 1; i >= 0; i--)
	{
		tuple.y = i;
		tuple.x = tempx - counter;
		if (direction_1 == blockType::NONE)
		{
			direction_1 = checkBlock(tuple, chessboardMap);
			if(direction_1 != blockType::BLOCK)
				xyTupleVector.push_back(tuple);
		}
		tuple.x = tempx + counter;
		if (direction_2 == blockType::NONE)
		{
			direction_2 = checkBlock(tuple, chessboardMap);
			if (direction_2 != blockType::BLOCK)
				xyTupleVector.push_back(tuple);
		}
		if (direction_1 == blockType::BLOCK && direction_2 == blockType::BLOCK)
			break;
		counter++;
	}
	counter = 1;
	direction_1 = blockType::NONE;
	direction_2 = blockType::NONE;
	for (int i = tempy + 1; i <= 7; i++)
	{
		tuple.y = i;
		tuple.x = tempx - counter;
		if (direction_1 == blockType::NONE)
		{
			direction_1 = checkBlock(tuple, chessboardMap);
			if (direction_1 != blockType::BLOCK)
				xyTupleVector.push_back(tuple);
		}
		tuple.x = tempx + counter;
		if (direction_2 == blockType::NONE)
		{
			direction_2 = checkBlock(tuple, chessboardMap);
			if (direction_2 != blockType::BLOCK)
				xyTupleVector.push_back(tuple);
		}
		if (direction_1 == blockType::BLOCK && direction_2 == blockType::BLOCK)
			break;
		counter++;
	}

	return xyTupleVector;
}