#ifndef BOARD
#define BOARD

#include <vector> 
#include <unordered_map>

#include "Piece.h"
#include "Figur.h"

class Board
{
public:
	Board();
	void Move(Coordinates c, Coordinates new_c);
	void Start();
private:
	std::unordered_map<PieceName, void (Board::*)(Coordinates c, Color color)> piece_l;
	std::vector<std::vector<Figur*>> figur{ 8 };
	Color game_color = Color::White;
	Coordinates king_c[2];
	void CreatePawn(Coordinates c, Color color);
	void CreateKnight(Coordinates c, Color color);
	void CreateBishop(Coordinates c, Color color);
	void CreateRook(Coordinates c, Color color);
	void CreateKing(Coordinates c, Color color);
	void CreateQueen(Coordinates c, Color color);
	void CreateNone(Coordinates c, Color color);
	bool ChackMate();
	
};
#endif //BOARD