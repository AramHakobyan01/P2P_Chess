#include <vector>

#include "Figur.h"
#include "Board.h"

bool Figur::AreChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c) {
	int count = 0;
	Color color = figur[c.x][c.y]->getP().color;
	for (int i = king_c.x + 1, j = king_c.y; i < 8; i++) {
		if (figur[i][j]->getP().color != color) {
			if (figur[i][j]->getP().name == PieceName::Queen || figur[i][j]->getP().name == PieceName::Rook) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = king_c.x - 1, j = king_c.y; i >= 0; i--) {
		if (i == c.x && j == c.y) {
			continue;
		}
		else if (i == new_c.x && j == new_c.y) {
			break;
		}
		if (figur[i][j]->getP().color != color) {
			if (figur[i][j]->getP().name == PieceName::Queen || figur[i][j]->getP().name == PieceName::Rook) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = king_c.x, j = king_c.y + 1; j < 8; j++) {
		if (i == c.x && j == c.y) {
			continue;
		}
		else if (i == new_c.x && j == new_c.y) {
			break;
		}
		if (figur[i][j]->getP().color != color) {
			if (figur[i][j]->getP().name == PieceName::Queen || figur[i][j]->getP().name == PieceName::Rook) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = king_c.x, j = king_c.y - 1; j >= 0; j--) {
		if (i == c.x && j == c.y) {
			continue;
		}
		else if (i == new_c.x && j == new_c.y) {
			break;
		}
		if (figur[i][j]->getP().color != color) {
			if (figur[i][j]->getP().name == PieceName::Queen || figur[i][j]->getP().name == PieceName::Rook) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = king_c.x + 1, j = king_c.y + 1; j < 8 && i < 8; j++, i++) {
		if (i == c.x && j == c.y) {
			continue;
		}
		else if (i == new_c.x && j == new_c.y) {
			break;
		}
		if (figur[i][j]->getP().color != color) {
			if (figur[i][j]->getP().name == PieceName::Queen || figur[i][j]->getP().name == PieceName::Bishop) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = king_c.x - 1, j = king_c.y + 1; j < 8 && i >= 0; j++, i--) {
		if (i == c.x && j == c.y) {
			continue;
		}
		else if (i == new_c.x && j == new_c.y) {
			break;
		}
		if (figur[i][j]->getP().color != color) {
			if (figur[i][j]->getP().name == PieceName::Queen || figur[i][j]->getP().name == PieceName::Bishop) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = king_c.x + 1, j = king_c.y - 1; j >= 0 && i < 8; j--, i++) {
		if (i == c.x && j == c.y) {
			continue;
		}
		else if (i == new_c.x && j == new_c.y) {
			break;
		}
		if (figur[i][j]->getP().color != color) {
			if (figur[i][j]->getP().name == PieceName::Queen || figur[i][j]->getP().name == PieceName::Bishop) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	for (int i = king_c.x - 1, j = king_c.y - 1; j >= 0 && i >= 0; j--, i--) {
		if (i == c.x && j == c.y) {
			continue;
		}
		else if (i == new_c.x && j == new_c.y) {
			break;
		}
		if (figur[i][j]->getP().color != color) {
			if (figur[i][j]->getP().name == PieceName::Queen || figur[i][j]->getP().name == PieceName::Bishop) {
				count++;
				break;
			}
		}
		else {
			break;
		}
	}
	if (king_c.x + 1 < 8 && king_c.y + 2 < 8 && figur[king_c.x + 1][king_c.y + 2]->getP().color != color && figur[king_c.x + 1][king_c.y + 2]->getP().name == PieceName::Knight) {
		if ((king_c.x + 1 == new_c.x || king_c.y + 2 == new_c.y) || (king_c.x + 1 == c.x && king_c.y + 2 == c.y)) {
		}
		else {
			count++;
		}
	}
	if (king_c.x - 1 >= 0 && king_c.y + 2 < 8 && figur[king_c.x - 1][king_c.y + 2]->getP().color != color && figur[king_c.x - 1][king_c.y + 2]->getP().name == PieceName::Knight) {
		if ((king_c.x - 1 == new_c.x || king_c.y + 2 == new_c.y) || (king_c.x - 1 == c.x && king_c.y + 2 == c.y)) {
		}
		else {
			count++;
		}
	}
	if (king_c.x - 1 >= 0 && king_c.y - 2 >= 0 && figur[king_c.x - 1][king_c.y - 2]->getP().color != color && figur[king_c.x - 1][king_c.y - 2]->getP().name == PieceName::Knight) {
		if ((king_c.x - 1 == new_c.x || king_c.y - 2 == new_c.y) || (king_c.x - 1 == c.x && king_c.y - 2 == c.y)) {
		}
		else {
			count++;
		}
	}
	if (king_c.x + 1 < 8 && king_c.y - 2 >= 0 && figur[king_c.x + 1][king_c.y - 2]->getP().color != color && figur[king_c.x + 1][king_c.y - 2]->getP().name == PieceName::Knight) {
		if ((king_c.x + 1 == new_c.x || king_c.y - 2 == new_c.y) || (king_c.x + 1 == c.x && king_c.y - 2 == c.y)) {
		}
		else {
			count++;
		}
	}

	if (king_c.x + 2 < 8 && king_c.y + 1 < 8 && figur[king_c.x + 2][king_c.y + 1]->getP().color != color && figur[king_c.x + 2][king_c.y + 1]->getP().name == PieceName::Knight) {
		if ((king_c.x + 2 == new_c.x || king_c.y + 1 == new_c.y) || (king_c.x + 2 == c.x && king_c.y + 1 == c.y)) {
		}
		else {
			count++;
		}
	}
	if (king_c.x - 2 >= 0 && king_c.y + 1 < 8 && figur[king_c.x - 2][king_c.y + 1]->getP().color != color && figur[king_c.x - 2][king_c.y + 1]->getP().name == PieceName::Knight) {
		if ((king_c.x - 2 == new_c.x || king_c.y + 1 == new_c.y) || (king_c.x - 2 == c.x && king_c.y + 1 == c.y)) {
		}
		else {
			count++;
		}
	}
	if (king_c.x - 2 >= 0 && king_c.y - 1 >= 0 && figur[king_c.x - 2][king_c.y - 1]->getP().color != color && figur[king_c.x - 2][king_c.y - 1]->getP().name == PieceName::Knight) {
		if ((king_c.x - 2 == new_c.x || king_c.y - 1 == new_c.y) || (king_c.x - 2 == c.x && king_c.y - 1 == c.y)) {
		}
		else {
			count++;
		}
	}
	if (king_c.x + 2 < 8 && king_c.y - 1 >= 0 && figur[king_c.x + 2][king_c.y - 1]->getP().color != color && figur[king_c.x + 2][king_c.y - 1]->getP().name == PieceName::Knight) {
		if ((king_c.x + 2 == new_c.x || king_c.y - 1 == new_c.y) || (king_c.x + 2 == c.x && king_c.y - 1 == c.y)) {
		}
		else {
			count++;
		}
	}	
	if (count == 0) {
		return false;
	}
	else {
		return true;
	}
}

void Board::CreatePawn(Coordinates c, Color color) {
	if (figur[c.x].size() < 8) {
		figur[c.x].push_back(new Pawn(color));
	}
	else {
		figur[c.x][c.y] = new Pawn(color);
	}
}

void Board::CreateKnight(Coordinates c, Color color) {
	if (figur[c.x].size() < 8) {
		figur[c.x].push_back(new Knight(color));
	}
	else {
		figur[c.x][c.y] = new Knight(color);
	}
}

void Board::CreateBishop(Coordinates c, Color color) {
	if (figur[c.x].size() < 8) {
		figur[c.x].push_back(new Bishop(color));
	}
	else {
		figur[c.x][c.y] = new Bishop(color);
	}
}

void Board::CreateRook(Coordinates c, Color color) {
	if (figur[c.x].size() < 8) {
		figur[c.x].push_back(new Rook(color));
	}
	else {
		figur[c.x][c.y] = new Rook(color);
	}
}

void Board::CreateKing(Coordinates c, Color color) {
	if (figur[c.x].size() < 8) {
		figur[c.x].push_back(new King(color));
	}
	else {
		figur[c.x][c.y] = new King(color);
	}
}
void Board::CreateQueen(Coordinates c, Color color) {
	if (figur[c.x].size() < 8) {
		figur[c.x].push_back(new Queen(color));
	}
	else {
		figur[c.x][c.y] = new Queen(color);
	}
}

void Board::CreateNone(Coordinates c, Color color) {
	if (figur[c.x].size() < 8) {
		figur[c.x].push_back(new None(c));
	}
	else {
		figur[c.x][c.y] = new None(c);
	}
}

bool Board::ChackMate() {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (figur[i][j]->getP().color == Color::White && game_color == Color::White) {
				if (!figur[i][j]->WhereCanMove(figur, { i,j }, king_c[0]).empty()) {
					count++;
				}
			}
			else if (figur[i][j]->getP().color == Color::Black && game_color == Color::Black) {
				if (!figur[i][j]->WhereCanMove(figur, { i,j }, king_c[1]).empty()) {
					count++;
				}
			}
		}
	}
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}