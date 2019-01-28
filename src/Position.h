#ifndef _POSITION_H_
#define _POSITION_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <map>
using namespace std;
class Position
{
private:
	int X;
	int Y;
public:
	// Constructors and Destructor
	Position() { X = 0; Y = 0; }
	Position(int x, int y) { X = x; Y = y; }
	~Position() {};

	// In order to enter and display information Position easier and more effectively
	friend istream & operator >> (istream &, Position &);
	friend ostream & operator << (ostream &, const Position &);

	// Getter and Setter
	inline int x(void) { return X; }
	inline int y(void) { return Y; }
	inline void setX(int x) { this->X = x; }
	inline void setY(int y) { this->Y = y; }

	// Member functions
	bool operator==(const Position &);
	Position operator-(const Position &);
	void operator=(const Position &);
	
};
#endif
