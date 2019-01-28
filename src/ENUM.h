#ifndef _ENUM_H_
#define _ENUM_H_
enum GameStatus { WhiteCheckmated, BlackCheckmated, WhiteInCheck, BlackInCheck, None } ;

enum GameResult { BlackWin, WhiteWin, Draw, none } ;

enum PieceType { pawn = 1, bishop, knight, rook, queen, king, Empty} ;

enum PieceColor { Black = 0, White = 8 } ;
#endif