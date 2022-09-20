#include "Board.h"
#include "Piece.h"

#include <iostream>

Board::Board() {

	piece_l.insert({ PieceName::Pawn, &Board::CreatePawn });
	piece_l.insert({ PieceName::Knight, &Board::CreateKnight });
	piece_l.insert({ PieceName::Bishop, &Board::CreateBishop });
	piece_l.insert({ PieceName::Rook, &Board::CreateRook });
	piece_l.insert({ PieceName::Queen, &Board::CreateQueen });
	piece_l.insert({ PieceName::King, &Board::CreateKing });
	piece_l.insert({ PieceName::None, &Board::CreateNone });
	Color color = Color::White;
	for (int i = 0, j = 0; i < 2; i++) {
		(this->*piece_l[PieceName::Rook])({ j,0 }, color);
		(this->*piece_l[PieceName::Knight])({ j,1 }, color);
		(this->*piece_l[PieceName::Bishop])({ j,2 }, color);
		(this->*piece_l[PieceName::King])({ j,3 }, color);
		(this->*piece_l[PieceName::Queen])({ j,4 }, color);
		(this->*piece_l[PieceName::Bishop])({ j,5 }, color);
		(this->*piece_l[PieceName::Knight])({ j,6 }, color);
		(this->*piece_l[PieceName::Rook])({ j,7 }, color);
		king_c[i] = { j,3 };
		j = 7;
		color = Color::Black;
	}
	color = Color::White;
	for (int i = 1, j = 0, l = 0; l < 16; l++) {
		(this->*piece_l[PieceName::Pawn])({ i,j }, color);
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
			(this->*piece_l[PieceName::None])({ i,j }, color);
		}
	}
}

void Board::Move(Coordinates c, Coordinates new_c) {
	delete figur[new_c.x][new_c.y];
	(this->*piece_l[figur[c.x][c.y]->getP().name])({new_c.x,new_c.y}, figur[c.x][c.y]->getP().color);
	if (new_c.y + 1 < 8 && figur[new_c.x][new_c.y + 1]->getP().name == PieceName::Pawn) {
		Pawn* p = &dynamic_cast<Pawn&>(*figur[new_c.x][new_c.y]);
		if (abs(c.x - new_c.x) == 2) {
			p->set();
		}
	}else if (new_c.y - 1 >= 0 && figur[new_c.x][new_c.y - 1]->getP().name == PieceName::Pawn) {
		Pawn* p = &dynamic_cast<Pawn&>(*figur[new_c.x][new_c.y]);
		if (abs(c.x - new_c.x) == 2) {
			p->set();
		}
	}
	if (abs(c.x - new_c.x) == 1 && abs(c.y - new_c.y) == 1 && figur[c.x][new_c.y + 1]->getP().name == PieceName::Pawn) {
		delete figur[c.x][new_c.y];
		(this->*piece_l[PieceName::None])({ c.x,new_c.y }, Color::None);

	}
	if (figur[c.x][c.y]->getP().name == PieceName::King) {
		if (c.y - new_c.y == 2 && (&dynamic_cast<King&>(*figur[c.x][c.y]))->get() && (&dynamic_cast<Rook&>(*figur[c.x][c.y - 3]))->get()) {
			delete figur[c.x][c.y - 1];
			(this->*piece_l[PieceName::Rook])({ c.x,c.y - 1 }, figur[c.x][c.y]->getP().color);
			delete figur[c.x][c.y - 3];
			(this->*piece_l[PieceName::None])({ c.x,c.y - 3 }, Color::None);
		}
		else if (c.y - new_c.y == -2 && (&dynamic_cast<King&>(*figur[c.x][c.y]))->get() && (&dynamic_cast<Rook&>(*figur[c.x][c.y + 3]))->get()) {
			delete figur[c.x][c.y + 1];
			(this->*piece_l[PieceName::Rook])({ c.x,c.y + 1 }, figur[c.x][c.y]->getP().color);
			delete figur[c.x][c.y + 4];
			(this->*piece_l[PieceName::None])({ c.x,c.y + 4 }, Color::None);
		}
		(&dynamic_cast<King&>(*figur[new_c.x][new_c.y]))->set();
		if (c.x == king_c[0].x) {
			king_c[0] = new_c;
		}
		else { 
			king_c[1] = new_c;
		}
	}
	if (figur[c.x][c.y]->getP().name == PieceName::Rook) {
		(&dynamic_cast<Rook&>(*figur[new_c.x][new_c.y]))->set();
	}
	delete figur[c.x][c.y];
	(this->*piece_l[PieceName::None])({ c.x,c.y }, Color::None);
}

void Board::Start() {
	while (!ChackMate()) {
		Coordinates coord;
		Coordinates new_coord;
		std::cin >> coord.x >> coord.y;
		if (coord.x < 8 && coord.x >= 0 && game_color == figur[coord.x][coord.y]->getP().color) {
			if (coord.y < 8 && coord.y >= 0 && figur[coord.x][coord.y]->getP().name != PieceName::None) {
				std::vector<Coordinates> move;
				if (figur[coord.x][coord.y]->getP().color == Color::White) {
					move = figur[coord.x][coord.y]->WhereCanMove(figur, coord, king_c[0]);
 				}
				else {
					move = figur[coord.x][coord.y]->WhereCanMove(figur, coord, king_c[1]);
				}
				for (int i = 0; i < move.size(); i++) {
					std::cout << move[i].x << move[i].y << std::endl;
				}
				std::cin >> new_coord.x >> new_coord.y;
				for (int i = 0; i < move.size(); i++) {
					if ((move[i].x == new_coord.x && move[i].y == new_coord.y)) {
						Move(coord, new_coord);
						if (game_color == Color::White) {
							game_color = Color::Black;
						}
						else {
							game_color = Color::White;
						}
						break;
					}
				}
			}
		}
	}
}


