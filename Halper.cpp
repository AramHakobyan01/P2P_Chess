#include <vector>

#include "Figur.h"
#include "Halper.h"

bool Halper::AreChacking(std::vector<std::vector<Figur*>> figur, Coordinates c, Coordinates new_c) {
	int count = 0;
	Color color = figur[c.x][c.y]->piece.color;
	Coordinates kc;
	std::vector<Figur> temp;
	temp[0].piece = figur[new_c.x][new_c.y]->piece;
	(*figur[new_c.x][new_c.y]).piece = (*figur[c.x][c.y]).piece;
	(*figur[c.x][c.y]).piece = { Color::None,PieceName::None };
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
	}
	for (int i = kc.x - 1, j = kc.y; i >= 0; i--) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Rook) {
				count++;
				break;
			}
		}
	}
	for (int i = kc.x, j = kc.y + 1; j < 8; j++) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Rook) {
				count++;
				break;
			}
		}
	}
	for (int i = kc.x, j = kc.y - 1; j >= 0; j--) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Rook) {
				count++;
				break;
			}
		}
	}
	for (int i = kc.x + 1, j = kc.y + 1; j < 8 && i < 8; j++, i++) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Bishop) {
				count++;
				break;
			}
		}
	}
	for (int i = kc.x - 1, j = kc.y + 1; j < 8 && i >= 0; j++, i--) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Bishop) {
				count++;
				break;
			}
		}
	}
	for (int i = kc.x + 1, j = kc.y - 1; j >= 0 && i < 8; j--, i++) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Bishop) {
				count++;
				break;
			}
		}
	}
	for (int i = kc.x - 1, j = kc.y - 1; j >= 0 && i >= 0; j++, i++) {
		if (figur[i][j]->piece.color != color) {
			if (figur[i][j]->piece.name == PieceName::Queen || figur[i][j]->piece.name == PieceName::Bishop) {
				count++;
				break;
			}
		}
	}
	if (figur[kc.x + 1][kc.y + 2]->piece.name == PieceName::Knight) {
		if (figur[kc.x + 1][kc.y + 2]->piece.color != color && kc.x + 1 < 8 && kc.y + 2 < 8) {
			count++;
		}
		if (figur[kc.x - 1][kc.y + 2]->piece.color != color && kc.x - 1 >= 0 && kc.y + 2 < 8) {
			count++;
		}
		if (figur[kc.x - 1][kc.y - 2]->piece.color != color && kc.x - 1 >= 0 && kc.y - 2 >= 0) {
			count++;
		}
		if (figur[kc.x + 1][kc.y - 2]->piece.color != color && kc.x + 1 < 8 && kc.y - 2 >= 0) {
			count++;
		}

		if (figur[kc.x + 2][kc.y + 1]->piece.color != color && kc.x + 2 < 8 && kc.y + 1 < 8) {
			count++;
		}
		if (figur[kc.x - 2][kc.y + 1]->piece.color != color && kc.x - 2 >= 0 && kc.y + 1 < 8) {
			count++;
		}
		if (figur[kc.x - 2][kc.y - 1]->piece.color != color && kc.x - 2 >= 0 && kc.y - 1 >= 0) {
			count++;
		}
		if (figur[kc.x + 2][kc.y - 1]->piece.color != color && kc.x + 2 < 8 && kc.y - 1 >= 0) {
			count++;
		}
	}
	(*figur[c.x][c.y]).piece = (*figur[new_c.x][new_c.y]).piece;
	(*figur[new_c.x][new_c.y]).piece = temp[0].piece;
	if (count == 0) {
		return false;
	}
	else {
		return true;
	}
}