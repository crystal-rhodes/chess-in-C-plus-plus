#include "Move.h"

int Decode(char a);

istream & operator >> (istream &is, Move &x)
{
	static string move;
	

	getline(is, move, '\n');

	x.FromPos.setX(Decode(move[0]) - 1);
	x.FromPos.setY((move[1] - '0') - 1);

	x.ToPos.setX(Decode(move[2]) - 1);
	x.ToPos.setY((move[3] - '0') - 1);


	//cout << "Enter a position to move: ";
	//is >> x.FromPos;

	//cout << "Enter a destination position: ";
	//is >> x.ToPos;
	return is;
}
ostream & operator << (ostream &os, const Move &x)
{
	os << x.FromPos << " " << x.ToPos;
	return os;
}
void Move::MovePiece()
{
	int Fx;
	int Tx;
	int Fy;
	int Ty;

TryAgain:
	try
	{
		string move;


		getline(cin, move, '\n');

		FromPos.setX(Decode(move[0]) - 1);
		FromPos.setY((move[1] - '0') - 1);

		ToPos.setX(Decode(move[2]) - 1);
		ToPos.setY((move[3] - '0') - 1);
		/*if (Game::turn == White)
		{
			cout << "White to move: ";
			cin >> FromPos;
			cout << "Destination: ";
			cin >> ToPos;
		}
		else
		{
			cout << "Black to move: ";
			cin >> FromPos;
			cout << "Destination: ";
			cin >> ToPos;
		}*/
		Fx = FromPos.x();
		Tx = ToPos.x();
		Fy = FromPos.y();
		Ty = ToPos.y();

		// Store the position of White King and Black King
		int x_WhiteKing = ChessBoard::whiteList[0]->getPosition().x();
		int y_WhiteKing = ChessBoard::whiteList[0]->getPosition().y();
		int x_BlackKing = ChessBoard::blackList[0]->getPosition().x();
		int y_BlackKing = ChessBoard::blackList[0]->getPosition().y();
		// Checking if The King is checked



		// Checking for moving empty space
		if (ChessBoard::SquaresList[Fy][Fx] == Empty)
			throw 10;

		// Checking for non-moving piece (Moving to the same place)
		if (ToPos == FromPos)
			throw 'a';

		// Checking for capturing friendly piece
		if (ChessBoard::SquaresList[Fy][Fx] <= (Black + king) && ChessBoard::SquaresList[Ty][Tx] <= (Black + king) && ChessBoard::SquaresList[Ty][Tx] > Empty)
			throw 5.5;
		if (ChessBoard::SquaresList[Fy][Fx] >= (White + pawn) && ChessBoard::SquaresList[Ty][Tx] >= (White + pawn) && ChessBoard::SquaresList[Ty][Tx] > Empty)
			throw 6.5;

		// Checking for moving an opponent's piece
		if (Game::turn == White && ChessBoard::SquaresList[Fy][Fx] <= (Black + king))
			throw 4.3f;
		if (Game::turn == Black && ChessBoard::SquaresList[Fy][Fx] >= (White + pawn))
			throw 4.3f;

		// Checking for how a specific piece moves (How queen/rook/king/pawn/bishop/knight moves)

		// Checking for white pieces
		if (ChessBoard::SquaresList[Fy][Fx] >= (White + pawn))
		{
			for (size_t i = 0; i < VECTOR_SIZE; i++)
			{
				if (ChessBoard::whiteList[i]->getPosition() == FromPos)
				{
					// if move successfully, vector containing all pieces must be updated
					if (ChessBoard::whiteList[i]->isValidMove(Fx, Fy, Tx, Ty))
					{
						ChessBoard::setWhitePosition(i, Tx, Ty);
						ChessBoard::SquaresList[Ty][Tx] = ChessBoard::SquaresList[Fy][Fx];
						ChessBoard::SquaresList[Fy][Fx] = Empty;
						break;
					}
					else 
					{
						throw "Invalid Move";
					}
				}
			}
		}
		// Checking for black pieces
		else if (ChessBoard::SquaresList[Fy][Fx] <= (Black + king))
		{
			for (size_t i = 0; i < VECTOR_SIZE; i++)
			{
				if (ChessBoard::blackList[i]->getPosition() == FromPos)
				{
					// if move successfully, vector containing all pieces must be updated
					if (ChessBoard::blackList[i]->isValidMove(Fx, Fy, Tx, Ty))
					{
						ChessBoard::setBlackPosition(i, Tx, Ty);
						ChessBoard::SquaresList[Ty][Tx] = ChessBoard::SquaresList[Fy][Fx];
						ChessBoard::SquaresList[Fy][Fx] = Empty;
						break;
					}
					else 
					{ 
						throw "Invalid Move"; 
					}
				}
			}
		}
		else throw "Invalid!";

	}
	catch (const int &)
	{
		cerr << "Cannot move an empty space!" << endl;
		goto TryAgain;
	}
	catch (const double &)
	{
		cerr << "Cannot capture the same color piece" << endl;
		goto TryAgain;
	}
	catch (const char &)
	{
		cerr << "Cannot move to the same place" << endl;
		goto TryAgain;
	}
	catch (const float &)
	{
		cerr << "Cannot move an opponent's piece" << endl;
		goto TryAgain;
	}
	catch (const exception&e)
	{
		cerr << e.what() << endl;
		goto TryAgain;
	}
	catch (...)
	{
		cerr << "Invalid Move!" << endl;
		goto TryAgain;
	}

	// If move is played successfully 
	

}


