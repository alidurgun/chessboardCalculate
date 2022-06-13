#pragma once
#ifndef CHESSBOARD_H_INCLUDED
#define CHESSBOARD_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
using namespace std;
class Chessboard
{
private:
	static Chessboard* instance; // Singleton usage
	Piece*** chessboardMap; // Every piece and empty spaces will be located in this object.
	Chessboard();
public:
	static Chessboard* getInstance(); // Singleton
	void mapTheBoard(std::string, int); // Locate pieces in the board.
	std::map<color, double> calculatePoints();
	void changeFile(std::string); // Next file
	void freeMemory(); // manage memory
	~Chessboard();
};

#endif // !CHESSBOARD_H_INCLUDED
