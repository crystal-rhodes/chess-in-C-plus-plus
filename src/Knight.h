#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include "Piece.h"
#include "Move.h"
class Knight : public Piece
{
public:
	// Constructors and Destructor
	Knight() : Piece() {};
	Knight(PieceColor  C, PieceType T, int x, int y) : Piece(C, T, x, y) {};
	~Knight() {};
	
	// Member Functions
	bool isValidMove(int FromX, int FromY, int ToX, int ToY);

};
#endif
