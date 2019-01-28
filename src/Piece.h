#ifndef _PIECE_H_
#define _PIECE_H_
#include "Position.h"
#include "ENUM.h"
using namespace std;
const int SIZE = 8;
const int VECTOR_SIZE = 16;
class Piece 
{
protected:
	PieceColor COLOR;
	PieceType TYPE;
	Position POSITION;
public:
	// Constructors and Destructor
	Piece() {}
	Piece(PieceColor C, PieceType T, int x, int y) 
	{ COLOR = C; TYPE = T; POSITION.setX(x); POSITION.setY(y); }
	virtual ~Piece() = 0 {};

	// Getter and setter
	Position getPosition() { return POSITION; }
	void setPosition(int x, int y) 
	{ 
		POSITION.setX(x); POSITION.setY(y); 
	}
	

	// Member Functions
	virtual bool isValidMove(int FromX, int FromY, int ToX, int ToY) = 0 {return true;}
};

#endif