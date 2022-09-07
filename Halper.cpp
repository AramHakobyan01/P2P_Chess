#include <vector>

#include "Figur.h"
#include "Halper.h"

bool Halper::AreChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c) {
	int count = 0;
	Color color = figur[c.x][c.y]->piece.color;
	Coordinates kc;
	Piece temp = figur[new_c.x][new_c.y]->piece;
	//temp = figur[new_c.x][new_c.y];
	//std::cout << &figur[c.x][c.y] << std::endl;
	if (c.x != new_c.x || c.y != new_c.y) {
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
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (figur[i][j]->piece.name == PieceName::King && figur[i][j]->piece.color == color) {
				kc.x = i;
				kc.y = j;
				break;
			}
		}
	}
	for (int i = kc.x + 1, j = kc.y; i < 8; i++) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Rook) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = kc.x - 1, j = kc.y; i >= 0; i--) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Rook) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = kc.x, j = kc.y + 1; j < 8; j++) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Rook) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = kc.x, j = kc.y - 1; j >= 0; j--) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Rook) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = kc.x + 1, j = kc.y + 1; j < 8 && i < 8; j++, i++) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Bishop) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = kc.x - 1, j = kc.y + 1; j < 8 && i >= 0; j++, i--) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Bishop) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = kc.x + 1, j = kc.y - 1; j >= 0 && i < 8; j--, i++) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Bishop) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = kc.x - 1, j = kc.y - 1; j >= 0 && i >= 0; j--, i--) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Bishop) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	if (kc.x + 1 < 8 && kc.y + 2 < 8 && figur[kc.x + 1][kc.y + 2]->piece.color != color && figur[kc.x + 1][kc.y + 2]->piece.name == PieceName::Knight) {
		count++;
	}
	if (kc.x - 1 >= 0 && kc.y + 2 < 8 && figur[kc.x - 1][kc.y + 2]->piece.color != color && figur[kc.x - 1][kc.y + 2]->piece.name == PieceName::Knight) {
		count++;
	}
	if (kc.x - 1 >= 0 && kc.y - 2 >= 0 && figur[kc.x - 1][kc.y - 2]->piece.color != color && figur[kc.x - 1][kc.y - 2]->piece.name == PieceName::Knight) {
		count++;
	}
	if (kc.x + 1 < 8 && kc.y - 2 >= 0 && figur[kc.x + 1][kc.y - 2]->piece.color != color && figur[kc.x + 1][kc.y - 2]->piece.name == PieceName::Knight) {
		count++;
	}

	if (kc.x + 2 < 8 && kc.y + 1 < 8 && figur[kc.x + 2][kc.y + 1]->piece.color != color && figur[kc.x + 2][kc.y + 1]->piece.name == PieceName::Knight) {
		count++;
	}
	if (kc.x - 2 >= 0 && kc.y + 1 < 8 && figur[kc.x - 2][kc.y + 1]->piece.color != color && figur[kc.x - 2][kc.y + 1]->piece.name == PieceName::Knight) {
		count++;
	}
	if (kc.x - 2 >= 0 && kc.y - 1 >= 0 && figur[kc.x - 2][kc.y - 1]->piece.color != color && figur[kc.x - 2][kc.y - 1]->piece.name == PieceName::Knight) {
		count++;
	}
	if (kc.x + 2 < 8 && kc.y - 1 >= 0 && figur[kc.x + 2][kc.y - 1]->piece.color != color && figur[kc.x + 2][kc.y - 1]->piece.name == PieceName::Knight) {
		count++;
	}
	if (c.x != new_c.x || c.y != new_c.y) {
		switch (figur[new_c.x][new_c.y]->piece.name)
		{
		case PieceName::Pawn:
			delete figur[c.x][c.y];
			figur[c.x][c.y] = new Pawn(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::Knight:
			delete figur[c.x][c.y];
			figur[c.x][c.y] = new Knight(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::Bishop:
			delete figur[c.x][c.y];
			figur[c.x][c.y] = new Bishop(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::Rook:
			delete figur[c.x][c.y];
			figur[c.x][c.y] = new Rook(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::Queen:
			delete figur[c.x][c.y];
			figur[c.x][c.y] = new Queen(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::King:
			delete figur[c.x][c.y];
			figur[c.x][c.y] = new King(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		}
		switch (temp.name)
		{
		case PieceName::None:
			delete figur[new_c.x][new_c.y];
			figur[new_c.x][new_c.y] = new None({ new_c.x,new_c.y });
			break;
		case PieceName::Pawn:
			delete figur[new_c.x][new_c.y];
			figur[new_c.x][new_c.y] = new Pawn(temp.color, {new_c.x,new_c.y});
			break;
		case PieceName::Knight:
			delete figur[new_c.x][new_c.y];
			figur[new_c.x][new_c.y] = new Knight(temp.color, { new_c.x,new_c.y });
			break;
		case PieceName::Bishop:
			delete figur[new_c.x][new_c.y];
			figur[new_c.x][new_c.y] = new Bishop(temp.color, { new_c.x,new_c.y });
			break;
		case PieceName::Rook:
			delete figur[new_c.x][new_c.y];
			figur[new_c.x][new_c.y] = new Rook(temp.color, { new_c.x,new_c.y });
			break;
		case PieceName::Queen:
			delete figur[new_c.x][new_c.y];
			figur[new_c.x][new_c.y] = new Queen(temp.color, { new_c.x,new_c.y });
			break;
		case PieceName::King:
			delete figur[new_c.x][new_c.y];
			figur[new_c.x][new_c.y] = new King(temp.color, { new_c.x,new_c.y });
			break;
		}
	}	
	if (count == 0) {
		return false;
	}
	else {
		return true;
	}
}