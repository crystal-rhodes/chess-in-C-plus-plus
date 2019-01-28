#ifndef _ROOK_H_
#define _ROOK_H_
#include "Piece.h"
#include "Move.h"
class Rook : public Piece
{
public:
	// Constructors and Destructor
	Rook() : Piece() {};
	Rook(PieceColor  C, PieceType T, int x, int y) : Piece(C, T, x, y) {};
	~Rook() {};

	// Member Functions
	bool isValidMove(int FromX, int FromY, int ToX, int ToY);
};
#endif
