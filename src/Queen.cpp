#include "Queen.h"

bool Queen::isValidMove(int FromX, int FromY, int ToX, int ToY)
{
	// Checking for moving vertically or horizontally 
	if ((ToX == FromX) || (ToY == FromY))
	{
		// Then, Specifically checking for queen moving to the right properly
		if (((ToX - FromX) > 0 && (ToY == FromY)))
		{
			for (int i = FromX + 1; i < ToX; i++)
			{
				if (ChessBoard::getSquare(i, ToY) != Empty)
				{
					cerr << "queen cannot move overhead piece!" << endl;
					return false;
				}
			}
			return true;
		}

		// Checking for queen moving to the left properly
		else if (((ToX - FromX) < 0 && (ToY == FromY)))
		{
			for (int i = FromX - 1; i > ToX; i--)
			{
				if (ChessBoard::getSquare(i, ToY) != Empty)
				{
					cerr << "queen cannot move overhead piece!" << endl;
					return false;
				}
			}
			return true;
		}

		// Checking for queen moving up properly
		else if (((ToX == FromX) && (ToY - FromY) > 0))
		{
			for (int i = FromY + 1; i < ToY; i++)
			{
				if (ChessBoard::getSquare(ToX, i) != Empty)
				{
					cerr << "queen cannot move overhead piece!" << endl;
					return false;
				}
			}
			return true;
		}


		// Checking for queen moving down properly
		else if (((ToX == FromX) && (ToY - FromY) < 0))
		{
			for (int i = FromY - 1; i > ToY; i--)
			{
				if (ChessBoard::getSquare(ToX, i) != Empty)
				{
					cerr << "queen cannot move overhead piece!" << endl;
					return false;
				}
			}
			return true;
		}

		else return false;
	}

	// Checking for moving diagonally 
	else if (abs(ToX - FromX) == abs(ToY - FromY))
	{

		// Checking for queen moving upleft
		if (ToX < FromX && ToY > FromY)
		{
			for (int i = FromY + 1; i < ToY; i++)
			{
				if (ChessBoard::getSquare(--FromX, i) != Empty)
				{
					cerr << "queen's illegal moves!" << endl;
					return false;
				}
			}
			return true;
		}

		// Checking for queen moving upright
		else if (ToX > FromX && ToY > FromY)
		{
			for (int i = FromY + 1; i < ToY; i++)
			{
				if (ChessBoard::getSquare(++FromX, i) != Empty)
				{
					cerr << "queen's illegal moves!" << endl;
					return false;
				}
			}
			return true;
		}

		// Checking for queen moving downright
		else if (ToX > FromX && ToY < FromY)
		{
			for (int i = FromX + 1; i < ToX; i++)
			{
				if (ChessBoard::getSquare(i, --FromY) != Empty)
				{
					cerr << "queen's illegal moves!" << endl;
					return false;
				}
			}
			return true;
		}
		// Checking for queen moving downleft
		else if (ToX < FromX && ToY < FromY)
		{
			for (int i = FromY - 1; i > ToY; i--)
			{
				if (ChessBoard::getSquare(--FromX, i) != Empty)
				{
					cerr << "queen's illegal moves!" << endl;
					return false;
				}
			}
			return true;
		}

		else return false;
	}

	else // All other moves are illegal
	{
		cout << "Queen's illegal move!" << endl;
		return false;
	}
};