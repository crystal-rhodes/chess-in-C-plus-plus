#ifndef _BISHOP_H_
#define _BISHOP_H_
#include "Piece.h"
#include "Move.h"

class Bishop : public Piece
{
public:
	// Constructors and Destructor
	Bishop() : Piece() {};
	Bishop(PieceColor  C, PieceType T, int x, int y) : Piece(C, T, x, y) {};
	~Bishop() {};

	// Member Functions
	bool isValidMove(int FromX, int FromY, int ToX, int ToY);
	
};
#endif
