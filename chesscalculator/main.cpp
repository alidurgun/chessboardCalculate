#include <iostream>
#include "chessboard.h"
using namespace std;

int main(int argc, char* argv)
{
    Chessboard *instance = Chessboard::getInstance();
	std::string filePrefix = "board";
	std::string fileExtension = ".txt";
	std::cout << "Tahta Dosya Adi Sonuclar" << std::endl;
	int i = 1;
	do
	{
		std::string fileName = filePrefix + std::to_string(i) + fileExtension;
		instance->changeFile(fileName); // Read new files
		std::map<color, double> points = instance->calculatePoints(); // calculate points with threats
		std::map<color, double>::iterator iter;
		std::cout << fileName << " ";
		for (iter = points.begin(); iter != points.end(); iter++)
		{
			if (iter->first == color::WHITE)
			{
				std::cout << "Beyaz:" << iter->second << " ";
			}
			else
			{
				std::cout << "Siyah:" << iter->second << std::endl;
			}
		}
		instance->freeMemory(); // prevent memory leak
		i++;
	} while (i < 4);
	delete instance;
	return 0;
}