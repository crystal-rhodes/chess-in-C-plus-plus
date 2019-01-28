#ifndef _MOVE_H_
#define _MOVE_H_
// In this file MOVE.h and MOVE.cpp, we have to define chess rules 
#include "Position.h"
#include "Piece.h"
#include "ChessBoard.h"
#include "Game.h"
class Move
{
	Position FromPos;
	Position ToPos;
public:
	Move() {};
	~Move() {};

	// Getter and Setter
	inline Position getFromPos() { return FromPos; }
	inline Position getToPos() { return ToPos; }

	// Input and Output
	friend istream & operator >> (istream &, Move &);
	friend ostream & operator << (ostream &, const Move &);

	// Member Functions
	void MovePiece();
};
#endif