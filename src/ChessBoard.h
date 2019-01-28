#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Move.h"
class ChessBoard
{
	friend class Move;
private:
	static vector<Piece*> whiteList;
	static vector<Piece*> blackList;
	static int SquaresList[SIZE][SIZE];
public:
	// Constructors and Destructor
	ChessBoard();
	~ChessBoard();

	// Getters and Setter
	static	vector<Piece*> wList() { return whiteList; }
	static	vector<Piece*> bList() { return blackList; }
	static int getSquare(int x, int y) { return SquaresList[y][x]; }
	static void setWhitePosition(int Index, int ToX, int ToY)
	{
		whiteList[Index]->setPosition(ToX, ToY);
		whiteList[Index]->setPosition(ToX, ToY);
	}
	static void setBlackPosition(int Index, int ToX, int ToY)
	{
		blackList[Index]->setPosition(ToX, ToY);
		blackList[Index]->setPosition(ToX, ToY);
	}
	// Member Functions
	char BoardDecoding(int);
	void Show();
	void WhiteInitialization();
	void BlackInitialization();


};
#endif
