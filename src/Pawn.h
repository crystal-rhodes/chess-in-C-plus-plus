#ifndef _PAWN_
#define _PAWN_
#include "Piece.h"
#include "Move.h"

class Pawn : public Piece
{
	bool Promoted;
public:
	// Constructors and Destructor
	Pawn() : Piece() { Promoted = false; };
	Pawn(PieceColor  C, PieceType T, int x, int y) : Piece(C, T, x, y) { Promoted = false; };
	~Pawn() {};

	// Member Functions
	bool isValidMove(int FromX, int FromY, int ToX, int ToY);
	
};
#endif
