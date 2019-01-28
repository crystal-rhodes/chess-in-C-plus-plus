#include "Bishop.h"

bool Bishop::isValidMove(int FromX, int FromY, int ToX, int ToY)
{
	// Checking for moving diagonally
	if (abs((ToX - FromX)) == abs((ToY - FromY)))
	{
		
		// Checking for bishop moving upleft
		if (ToX < FromX && ToY > FromY)
		{
			for (int i = FromY + 1; i < ToY; i++, FromX++)
			{
				if (ChessBoard::getSquare(--FromX, i) != Empty)
				{
					cerr << "Bishop's illegal moves!" << endl;
					return false;
				}
			}
			return true;
		}

		// Checking for bishop moving upright
		else if (ToX > FromX && ToY > FromY)
		{
			for (int i = FromY + 1; i < ToY; i++)
			{
				if (ChessBoard::getSquare(++FromX, i) != Empty) 
				{
					cerr << "Bishop's illegal moves!" << endl;
					return false;
				}
			}
			return true;
		}

		// Checking for bishop moving downright
		else if (ToX > FromX && ToY < FromY)
		{
			for (int i = FromX + 1; i < ToX; i++)
			{
				if (ChessBoard::getSquare(i, --FromY) != Empty) 
				{
					cerr << "Bishop's illegal moves!" << endl;
					return false;
				}
			}
			return true;
		}
		// Checking for bishop moving downleft
		else if (ToX < FromX && ToY < FromY)
		{
			for (int i = FromY - 1; i > ToY; i--)
			{
				if (ChessBoard::getSquare(--FromX,i) != Empty) 
				{
					cerr << "Bishop's illegal moves!" << endl;
					return false;
				}
			}
			return true;
		}

		else return false;
	}
	else
	{
		cerr << "Bishop's illegal moves!" << endl;
		return false;
	}
}
