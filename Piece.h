#ifndef _Piece_
#define _Piece_
enum class PieceName
{
	None = 0,
	Pawn,
	Knight,
	Bishop,
	Rook,
	Queen,
	King
};

enum class Color
{
	None = 0,
	White,
	Black
};

struct Piece
{
	Color color;
	PieceName name;
};
#endif _Piece_