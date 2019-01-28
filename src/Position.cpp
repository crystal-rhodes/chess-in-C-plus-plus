#include "Position.h"

extern int Decode(char a)
{
	char test = 'a';
	for (int i = 1; i <= 8; i++)
	{
		if (a == test) return i;
		else test++;
	}
	throw 10;
	//if (a == 'a') return 1;
	//if (a == 'b') return 2;
	//if (a == 'c') return 3;
	//if (a == 'd') return 4;
	//if (a == 'e') return 5;
	//if (a == 'f') return 6;
	//if (a == 'g') return 7;
	//if (a == 'h') return 8;
	//else throw 10;
}

istream & operator >>(istream &is, Position &pos)
{
	TryAgain:
	try
	{
		string Pos;
		getline(is, Pos, '\n');
		pos.X = Decode(Pos[0]) - 1;
		pos.Y = (Pos[1] - '0') - 1;
		if (pos.X > 7 || pos.X < 0) throw 10;
		if (pos.Y > 7 || pos.Y < 0) throw 10;
		
	}
	catch (const int &)
	{
		cout << "Invalid Position!" << endl;
		cin.ignore(INT_MAX, '\n');
		goto TryAgain;
	}

//EnterX:
//	try
//	{
//		cout << "Enter X: ";
//		char a;
//		is >> a;
//
//		pos.X = Decode(a) - 1;
//
//
//		if (pos.X > 7 || pos.X < 0) throw 10;
//	}
//	catch (const int &)
//	{
//		cout << "Invalid Position!" << endl;
//		cin.ignore(INT_MAX, '\n');
//		goto EnterX;
//	}
//
//	cin.ignore(INT_MAX, '\n');
//
//	try
//	{
//		cout << "Enter Y: ";
//		int a;
//		is >> a;
//		if (a > 8 || a < 1) throw 10;
//		pos.Y = a - 1;
//
//
//		if (pos.Y > 7 || pos.Y < 0) throw 10;
//	}
//	catch (const int &)
//	{
//		cout << "Invalid Position!" << endl;
//		goto EnterX;
//	}
//
	
	return is;
}
ostream & operator << (ostream &os, const Position &x)
{
	os << "(" << x.Y << ";" << x.X << ")";
	return os;
}
bool Position::operator==(const Position &x)
{
	if (x.X == this->X && x.Y == this->Y) return true;
	else return false;
}
void Position::operator=(const Position &x)
{
	this->X = x.X;
	this->Y = x.Y;
}
Position Position::operator-(const Position &x)
{
	Position a;
	a.X = this->X - x.X;
	a.Y = this->Y - x.Y;
	return a;
}






