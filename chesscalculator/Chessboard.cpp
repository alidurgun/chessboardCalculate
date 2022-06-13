#include "chessboard.h"

Chessboard* Chessboard::instance = 0;

Chessboard* Chessboard::getInstance()
{
	if (instance == 0)
	{
		instance = new Chessboard();
	}
	return instance;
}

// Initialize the board will only call once.
Chessboard::Chessboard()
{
	chessboardMap = new Piece * *[8];
	for (int i = 0; i < 8; i++)
	{
		chessboardMap[i] = new Piece * [8];
	}
}

// This function will read line by spaces and map the chessboard with given values
void Chessboard::mapTheBoard(std::string line, int i)
{
	size_t pos;
	line = line + " "; // For last input.
	int j = 0;
	while ((pos = line.find(' ')) != std::string::npos)
	{
		std::string value = line.substr(0, pos);
		line = line.substr(pos + 1);
		char type = value[0];
		int colorInt = 0; // MEANS WHITE
		if (value[1] == 's')
		{
			colorInt = 1; // MEANS BLACK
		}
		switch (type)
		{
		case 'k':
		{
			// Rook
			Rook *rook = new Rook(i, j);
			rook->setMyColor(colorInt);
			chessboardMap[i][j] = rook;
			break;
		}
		case 'a':
		{
			// Knight
			Knight *knight = new Knight(i, j);
			knight->setMyColor(colorInt);
			chessboardMap[i][j] = knight;
			break;
		}
		case 'f':
		{
			// Bishop
			Bishop *bishop = new Bishop(i, j);
			bishop->setMyColor(colorInt);
			chessboardMap[i][j] = bishop;
			break;
		}
		case 'p':
		{
			// Pawn
			Pawn *pawn = new Pawn(i, j);
			pawn->setMyColor(colorInt);
			chessboardMap[i][j] = pawn;
			break;
		}
		case 's':
		{
			// King
			King *king = new King(i, j);
			king->setMyColor(colorInt);
			chessboardMap[i][j] = king;
			break;
		}
		case 'v':
		{
			// Queen
			Queen *queen = new Queen(i, j);
			queen->setMyColor(colorInt);
			chessboardMap[i][j] = queen;
			break;
		}
		default:
		{
			chessboardMap[i][j] = NULL;
			break;
		}
		}
		j++;
	}
}

// 3 files will be read during execution time
void Chessboard::changeFile(std::string fileName)
{
	fstream infile;
	std::string wholeLine;
	infile.open(fileName, ios::in);
	int i = 0;

	if (infile.is_open())
	{
		while (getline(infile, wholeLine))
		{
			mapTheBoard(wholeLine, i);
			i++;
		}
		infile.close();
	}
}

// This function will calculate the points for each color and returns to the user.
std::map<color,double> Chessboard::calculatePoints()
{
	Piece* piece = new Piece();
	std::map<color, double> retVal;
	double sumWhite = 0;
	double sumBlack = 0;
	piece->checkThreats(chessboardMap);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			double point = 0;
			piece = chessboardMap[i][j];
			if (piece == NULL) // Empty space in board
				continue;
			else
			{
				point = piece->getPoint();
				if (piece->getMyColor() == color::WHITE)
				{
					sumWhite += point;
				}
				else
				{
					sumBlack += point;
				}
			}
		}
	}
	retVal.insert({ color::WHITE, sumWhite });
	retVal.insert({ color::BLACK, sumBlack });

	return retVal;
}

// Managing memory after each board calculated
void Chessboard::freeMemory()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			chessboardMap[i][j] = NULL;
			delete chessboardMap[i][j];
		}
	}
}

// Deconstructor
Chessboard::~Chessboard()
{
	for (int i = 0; i < 8; i++)
	{
		delete chessboardMap[i];
	}
	delete chessboardMap;
}