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
	for (int i = 1, j = 0, l = 0; l < 16; l++ ) {
		//std::cout << i << j << std::endl;
		figur[i].push_back(new Pawn(color, { i,j }));
		if (l == 7) {
			j = 0;
			i = 6;
			color = Color::Black;
		}
		else {
			j++;
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
		if (c.y - new_c.y == 2) {
			if (figur[new_c.x][new_c.y]->piece.color == Color::White) {
				delete figur[0][2];
				figur[0][2] = new Rook(figur[new_c.x][new_c.y]->piece.color, { 0,2 });
				delete figur[0][0];
				figur[0][0] = new None({ c.x,c.y });
			}
			else {
				delete figur[7][2];
				figur[7][2] = new Rook(figur[new_c.x][new_c.y]->piece.color, { 7,2 });
				delete figur[7][0];
				figur[7][0] = new None({ c.x,c.y });
			}
		}
		else if (c.y - new_c.y == -2) {
			if (figur[new_c.x][new_c.y]->piece.color == Color::White) {
				delete figur[0][4];
				figur[0][4] = new Rook(figur[new_c.x][new_c.y]->piece.color, { 0,2 });
				delete figur[0][7];
				figur[0][7] = new None({ c.x,c.y });
			}
			else {
				delete figur[7][4];
				figur[7][4] = new Rook(figur[new_c.x][new_c.y]->piece.color, { 7,2 });
				delete figur[7][7];
				figur[7][7] = new None({ c.x,c.y });
			}
		}
		
		break;
	}
}

void Board::Start(Coordinates coord) {
	if (coord.x < 8 && coord.x >= 0 && game_color == figur[coord.x][coord.y]->piece.color) {
		if (coord.y < 8 && coord.y >= 0 && figur[coord.x][coord.y]->piece.name != PieceName::None) {
			std::vector<Coordinates> move;
			move = figur[coord.x][coord.y]->WhereCanMove(figur, coord);
			std::cout << &figur[coord.x][coord.y] << std::endl;
			for (int i = 0; i < move.size(); i++) {
				std::cout << move[i].x << move[i].y << std::endl;
			}
			Coordinates new_coord;
			std::cin >> new_coord.x >> new_coord.y;
			if (coord.x != new_coord.x || coord.y != new_coord.y) {
				Move(coord, new_coord);
				if (game_color == Color::White) {
					game_color = Color::Black;
				}
				else {
					game_color = Color::White;
				}
			}
		}
	}
}