#include "rook.h"

Rook::Rook(int x, int y)
{
	this->myColor = color::WHITE;
	this->myType = ROOK;
	this->x = x;
	this->y = y;
	this->underThreat = false;
	this->point = 5.0;
}

void Rook::move(Piece*** chessboardMap)
{
	// No need to implement because this move will be ignored!
}

// Add all possible moves for rook Queen will use it.
std::vector<xyTuple> Rook::possibleMoves(Piece*** chessboardMap)
{
	int tempx = this->x;
	int tempy = this->y;
	blockType direction_1 = blockType::NONE;// 4 different directions in total 2 for x line 2 for y line.
	blockType direction_2 = blockType::NONE;
	std::vector<xyTuple> xyTupleVector;
	xyTuple tuple;
	tuple.x = tempx;

	for (int i = 1; i <= 7; i++)
	{
		tuple.y = tempy - i;
		if (direction_1 != blockType::NONE)
		{
			direction_1 = checkBlock(tuple, chessboardMap);
			if (direction_1 != blockType::BLOCK)
				xyTupleVector.push_back(tuple);
		}

		tuple.y = tempy + i;
		if (direction_2 == blockType::NONE)
		{
			direction_2 = checkBlock(tuple, chessboardMap);
			if (direction_2 != blockType::BLOCK)
				xyTupleVector.push_back(tuple);
		}

		if (direction_1 == blockType::BLOCK && direction_2 == blockType::BLOCK)
			break;
	}

	tuple.y = tempy;
	direction_1 = blockType::NONE;
	direction_2 = blockType::NONE;
	for (int i = 1; i <= 7; i++)
	{
		tuple.x = tempx - i;
		if (direction_1 == blockType::NONE)
		{
			direction_1 = checkBlock(tuple, chessboardMap);
			if(direction_1 != blockType::BLOCK)
				xyTupleVector.push_back(tuple);
		}
		tuple.x = tempx + i;
		if (direction_2 == blockType::NONE)
		{
			direction_2 = checkBlock(tuple, chessboardMap);
			if (direction_2 != blockType::BLOCK)
				xyTupleVector.push_back(tuple);
		}

		if (direction_1 == blockType::BLOCK && direction_2 == blockType::BLOCK)
			break;
	}

	return xyTupleVector;
}