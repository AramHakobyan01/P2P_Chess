#pragma once
#include <string>
enum class PieceName
{
	None = 0,
	Pawn = 1,
	Knight = 2,
	Bishop = 3,
	Rook = 4,
	Queen = 5,
	King = 6
};
enum class Color
{
	None = 1,
	White = 2,
	Black = 3
};
class Piece
{
public:
	Color color;
	PieceName name;
};