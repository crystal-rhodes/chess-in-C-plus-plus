#include "Piece.h"
#include "ChessBoard.h"
#include <iostream>
int main()
{
	
	Game *b = new Game;
	
	b->AddMove();
	delete b;
	return 0;
}