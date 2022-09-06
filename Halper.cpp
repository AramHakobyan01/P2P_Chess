#include <vector>

#include "Figur.h"
#include "Halper.h"

bool Halper::AreChacking(std::vector<std::vector<Figur*>> figur, Coordinates c, Coordinates new_c) {
	int count = 0;
	Color color = figur[c.x][c.y]->piece.color;
	Coordinates kc;
	std::vector<Figur*> temp;
	temp.push_back(figur[new_c.x][new_c.y]);
	if (c.x != new_c.x || c.y != new_c.y) {
		switch (figur[c.x][c.y]->piece.name)
		{
		case PieceName::Pawn:
			figur[new_c.x][new_c.y] = new Pawn(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
			figur[c.x][c.y] = new None({ c.x,c.y });
			break;
		case PieceName::Knight:
			figur[new_c.x][new_c.y] = new Knight(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
			figur[c.x][c.y] = new None({ c.x,c.y });
			break;
		case PieceName::Bishop:
			figur[new_c.x][new_c.y] = new Bishop(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
			figur[c.x][c.y] = new None({ c.x,c.y });
			break;
		case PieceName::Rook:
			figur[new_c.x][new_c.y] = new Rook(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
			figur[c.x][c.y] = new None({ c.x,c.y });
			break;
		case PieceName::Queen:
			figur[new_c.x][new_c.y] = new Queen(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
			figur[c.x][c.y] = new None({ c.x,c.y });
			break;
		case PieceName::King:
			figur[new_c.x][new_c.y] = new King(figur[c.x][c.y]->piece.color, { new_c.x,new_c.y });
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
	//if (figur[kc.x + 1][kc.y + 2]->piece.name == PieceName::Knight) {
	//	if (kc.x + 1 < 8 && kc.y + 2 < 8 && figur[kc.x + 1][kc.y + 2]->piece.color != color ) {
	//		count++;
	//	}
	//	if (kc.x - 1 >= 0 && kc.y + 2 < 8 && figur[kc.x - 1][kc.y + 2]->piece.color != color ) {
	//		count++;
	//	}
	//	if (kc.x - 1 >= 0 && kc.y - 2 >= 0 && figur[kc.x - 1][kc.y - 2]->piece.color != color ) {
	//		count++;
	//	}
	//	if (kc.x + 1 < 8 && kc.y - 2 >= 0 && figur[kc.x + 1][kc.y - 2]->piece.color != color ) {
	//		count++;
	//	}

	//	if (kc.x + 2 < 8 && kc.y + 1 < 8 && figur[kc.x + 2][kc.y + 1]->piece.color != color ) {
	//		count++;
	//	}
	//	if (kc.x - 2 >= 0 && kc.y + 1 < 8 && figur[kc.x - 2][kc.y + 1]->piece.color != color ) {
	//		count++;
	//	}
	//	if (kc.x - 2 >= 0 && kc.y - 1 >= 0 && figur[kc.x - 2][kc.y - 1]->piece.color != color ) {
	//		count++;
	//	}
	//	if (kc.x + 2 < 8 && kc.y - 1 >= 0 && figur[kc.x + 2][kc.y - 1]->piece.color != color ) {
	//		count++;
	//	}
	//}
	if (c.x != new_c.x || c.y != new_c.y) {
		switch (figur[new_c.x][new_c.y]->piece.name)
		{
		case PieceName::Pawn:
			figur[c.x][c.y] = new Pawn(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::Knight:
			figur[c.x][c.y] = new Knight(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::Bishop:
			figur[c.x][c.y] = new Bishop(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::Rook:
			figur[c.x][c.y] = new Rook(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::Queen:
			figur[c.x][c.y] = new Queen(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		case PieceName::King:
			figur[c.x][c.y] = new King(figur[new_c.x][new_c.y]->piece.color, { c.x,c.y });
			break;
		}
		switch (temp[0]->piece.name)
		{
		case PieceName::Pawn:
			figur[new_c.x][new_c.y] = new Pawn(temp[0]->piece.color, {new_c.x,new_c.y});
			break;
		case PieceName::Knight:
			figur[new_c.x][new_c.y] = new Knight(temp[0]->piece.color, { new_c.x,new_c.y });
			break;
		case PieceName::Bishop:
			figur[new_c.x][new_c.y] = new Bishop(temp[0]->piece.color, { new_c.x,new_c.y });
			break;
		case PieceName::Rook:
			figur[new_c.x][new_c.y] = new Rook(temp[0]->piece.color, { new_c.x,new_c.y });
			break;
		case PieceName::Queen:
			figur[new_c.x][new_c.y] = new Queen(temp[0]->piece.color, { new_c.x,new_c.y });
			break;
		case PieceName::King:
			figur[new_c.x][new_c.y] = new King(temp[0]->piece.color, { new_c.x,new_c.y });
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