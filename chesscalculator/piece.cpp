#include "piece.h"
#include <iostream>
color Piece::getMyColor()
{
	return this->myColor;
}

bool Piece::isUnderThreat()
{
	return this->underThreat;
}

void Piece::setUnderThreat()
{
	this->underThreat = true;
}

void Piece::setMyColor(int myColor)
{
	this->myColor = static_cast<color>(myColor);
}

void Piece::checkMove(std::vector<xyTuple> tupleVector, Piece*** chessboardMap)
{
	std::vector<xyTuple>::iterator iter;
	color oppositeColor = color::WHITE;
	if (this->myColor == color::WHITE)
	{
		oppositeColor = color::BLACK;
	}
	for (iter = tupleVector.begin(); iter != tupleVector.end(); iter++)
	{
		// IGNORE MOVES FOR INVALID LINES
		if (iter->x < 0 || iter->x > 7 || iter->y < 0 || iter->y > 7)
		{
			continue;
		}

		Piece* currentTas = chessboardMap[iter->x][iter->y];
		if (currentTas != NULL)
		{
			if (currentTas->getMyColor() == oppositeColor)
			{
				currentTas->setUnderThreat(); // If this piece has different color then set it under threat.
			}
		}
	}
}

// 0 => NO BLOCK, 
// 1=> BLOCKED BY SAME COLOR OF PIECE OR INVALID MOVE
// 2=> BLOCKED BY DIFFERENT COLOR OF PIECE
blockType Piece::checkBlock(xyTuple myTuple, Piece*** chessboardMap)
{
	// IGNORE MOVES FOR INVALID LINES
	if (myTuple.x < 0 || myTuple.x > 7 || myTuple.y < 0 || myTuple.y > 7)
	{
		return blockType::BLOCK;
	}

	Piece* current = chessboardMap[myTuple.x][myTuple.y];
	if (current != NULL)
	{
		// Both situation will block the piece but if there is opposite color then it means this piece
		// can move to this position by defeating that piece.
		if(current->getMyColor() == this->getMyColor())
			return blockType::BLOCK; // Move won't be added
		else
		{
			return blockType::BLOCK_WITH_THREAT; // Move will be added.
		}
	}
	// Empty position
	return blockType::NONE; // Move will be added
}

void Piece::checkThreats(Piece*** chessboardMap)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Piece* current = chessboardMap[i][j];
			if (current != NULL)
			{
				current->move(chessboardMap); // Threats will be calculated in move functions Chessboardmap will affected.
			}
		}
	}
}

void Piece::move(Piece*** chessboardMap)
{
	// Every Object has own move function.
}

double Piece::getPoint()
{
	if (this->isUnderThreat())
		return this->point / 2;
	return this->point;
}