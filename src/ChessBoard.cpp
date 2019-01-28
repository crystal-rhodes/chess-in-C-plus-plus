#include "ChessBoard.h"

vector<Piece*> ChessBoard::blackList = {};
vector<Piece*> ChessBoard::whiteList = {};
int ChessBoard::SquaresList[8][8] = {};

char ChessBoard::BoardDecoding(int x)
{
	switch (x)
	{
	case (White + rook):	return 'R'; break;
	case (White + knight):	return 'N'; break;
	case (White + bishop):	return 'B'; break;
	case (White + queen):	return 'Q'; break;
	case (White + king):	return 'K'; break;
	case (White + pawn):	return 'P'; break;

	case (Black + rook):	return 'r'; break;
	case (Black + knight):	return 'n'; break;
	case (Black + bishop):	return 'b'; break;
	case (Black + queen):	return 'q'; break;
	case (Black + king):	return 'k'; break;
	case (Black + pawn):	return 'p'; break;
	default: return '.'; break;
	}
}
void ChessBoard::Show()
{
	cout << "    a " << " b " << " c " << " d " << " e " << " f " << " g " << " h " << endl;
	cout << "    _ " << " _ " << " _ " << " _ " << " _ " << " _ " << " _ " << " _ " << endl;
	cout << endl;
	for (int i = SIZE-1; i >= 0; i--)
	{
		cout << i + 1 << "|  ";
		for (int j = 0; j < SIZE; j++)
		{
			cout  << BoardDecoding(SquaresList[i][j]) << "  ";
		}
		cout << endl;
		cout << endl;
	}
}
void ChessBoard::WhiteInitialization()
{

	whiteList.resize(VECTOR_SIZE);


	whiteList[0] = new King(White, king, 4, 0);
	whiteList[1] = new Queen(White, queen, 3, 0);
	whiteList[2] = new Rook(White, rook, 0, 0);
	whiteList[3] = new Rook(White, rook, 7, 0);
	whiteList[4] = new Bishop(White, bishop, 2, 0);
	whiteList[5] = new Bishop(White, bishop, 5, 0);
	whiteList[6] = new Knight(White, knight, 1, 0);
	whiteList[7] = new Knight(White, knight, 6, 0);

	for (size_t i = 8; i < VECTOR_SIZE; i++)
	{
		whiteList[i] = new Pawn(White, pawn, i - 8, 1);
	}


}
void ChessBoard::BlackInitialization()
{
	blackList.resize(VECTOR_SIZE);


	blackList[0] = new King(Black, king, 4, 7);
	blackList[1] = new Queen(Black, queen, 3, 7);
	blackList[2] = new Rook(Black, rook, 0, 7);
	blackList[3] = new Rook(Black, rook, 7, 7);
	blackList[4] = new Bishop(Black, bishop, 2, 7);
	blackList[5] = new Bishop(Black, bishop, 5, 7);
	blackList[6] = new Knight(Black, knight, 1, 7);
	blackList[7] = new Knight(Black, knight, 6, 7);

	for (size_t i = 8; i < VECTOR_SIZE; i++)
	{
		blackList[i] = new Pawn(Black, pawn, i - 8, 6);
	}

}


ChessBoard::ChessBoard()
{
	SquaresList[0][0] = White + rook;
	SquaresList[0][1] = White + knight;
	SquaresList[0][2] = White + bishop;
	SquaresList[0][3] = White + queen;
	SquaresList[0][4] = White + king;
	SquaresList[0][5] = White + bishop;
	SquaresList[0][6] = White + knight;
	SquaresList[0][7] = White + rook;

	for (size_t i = 0; i < 8; i++)
	{
		SquaresList[1][i] = White + pawn;
	}

	SquaresList[7][0] = Black + rook;
	SquaresList[7][1] = Black + knight;
	SquaresList[7][2] = Black + bishop;
	SquaresList[7][3] = Black + queen;
	SquaresList[7][4] = Black + king;
	SquaresList[7][5] = Black + bishop;
	SquaresList[7][6] = Black + knight;
	SquaresList[7][7] = Black + rook;

	for (size_t i = 0; i < 8; i++)
	{
		SquaresList[6][i] = Black + pawn;
	}

	for (size_t i = 2; i < 6; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			SquaresList[i][j] = Empty;
		}
	}
}


ChessBoard::~ChessBoard()
{
}


