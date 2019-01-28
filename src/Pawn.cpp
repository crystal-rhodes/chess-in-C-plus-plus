#include "Pawn.h"

bool Pawn::isValidMove(int FromX, int FromY, int ToX, int ToY)
{
	// Pawn normally moves
	if ((Promoted == false) && (ToX == FromX) && (ChessBoard::getSquare(ToX, ToY) == Empty))
	{
		if (COLOR == White && (ToY-FromY > 0)) // Checking color and preventing pawn from moving backward
		{
			// Checking for first move
			if (FromY == 1)
			{
				if (ToY - FromY <= 2) return true;
				else
				{
					cerr << "Pawn's illegal move" << endl;
					return false;
				}
			}
			// Checking for second move, third move, so on...
			else if (FromY != 1)
			{
				if (ToY - FromY == 1) return true;
				else 
				{
					cerr << "Pawn's illegal move" << endl;
					return false;
				}
			}
			else return false;
		}
		else if (COLOR == Black && (ToY - FromY < 0)) // Checking color and preventing pawn from moving backward
		{
			// Checking for first move
			if (FromY == 6)
			{
				if (FromY - ToY <= 2) return true;
				else 
				{
					cerr << "Pawn's illegal move" << endl;
					return false;
				}
			}
			// Checking for second move, third move, so on...
			else if (FromY != 6)
			{
				if (FromY - ToY == 1) return true;
				else 
				{
					cerr << "Pawn's illegal move" << endl;
					return false;
				}
			}
			else return false;
		}
		else return false;
	}

	// Pawn captures an opponent piece
	else if ((Promoted == false) && abs(ToY - FromY) == 1 && abs(ToX - FromX) == 1 && (ChessBoard::getSquare(ToX, ToY) != Empty))
	{
		// White's pawn capturing 
		if ((COLOR == White) && (ToY - FromY) == 1) return true; // Preventing capturing backward
		else if ((COLOR == Black) && (FromX - ToX) == 1) return true;
		else
		{
			cerr << "Pawn's illegal move!" << endl;
		}
	}

	else // All other moves are illegal
	{
		cerr << "Pawn's illegal move" << endl;
		return false;
	}
}

