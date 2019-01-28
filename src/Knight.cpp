#include "Knight.h"

bool Knight::isValidMove(int FromX, int FromY, int ToX, int ToY)
{
	if (abs(ToX - FromX ) == 2 && abs(ToY - FromY ) == 1) return true;
	if (abs(ToY - FromY ) == 2 && abs(ToX - FromX ) == 1) return true;
	else return false;
}
