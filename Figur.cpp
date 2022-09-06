#include <vector>

#include "Figur.h"
#include "Halper.h"

std::vector<Coordinates> Pawn::WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) {
	std::vector<Coordinates> pawnMove;
	Halper halp;
	if (figur[c.x][c.y]->piece.color == Color::White) {
		if (!halp.AreChacking(figur, c, c)) {
			if (c.x == 1) {
				if (figur[c.x + 2][c.y]->piece.name == PieceName::None && figur[c.x + 1][c.y]->piece.name == PieceName::None) {
					if (!halp.AreChacking(figur, c, { c.x + 2,c.y })) {
						pawnMove.push_back({ c.x + 2,c.y });
					}
				}
			}
			if (c.x + 1 < 8 && figur[c.x + 1][c.y]->piece.name == PieceName::None) {
				if (!halp.AreChacking(figur, c, { c.x + 1,c.y })) {
					pawnMove.push_back({ c.x + 1,c.y });
				}
			}
			if (c.y - 1 >= 0 && c.x + 1 < 8 && figur[c.x + 1][c.y - 1]->piece.name != PieceName::None && figur[c.x + 1][c.y - 1]->piece.color == Color::Black) {
				if (!halp.AreChacking(figur, c, { c.x + 1,c.y - 1 })) {
					pawnMove.push_back({ c.x + 1,c.y - 1 });
				}
			}
			if (c.y + 1 < 8 && c.x + 1 < 8 && figur[c.x + 1][c.y + 1]->piece.name != PieceName::None && figur[c.x + 1][c.y + 1]->piece.color == Color::Black) {
				if (!halp.AreChacking(figur, c, { c.x + 1,c.y + 1 })) {
					pawnMove.push_back({ c.x + 1,c.y + 1 });
				}
			}
		}
	}
	else if (figur[c.x][c.y]->piece.color == Color::Black) {
		if (!halp.AreChacking(figur, c, c)) {
			if (c.x == 6) {
				if (figur[c.x - 2][c.y]->piece.name == PieceName::None && figur[c.x - 1][c.y]->piece.name == PieceName::None) {
					if (!halp.AreChacking(figur, c, { c.x - 2,c.y })) {
						pawnMove.push_back({ c.x - 2,c.y });
					}
				}
			}
			if (figur[c.x - 1][c.y]->piece.name == PieceName::None) {
				if (!halp.AreChacking(figur, c, { c.x - 1,c.y })) {
					pawnMove.push_back({ c.x - 1,c.y });
				}
			}
			if (figur[c.x - 1][c.y - 1]->piece.name != PieceName::None && figur[c.x - 1][c.y - 1]->piece.color == Color::White) {
				if (!halp.AreChacking(figur, c, { c.x - 1,c.y - 1 })) {
					pawnMove.push_back({ c.x - 1,c.y - 1 });
				}
			}
			if (figur[c.x - 1][c.y + 1]->piece.name != PieceName::None && figur[c.x - 1][c.y + 1]->piece.color == Color::White) {
				if (!halp.AreChacking(figur, c, { c.x - 1,c.y + 1 })) {
					pawnMove.push_back({ c.x - 1,c.y + 1 });
				}
			}
		}
	}
	return pawnMove;
}

std::vector<Coordinates> Knight::WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) {
	std::vector<Coordinates> knightMove;
	Halper halp;
	if (!halp.AreChacking(figur, c, c)) {
		if(c.x + 1 < 8 && c.y + 2 < 8 && figur[c.x][c.y]->piece.color != figur[c.x + 1][c.y + 2]->piece.color){
			if (!halp.AreChacking(figur, c, { c.x + 1,c.y + 2 })) {
				knightMove.push_back({ c.x + 1,c.y + 2 });
			}
		}
		if (c.x + 1 < 8 && c.y - 2 >= 0 && figur[c.x][c.y]->piece.color != figur[c.x + 1][c.y - 2]->piece.color ) {
			if (!halp.AreChacking(figur, c, { c.x + 1,c.y - 2 })) {
				knightMove.push_back({ c.x + 1,c.y - 2 });
			}
		}
		if (c.x - 1 >= 0 && c.y + 2 < 8 && figur[c.x][c.y]->piece.color != figur[c.x - 1][c.y + 2]->piece.color ) {
			if (!halp.AreChacking(figur, c, { c.x - 1,c.y + 2 })) {
				knightMove.push_back({ c.x - 1,c.y + 2 });
			}
		}
		if (c.x - 1 >= 0 && c.y - 2 >= 0 && figur[c.x][c.y]->piece.color != figur[c.x - 1][c.y - 2]->piece.color) {
			if (!halp.AreChacking(figur, c, { c.x - 1,c.y - 2 })) {
				knightMove.push_back({ c.x - 1,c.y - 2 });
			}
		}
		if (c.x + 2 < 8 && c.y + 1 < 8 && figur[c.x][c.y]->piece.color != figur[c.x + 2][c.y + 1]->piece.color ) {
			if (!halp.AreChacking(figur, c, { c.x + 2,c.y + 1 })) {
				knightMove.push_back({ c.x + 2,c.y + 1 });
			}
		}
		if (c.x + 2 < 8 && c.y - 1 >= 0 && figur[c.x][c.y]->piece.color != figur[c.x + 2][c.y - 1]->piece.color ) {
			if (!halp.AreChacking(figur, c, { c.x + 2,c.y - 1 })) {
				knightMove.push_back({ c.x + 2,c.y - 1 });
			}
		}
		if (c.x - 2 >= 0 && c.y + 1 < 8 && figur[c.x][c.y]->piece.color != figur[c.x - 2][c.y + 1]->piece.color) {
			if (!halp.AreChacking(figur, c, { c.x - 2,c.y + 1 })) {
				knightMove.push_back({ c.x - 2,c.y + 1 });
			}
		}
		if (c.x - 2 >= 0 && c.y - 1 >= 0 && figur[c.x][c.y]->piece.color != figur[c.x - 2][c.y - 1]->piece.color ) {
			if (!halp.AreChacking(figur, c, { c.x - 2,c.y - 1 })) {
				knightMove.push_back({ c.x - 2,c.y - 1 });
			}
		}
	}
	return knightMove;
}

std::vector<Coordinates> Bishop::WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) {
	std::vector<Coordinates> bishopMove;
	Halper halp;
	if (!halp.AreChacking(figur, c, c)) {
		for (int i = c.x + 1, j = c.y + 1; i < 8 && j < 8; i++, j++) {
			if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
				if(!halp.AreChacking(figur, c, { i,j })){
					if (figur[i][j]->piece.color != Color::None) {
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
			if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
				if (!halp.AreChacking(figur, c, { i,j })) {
					if (figur[i][j]->piece.color != Color::None) {
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
			if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
				if (!halp.AreChacking(figur, c, { i,j })) {
					if (figur[i][j]->piece.color != Color::None) {
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
			if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
				if (!halp.AreChacking(figur, c, { i,j })) {
					if (figur[i][j]->piece.color != Color::None) {
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
	}
	return bishopMove;
}

std::vector<Coordinates> Rook::WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) {
	std::vector<Coordinates> rookMove;
	Halper halp;
	if (!halp.AreChacking(figur, c, c)) {
		for (int i = c.x + 1, j = c.y; i < 8; i++) {
			if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
				if (!halp.AreChacking(figur, c, { i,j })) {
					if (figur[i][j]->piece.color != Color::None) {
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
			if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
				if (!halp.AreChacking(figur, c, { i,j })) {
					if (figur[i][j]->piece.color != Color::None) {
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
	}
	for (int i = c.x, j = c.y + 1; j < 8; j++) {
		if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
			if (!halp.AreChacking(figur, c, { i,j })) {
				if (figur[i][j]->piece.color != Color::None) {
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
		if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
			if (!halp.AreChacking(figur, c, { i,j })) {
				if (figur[i][j]->piece.color != Color::None) {
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

std::vector<Coordinates> Queen::WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) {
	std::vector<Coordinates> queenMove(Rook::WhereCanMove(figur, c));
	std::vector<Coordinates> bishop = Bishop::WhereCanMove(figur, c);
	queenMove.insert(queenMove.end(), bishop.begin(), bishop.end());
	return queenMove;
}

std::vector<Coordinates> King::WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) {
	std::vector<Coordinates> kingMove;
	Halper halp;
	if (!halp.AreChacking(figur, c, c)) {
		if (c.x + 1 < 8 && figur[c.x][c.y]->piece.color != figur[c.x + 1][c.y]->piece.color) {
			if (!halp.AreChacking(figur, c, { c.x + 1,c.y })) {
				kingMove.push_back({ c.x + 1,c.y });
			}
		}
		if (c.y + 2 < 8 && figur[c.x][c.y]->piece.color != figur[c.x][c.y + 1]->piece.color) {
			if (!halp.AreChacking(figur, c, { c.x,c.y + 1 })) {
				kingMove.push_back({ c.x,c.y + 1 });
			}
		}
		if (c.x - 1 >= 0 && figur[c.x][c.y]->piece.color != figur[c.x - 1][c.y]->piece.color ) {
			if (!halp.AreChacking(figur, c, { c.x - 1,c.y })) {
				kingMove.push_back({ c.x - 1,c.y });
			}
		}
		if (c.y - 1 >= 0 && figur[c.x][c.y]->piece.color != figur[c.x][c.y - 1]->piece.color ) {
			if (!halp.AreChacking(figur, c, { c.x,c.y - 1 })) {
				kingMove.push_back({ c.x,c.y - 1 });
			}
		}
		if (c.x + 1 < 8 && c.y + 1 < 8 && figur[c.x][c.y]->piece.color != figur[c.x + 1][c.y + 1]->piece.color) {
			if (!halp.AreChacking(figur, c, { c.x + 1,c.y + 1 })) {
				kingMove.push_back({ c.x + 1,c.y + 1 });
			}
		}
		if (c.x + 1 < 8 && c.y - 1 >= 0 && figur[c.x][c.y]->piece.color != figur[c.x + 1][c.y - 1]->piece.color ) {
			if (!halp.AreChacking(figur, c, { c.x + 1,c.y - 1 })) {
				kingMove.push_back({ c.x + 1,c.y - 1 });
			}
		}
		if (c.x - 1 >= 0 && c.y + 1 < 8 && figur[c.x][c.y]->piece.color != figur[c.x - 1][c.y + 1]->piece.color ) {
			if (!halp.AreChacking(figur, c, { c.x - 1,c.y + 1 })) {
				kingMove.push_back({ c.x - 1,c.y + 1 });
			}
		}
		if (c.x - 1 >= 0 && c.y - 1 >= 0 && figur[c.x][c.y]->piece.color != figur[c.x - 1][c.y - 1]->piece.color) {
			if (!halp.AreChacking(figur, c, { c.x - 1,c.y - 1 })) {
				kingMove.push_back({ c.x - 1,c.y - 1 });
			}
		}
		if ((c.x == 0 || c.x == 7) && c.y == 3) {
			if (figur[c.x][c.y + 1]->piece.name == PieceName::None && figur[c.x][c.y + 2]->piece.name == PieceName::None && figur[c.x][c.y + 3]->piece.name == PieceName::None) {
				if (figur[c.x][c.y + 4]->piece.name == PieceName::Rook) {
					if (!halp.AreChacking(figur, c, { c.x,c.y + 1 }) && !halp.AreChacking(figur, c, { c.x,c.y + 2 })) {
						kingMove.push_back({ c.x ,c.y + 2 });
					}
				}
			}
			if (figur[c.x][c.y - 1]->piece.name == PieceName::None && figur[c.x][c.y - 2]->piece.name == PieceName::None) {
				if (figur[c.x][c.y - 3]->piece.name == PieceName::Rook) {
					if (!halp.AreChacking(figur, c, { c.x,c.y - 1 }) && !halp.AreChacking(figur, c, { c.x,c.y - 2 })) {
						kingMove.push_back({ c.x ,c.y - 2 });
					}
				}
			}
		}
	}
	return kingMove;
}
