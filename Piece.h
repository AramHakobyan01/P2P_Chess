#pragma once
#include <string>
enum PieceName
{
	None = 0,
	Pawn = 1,
	Knight = 2,
	Bishop = 3,
	Rook = 4,
	Queen = 5,
	King = 6
};
class Piece
{
public:
	bool color;
	PieceName name;
};