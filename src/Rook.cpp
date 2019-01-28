#include "Rook.h"

bool Rook::isValidMove(int FromX, int FromY, int ToX, int ToY)
{
	// First, Checking if rook moves vertically or horizontally 
	if ((ToX == FromX) || (ToY == FromY)) 
	{
		// Then, Specifically checking for rook moving to the right properly
		if (((ToX - FromX) > 0 && (ToY == FromY)))
		{
			for (int i = FromX + 1; i < ToX; i++)
			{
				if (ChessBoard::getSquare(i, ToY) != Empty)
				{
					cerr << "Rook cannot move overhead piece!" << endl;
					return false;
				}
			}
			return true;
		}

		// Checking for rook moving to the left properly
		else if (((ToX - FromX) < 0 && (ToY == FromY)))
		{
			for (int i = FromX - 1; i > ToX; i--)
			{
				if (ChessBoard::getSquare(i, ToY) != Empty)
				{
					cerr << "Rook cannot move overhead piece!" << endl;
					return false;
				}
			}
			return true;
		}

		// Checking for rook moving up properly
		else if (((ToX == FromX) && (ToY - FromY) > 0))
		{
			for (int i = FromY + 1; i < ToY; i++)
			{
				if (ChessBoard::getSquare(ToX, i) != Empty)
				{
					cerr << "Rook cannot move overhead piece!" << endl;
					return false;
				}
			}
			return true;
		}


		// Checking for rook moving down properly
		else if (((ToX == FromX) && (ToY - FromY) < 0))
		{
			for (int i = FromY - 1; i > ToY; i--)
			{
				if (ChessBoard::getSquare(ToX, i) != Empty)
				{
					cerr << "Rook cannot move overhead piece!" << endl;
					return false;
				}
			}
			return true;
		}

		else return false;
	}
	else // All other moves are illegal
	{
		cerr << "Rook's illegal move!";
		return false;
	}
}