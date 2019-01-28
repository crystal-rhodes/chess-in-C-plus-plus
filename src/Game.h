#ifndef _GAME_H_
#define _GAME_H_
#include "Piece.h"
#include "Move.h"
#include "ENUM.h"
class Game
{
	friend class Move;
private:
	static vector<Move> movesPlayed;
	static GameStatus status;
	static GameResult result;
	static PieceColor turn;
public:
	// Constructors and Destructor
	Game() {};
	~Game() {};

	// Getter and Setter
	inline GameStatus Status() { return status; }
	inline GameResult Result() { return result; }
	inline PieceColor Turn() { return turn; }

	// Input and Output stream
	/*friend istream & operator >> (istream &, Game &);
	friend ostream & operator << (ostream &, const Game &);
*/

	void AddMove();
	//void Create();
};

#endif