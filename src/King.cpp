#include "King.h"

bool King::isValidMove(int FromX, int FromY, int ToX, int ToY)
{
	// Checking for how King moves
	if (abs(ToX - FromX) > 1 || abs(ToY - FromY) > 1) return false;

	else return true;
}
bool King::isChecked(int X_King, int Y_King)
{
	// Checking for if the king is checked vertically and horizontally
	for (int i = X_King; i < SIZE; i++)
	{
		ChessBoard::getSquare(i, Y_King);
		
	}

	// Checking for if the king is checked diagonally

	
	return true;
}