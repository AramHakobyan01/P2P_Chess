#include "Board.h"
#include "Piece.h"

#include <iostream>

Board::Board() {
	std::cout << "mmmm" << std::endl;
	if (figur.empty()) {
		std::cout << "mmmm" << std::endl;
		Color color = Color::White;
		for (int i = 0, j = 0; i < 2; i++) {
			figur[j][0] = new Rook();
			//figur[j][1] = new Knight(figur[j][1], color, { j,1 });
			//figur[j][2] = new Bishop(figur[j][1], color, { j,2 });
			//figur[j][3] = new King(figur[j][1], color, { j,3 });
			//figur[j][4] = new Queen(figur[j][1], color, { j,4 });
			//figur[j][5] = new Bishop(figur[j][1], color, { j,5 });
			//figur[j][6] = new Knight(figur[j][1], color, { j,6 });
			//figur[j][7] = new Rook(figur[j][1], color, { j,7 });
			j = 7;
			color = Color::Black;
		}
		//color = Color::White;
		//std::cout << "mmmm" << std::endl;
		//for (int i = 1, j = 0, l = 0; l < 15; l++) {
		//	figur[j][i] = new Pawn(figur[j][i], color, { j,i });
		//	if (l == 7) {
		//		j = 6;
		//		i = 0;
		//		color = Color::Black;
		//	}
		//}
		//std::cout << "mmmm" << std::endl;
		//for (int i = 2; i < 6; i++) {
		//	for (int j = 0; j < 8; j++) {
		//		figur[j][i]->coord = { j,i };
		//		figur[j][i]->piece = { Color::None,PieceName::None };
		//	}
		//}
	}
}

void Board::Start(Coordinates coord) {
	if (coord.x < 8 && coord.x >= 0) {
		if (coord.y < 8 && coord.y >= 0) {
			std::cout << "mmmm";
			std::vector<Coordinates> move;//= figur[coord.x][coord.y]->WhereCanMove(figur, coord);
			for (int i = 0; i < move.size(); i++) {
				std::cout << move[i].x << move[i].y << std::endl;
			}
		}
	}
}