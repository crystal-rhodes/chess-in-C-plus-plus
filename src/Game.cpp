#include "Game.h"

GameStatus Game::status = None;
GameResult Game::result = none;
PieceColor Game::turn = White;
vector<Move> Game::movesPlayed = {};

void Game::AddMove()
{
	ChessBoard *b = new ChessBoard;
	b->BlackInitialization();
	b->WhiteInitialization();
	do
	{
		
		b->Show();
		Move a;
		bool MoveSuccessful = true;

		if (this->turn == White)
		{
			cout << "White to move: ";
			//cin >> a;
			a.MovePiece();
			this->movesPlayed.push_back(a);
			turn = Black;
		}
		else
		{
			cout << "Black to move: ";
			//cin >> a;
			a.MovePiece();
			this->movesPlayed.push_back(a);
			turn = White;
		} 
	} while (result != None);
}