#ifndef _KING_H_
#define _KING_H_
#include "Piece.h"
#include "Move.h"

class King : public Piece
{
public:
	// Constructors and Destructor
	King() : Piece() {};
	King(PieceColor  C, PieceType T, int x, int y) : Piece(C, T, x, y) {};
	~King() {};

	// Member Functions
	bool isValidMove(int FromX, int FromY, int ToX, int ToY);
	bool isChecked(int X_King, int Y_King);
};
#endif
