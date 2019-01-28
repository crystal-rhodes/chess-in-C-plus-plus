#ifndef _QUEEN_H_
#define _QUEEN_H_
#include "Piece.h"
#include "Move.h"
class Queen : public Piece
{
public:
	// Constructors and Destructor
	Queen() : Piece() {};
	Queen(PieceColor  C, PieceType T, int x, int y) : Piece(C, T, x, y) {};
	~Queen() {};

	// Member Functions
	bool isValidMove(int FromX, int FromY, int ToX, int ToY);
	
};
#endif
