#pragma once
#include "Piece.h"
#include <vector>
#include "Figur.h"
class Board 
{
public:
	std::vector<Figur*> figur[8];
	bool game_color;
	Board() {
		figur[0].push_back(new Rook());
		figur[0][0]->coord = { 0,0 };
		figur[0][0]->piece = { Color::White,PieceName::Knight };
	}
	~Board(){}
};