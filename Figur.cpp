#include <vector>

#include "Figur.h"

std::vector<Coordinates> Pawn::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
	std::vector<Coordinates> pawnMove;
	if (figur[c.x][c.y]->getP().color == Color::White) {
		if (c.x == 1) {
			if (figur[c.x + 2][c.y]->getP().name == PieceName::None && figur[c.x + 1][c.y]->getP().name == PieceName::None) {
				if (!AreChacking(figur, c, { c.x + 2,c.y }, king_c)) {

					pawnMove.push_back({ c.x + 2,c.y });
				}
			}
		}
		if (c.x + 1 < 8 && figur[c.x + 1][c.y]->getP().name == PieceName::None) {
			if (!AreChacking(figur, c, { c.x + 1,c.y }, king_c)) {
				pawnMove.push_back({ c.x + 1,c.y });
			}
		}
		if (c.y - 1 >= 0 && c.x + 1 < 8 && figur[c.x + 1][c.y - 1]->getP().name != PieceName::None && figur[c.x + 1][c.y - 1]->getP().color == Color::Black) {
			if (!AreChacking(figur, c, { c.x + 1,c.y - 1 }, king_c)) {
				pawnMove.push_back({ c.x + 1,c.y - 1 });
			}
		}
		if (c.y + 1 < 8 && c.x + 1 < 8 && figur[c.x + 1][c.y + 1]->getP().name != PieceName::None && figur[c.x + 1][c.y + 1]->getP().color == Color::Black) {
			if (!AreChacking(figur, c, { c.x + 1,c.y + 1 }, king_c)) {
				pawnMove.push_back({ c.x + 1,c.y + 1 });
			}
		}
	}
	else if (figur[c.x][c.y]->getP().color == Color::Black) {
		if (c.x == 6) {
			if (figur[c.x - 2][c.y]->getP().name == PieceName::None && figur[c.x - 1][c.y]->getP().name == PieceName::None) {
				if (!AreChacking(figur, c, { c.x - 2,c.y }, king_c)) {
					pawnMove.push_back({ c.x - 2,c.y });
				}
			}
		}
		if (c.x - 1 >= 0 && figur[c.x - 1][c.y]->getP().name == PieceName::None) {
			if (!AreChacking(figur, c, { c.x - 1,c.y }, king_c)) {
				pawnMove.push_back({ c.x - 1,c.y });
			}
		}
		if (c.x - 1 >= 0 && c.y - 1 >= 0 && figur[c.x - 1][c.y - 1]->getP().name != PieceName::None && figur[c.x - 1][c.y - 1]->getP().color == Color::White) {
			if (!AreChacking(figur, c, { c.x - 1,c.y - 1 }, king_c)) {
				pawnMove.push_back({ c.x - 1,c.y - 1 });
			}
		}
		if (c.x - 1 >= 0 && c.y + 1 < 8 && figur[c.x - 1][c.y + 1]->getP().name != PieceName::None && figur[c.x - 1][c.y + 1]->getP().color == Color::White) {
			if (!AreChacking(figur, c, { c.x - 1,c.y + 1 }, king_c)) {
				pawnMove.push_back({ c.x - 1,c.y + 1 });
			}
		}
	}
	 
		if (figur[c.x][c.y]->getP().color == Color::White) {
			if (c.y + 1 < 8 &&
				figur[c.x][c.y + 1]->getP().name == PieceName::Pawn &&
				figur[c.x][c.y + 1]->getP().color != figur[c.x][c.y]->getP().color &&
				(&dynamic_cast<Pawn&>(*figur[c.x][c.y + 1]))->get()) {
				pawnMove.push_back({ c.x + 1, c.y + 1 });
			}
			if (c.y - 1 >= 0 &&
				figur[c.x][c.y - 1]->getP().name == PieceName::Pawn &&
				figur[c.x][c.y - 1]->getP().color != figur[c.x][c.y]->getP().color &&
				(&dynamic_cast<Pawn&>(*figur[c.x][c.y - 1]))->get()) {
				pawnMove.push_back({ c.x + 1, c.y - 1 });
			}
		}
		else if (figur[c.x][c.y]->getP().color == Color::Black) {
			if (c.y + 1 < 8 &&
				figur[c.x][c.y + 1]->getP().name == PieceName::Pawn &&
				figur[c.x][c.y + 1]->getP().color != figur[c.x][c.y]->getP().color && (&dynamic_cast<Pawn&>(*figur[c.x][c.y + 1]))->get()) {
				pawnMove.push_back({ c.x - 1, c.y + 1 });
			}
			else if (c.y - 1 >= 0 &&
				figur[c.x][c.y - 1]->getP().name == PieceName::Pawn &&
				figur[c.x][c.y - 1]->getP().color != figur[c.x][c.y]->getP().color && (&dynamic_cast<Pawn&>(*figur[c.x][c.y - 1]))->get()) {
				pawnMove.push_back({ c.x - 1, c.y - 1 });
			}
		}
	return pawnMove;
}

std::vector<Coordinates> Knight::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
	std::vector<Coordinates> knightMove;
	if(c.x + 1 < 8 && c.y + 2 < 8 && figur[c.x][c.y]->getP().color != figur[c.x + 1][c.y + 2]->getP().color){
		if (!AreChacking(figur, c, { c.x + 1,c.y + 2 }, king_c)) {
			knightMove.push_back({ c.x + 1,c.y + 2 });
		}
	}
	if (c.x + 1 < 8 && c.y - 2 >= 0 && figur[c.x][c.y]->getP().color != figur[c.x + 1][c.y - 2]->getP().color ) {
		if (!AreChacking(figur, c, { c.x + 1,c.y - 2 }, king_c)) {
			knightMove.push_back({ c.x + 1,c.y - 2 });
		}
	}
	if (c.x - 1 >= 0 && c.y + 2 < 8 && figur[c.x][c.y]->getP().color != figur[c.x - 1][c.y + 2]->getP().color ) {
		if (!AreChacking(figur, c, { c.x - 1,c.y + 2 }, king_c)) {
			knightMove.push_back({ c.x - 1,c.y + 2 });
		}
	}
	if (c.x - 1 >= 0 && c.y - 2 >= 0 && figur[c.x][c.y]->getP().color != figur[c.x - 1][c.y - 2]->getP().color) {
		if (!AreChacking(figur, c, { c.x - 1,c.y - 2 }, king_c)) {
			knightMove.push_back({ c.x - 1,c.y - 2 });
		}
	}
	if (c.x + 2 < 8 && c.y + 1 < 8 && figur[c.x][c.y]->getP().color != figur[c.x + 2][c.y + 1]->getP().color ) {
		if (!AreChacking(figur, c, { c.x + 2,c.y + 1 }, king_c)) {
			knightMove.push_back({ c.x + 2,c.y + 1 });
		}
	}
	if (c.x + 2 < 8 && c.y - 1 >= 0 && figur[c.x][c.y]->getP().color != figur[c.x + 2][c.y - 1]->getP().color ) {
		if (!AreChacking(figur, c, { c.x + 2,c.y - 1 }, king_c)) {
			knightMove.push_back({ c.x + 2,c.y - 1 });
		}
	}
	if (c.x - 2 >= 0 && c.y + 1 < 8 && figur[c.x][c.y]->getP().color != figur[c.x - 2][c.y + 1]->getP().color) {
		if (!AreChacking(figur, c, { c.x - 2,c.y + 1 }, king_c)) {
			knightMove.push_back({ c.x - 2,c.y + 1 });
		}
	}
	if (c.x - 2 >= 0 && c.y - 1 >= 0 && figur[c.x][c.y]->getP().color != figur[c.x - 2][c.y - 1]->getP().color ) {
		if (!AreChacking(figur, c, { c.x - 2,c.y - 1 }, king_c)) {
			knightMove.push_back({ c.x - 2,c.y - 1 });
		}
	}
	return knightMove;
}

std::vector<Coordinates> Bishop::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
	std::vector<Coordinates> bishopMove;
	for (int i = c.x + 1, j = c.y + 1; i < 8 && j < 8; i++, j++) {
		if (figur[c.x][c.y]->getP().color != figur[i][j]->getP().color) {
			if(!AreChacking(figur, c, { i,j }, king_c)){
				if (figur[i][j]->getP().color != Color::None) {
					bishopMove.push_back({ i,j });
					break;
				}
				else {
					bishopMove.push_back({ i,j });
				}
			}
		}
		else {
			break;
		}
	}
	for (int i = c.x + 1, j = c.y - 1; i < 8 && j >= 0; i++, j--) {
		if (figur[c.x][c.y]->getP().color != figur[i][j]->getP().color) {
			if (!AreChacking(figur, c, { i,j }, king_c)) {
				if (figur[i][j]->getP().color != Color::None) {
					bishopMove.push_back({ i,j });
					break;
				}
				else {
					bishopMove.push_back({ i,j });
				}
			}
		}
		else {
			break;
		}
	}
	for (int i = c.x - 1, j = c.y + 1; i >= 0 && j < 8; i--, j++) {
		if (figur[c.x][c.y]->getP().color != figur[i][j]->getP().color) {
			if (!AreChacking(figur, c, { i,j }, king_c)) {
				if (figur[i][j]->getP().color != Color::None) {
					bishopMove.push_back({ i,j });
					break;
				}
				else {
					bishopMove.push_back({ i,j });
				}
			}
			
		}
		else {
			break;
		}
	}
	for (int i = c.x - 1, j = c.y - 1; i >= 0 && j >= 0; i--, j--) {
		if (figur[c.x][c.y]->getP().color != figur[i][j]->getP().color) {
			if (!AreChacking(figur, c, { i,j }, king_c)) {
				if (figur[i][j]->getP().color != Color::None) {
					bishopMove.push_back({ i,j });
					break;
				}
				else {
					bishopMove.push_back({ i,j });
				}
			}
		}
		else {
			break;
		}
	}
	return bishopMove;
}

std::vector<Coordinates> Rook::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
	std::vector<Coordinates> rookMove;
	for (int i = c.x + 1, j = c.y; i < 8; i++) {
		if (figur[c.x][c.y]->getP().color != figur[i][j]->getP().color) {
			if (!AreChacking(figur, c, { i,j }, king_c)) {
				if (figur[i][j]->getP().color != Color::None) {
					rookMove.push_back({ i,j });
					break;
				}
				else {
					rookMove.push_back({ i,j });
				}
			}
		}
		else {
			break;
		}
	}
	for (int i = c.x - 1, j = c.y; i >= 0; i--) {
		if (figur[c.x][c.y]->getP().color != figur[i][j]->getP().color) {
			if (!AreChacking(figur, c, { i,j }, king_c)) {
				if (figur[i][j]->getP().color != Color::None) {
					rookMove.push_back({ i,j });
					break;
				}
				else {
					rookMove.push_back({ i,j });
				}
			}
		}
		else {
			break;
		}
	}
	for (int i = c.x, j = c.y + 1; j < 8; j++) {
		if (figur[c.x][c.y]->getP().color != figur[i][j]->getP().color) {
			if (!AreChacking(figur, c, { i,j }, king_c)) {
				if (figur[i][j]->getP().color != Color::None) {
					rookMove.push_back({ i,j });
					break;
				}
				else {
					rookMove.push_back({ i,j });
				}
			}
		}
		else {
			break;
		}
	}
	for (int i = c.x, j = c.y - 1; j >= 0; j--) {
		if (figur[c.x][c.y]->getP().color != figur[i][j]->getP().color) {
			if (!AreChacking(figur, c, { i,j }, king_c)) {
				if (figur[i][j]->getP().color != Color::None) {
					rookMove.push_back({ i,j });
					break;
				}
				else {
					rookMove.push_back({ i,j });
				}
			}
		}
		else {
			break;
		}
	}
	return rookMove;
}

std::vector<Coordinates> Queen::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
	std::vector<Coordinates> queenMove = Rook::WhereCanMove(figur, c, king_c);
	std::vector<Coordinates> bishop = Bishop::WhereCanMove(figur, c, king_c);
	queenMove.insert(queenMove.end(), bishop.begin(), bishop.end());
	return queenMove;
}

std::vector<Coordinates> King::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
	std::vector<Coordinates> kingMove;
		if (c.x + 1 < 8 && figur[c.x][c.y]->getP().color != figur[c.x + 1][c.y]->getP().color) {
            if (!AreChacking(figur, c, { c.x + 1,c.y }, { c.x + 1,c.y })) {
				kingMove.push_back({ c.x + 1,c.y });
			}
		}
		if (c.y + 1 < 8 && figur[c.x][c.y]->getP().color != figur[c.x][c.y + 1]->getP().color) {
            if (!AreChacking(figur, c, { c.x,c.y + 1 }, { c.x,c.y + 1 })) {
				kingMove.push_back({ c.x,c.y + 1 });
			}
		}
		if (c.x - 1 >= 0 && figur[c.x][c.y]->getP().color != figur[c.x - 1][c.y]->getP().color ) {
            if (!AreChacking(figur, c, { c.x - 1,c.y }, { c.x - 1,c.y })) {
				kingMove.push_back({ c.x - 1,c.y });
			}
		}
		if (c.y - 1 >= 0 && figur[c.x][c.y]->getP().color != figur[c.x][c.y - 1]->getP().color ) {
            if (!AreChacking(figur, c, { c.x,c.y - 1 }, { c.x,c.y - 1 })) {
				kingMove.push_back({ c.x,c.y - 1 });
			}
		}
        if (c.x + 1 < 8 && c.y + 1 < 8 && figur[c.x][c.y]->getP().color != figur[c.x + 1][c.y + 1]->getP().color) {
            if (!AreChacking(figur, c, { c.x + 1,c.y + 1 }, { c.x + 1,c.y + 1 })) {
                kingMove.push_back({ c.x + 1,c.y + 1 });
            }
        }
		if (c.x + 1 < 8 && c.y - 1 >= 0 && figur[c.x][c.y]->getP().color != figur[c.x + 1][c.y - 1]->getP().color ) {
            if (!AreChacking(figur, c, { c.x + 1,c.y - 1 }, { c.x + 1,c.y - 1 })) {
				kingMove.push_back({ c.x + 1,c.y - 1 });
			}
		}
		if (c.x - 1 >= 0 && c.y + 1 < 8 && figur[c.x][c.y]->getP().color != figur[c.x - 1][c.y + 1]->getP().color ) {
            if (!AreChacking(figur, c, { c.x - 1,c.y + 1 }, { c.x - 1,c.y + 1 })) {
				kingMove.push_back({ c.x - 1,c.y + 1 });
			}
		}
		if (c.x - 1 >= 0 && c.y - 1 >= 0 && figur[c.x][c.y]->getP().color != figur[c.x - 1][c.y - 1]->getP().color) {
            if (!AreChacking(figur, c, { c.x - 1,c.y - 1 }, { c.x - 1,c.y - 1 })) {
				kingMove.push_back({ c.x - 1,c.y - 1 });
			}
		}
		if ((c.x == 0 || c.x == 7) && c.y == 3) {
			if (figur[c.x][c.y + 1]->getP().name == PieceName::None && figur[c.x][c.y + 2]->getP().name == PieceName::None && figur[c.x][c.y + 3]->getP().name == PieceName::None) {
				if (figur[c.x][c.y + 4]->getP().name == PieceName::Rook) {
                    if (!AreChacking(figur, c, { c.x,c.y + 1 }, { c.x,c.y + 1 }) && !AreChacking(figur, c, { c.x,c.y + 2 }, { c.x,c.y + 2 })) {
						kingMove.push_back({ c.x ,c.y + 2 });
					}
                }
			}
			if (figur[c.x][c.y - 1]->getP().name == PieceName::None && figur[c.x][c.y - 2]->getP().name == PieceName::None) {
				if (figur[c.x][c.y - 3]->getP().name == PieceName::Rook) {
                    if (!AreChacking(figur, c, { c.x,c.y - 1 }, { c.x,c.y - 1 }) && !AreChacking(figur, c, { c.x,c.y - 2 }, { c.x,c.y - 2 })) {
						kingMove.push_back({ c.x ,c.y - 2 });
					}
				}
			}
	}
	return kingMove;
}
