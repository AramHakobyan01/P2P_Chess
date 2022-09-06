#include "Board.h"
#include "Piece.h"

#include <iostream>

Board::Board() {
	Color color = Color::White;
	for (int i = 0, j = 0; i < 2; i++) {
		figur[j].push_back(new Rook(color, {j,0}));
		figur[j].push_back(new Knight(color, { j,1 }));
		figur[j].push_back(new Bishop(color, { j,2 }));
		figur[j].push_back(new King(color, { j,3 }));
		figur[j].push_back(new Queen(color, { j,4 }));
		figur[j].push_back(new Bishop(color, { j,5 }));
		figur[j].push_back(new Knight(color, { j,6 }));
		figur[j].push_back(new Rook(color, { j,7 }));
		j = 7;
		color = Color::Black;
	}

	color = Color::White;
	for (int i = 1, j = 0, l = 0; l < 16; l++ ,j++) {
		figur[i].push_back(new Pawn(color, { i,j }));
		if (l == 7) {
			j = 0;
			i = 6;
			color = Color::Black;
		}
	}

	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			figur[i].push_back(new None({ i,j }));
		}
	}
}

void Board::Move(Coordinates c, Coordinates new_c) {
	switch (figur[c.x][c.y]->piece.name)
	{
	case PieceName::Pawn:
		delete figur[new_c.x][new_c.y];
		figur[new_c.x][new_c.y] = new Pawn(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
		delete figur[c.x][c.y];
		figur[c.x][c.y] = new None({ c.x,c.y });
		break;
	case PieceName::Knight:
		delete figur[new_c.x][new_c.y];
		figur[new_c.x][new_c.y] = new Knight(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
		delete figur[c.x][c.y];
		figur[c.x][c.y] = new None({ c.x,c.y });
		break;
	case PieceName::Bishop:
		delete figur[new_c.x][new_c.y];
		figur[new_c.x][new_c.y] = new Bishop(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
		delete figur[c.x][c.y];
		figur[c.x][c.y] = new None({ c.x,c.y });
		break;
	case PieceName::Rook:
		delete figur[new_c.x][new_c.y];
		figur[new_c.x][new_c.y] = new Rook(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
		delete figur[c.x][c.y];
		figur[c.x][c.y] = new None({ c.x,c.y });
		break;
	case PieceName::Queen:
		delete figur[new_c.x][new_c.y];
		figur[new_c.x][new_c.y] = new Queen(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
		delete figur[c.x][c.y];
		figur[c.x][c.y] = new None({ c.x,c.y });
		break;
	case PieceName::King:
		delete figur[new_c.x][new_c.y];
		figur[new_c.x][new_c.y] = new King(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
		delete figur[c.x][c.y];
		figur[c.x][c.y] = new None({ c.x,c.y });
		break;
	}
}

void Board::Start(Coordinates coord) {
	if (coord.x < 8 && coord.x >= 0) {
		if (coord.y < 8 && coord.y >= 0) {
			std::vector<Coordinates> move;
			move = figur[coord.x][coord.y]->WhereCanMove(figur, coord);
			for (int i = 0; i < move.size(); i++) {
				std::cout << move[i].x << move[i].y << std::endl;
			}
			Coordinates new_coord;
			std::cin >> new_coord.x >> new_coord.y;
			Move(coord, new_coord);
		}
	}
}