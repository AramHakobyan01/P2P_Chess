#include "Figur.h"
#include <vector>
#include "Halper.h"
std::vector<Coordinates> Pawn::WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) {
	std::vector<Coordinates> pawnMove;
	Halper halper;
	if (figur[c.x][c.y]->piece.color == Color::White) {
		if (!halper.AreChacking(figur, c, c)) {
			if (c.x == 1) {
				if (figur[c.x + 2][c.y]->piece.name == PieceName::None && figur[c.x + 1][c.y]->piece.name == PieceName::None) {
					if (!halper.AreChacking(figur, c, { c.x + 2,c.y })) {
						pawnMove.push_back({ c.x + 2,c.y });
					}
				}
			}
			if (figur[c.x + 1][c.y]->piece.name == PieceName::None) {
				if (!halper.AreChacking(figur, c, { c.x + 1,c.y })) {
					pawnMove.push_back({ c.x + 1,c.y });
				}
			}
			if (figur[c.x + 1][c.y - 1]->piece.name != PieceName::None && figur[c.x + 1][c.y - 1]->piece.color == Color::Black) {
				if (!halper.AreChacking(figur, c, { c.x + 1,c.y - 1 })) {
					pawnMove.push_back({ c.x + 1,c.y - 1 });
				}
			}
			if (figur[c.x + 1][c.y + 1]->piece.name != PieceName::None && figur[c.x + 1][c.y + 1]->piece.color == Color::Black) {
				if (!halper.AreChacking(figur, c, { c.x + 1,c.y + 1 })) {
					pawnMove.push_back({ c.x + 1,c.y + 1 });
				}
			}
		}
	}
	else if (figur[c.x][c.y]->piece.color == Color::Black) {
		if (!halper.AreChacking(figur, c, c)) {
			if (c.x == 6) {
				if (figur[c.x - 2][c.y]->piece.name == PieceName::None && figur[c.x - 1][c.y]->piece.name == PieceName::None) {
					if (!halper.AreChacking(figur, c, { c.x - 2,c.y })) {
						pawnMove.push_back({ c.x - 2,c.y });
					}
				}
			}
			if (figur[c.x - 1][c.y]->piece.name == PieceName::None) {
				if (!halper.AreChacking(figur, c, { c.x - 1,c.y })) {
					pawnMove.push_back({ c.x - 1,c.y });
				}
			}
			if (figur[c.x - 1][c.y - 1]->piece.name != PieceName::None && figur[c.x - 1][c.y - 1]->piece.color == Color::White) {
				if (!halper.AreChacking(figur, c, { c.x - 1,c.y - 1 })) {
					pawnMove.push_back({ c.x - 1,c.y - 1 });
				}
			}
			if (figur[c.x - 1][c.y + 1]->piece.name != PieceName::None && figur[c.x - 1][c.y + 1]->piece.color == Color::White) {
				if (!halper.AreChacking(figur, c, { c.x - 1,c.y + 1 })) {
					pawnMove.push_back({ c.x - 1,c.y + 1 });
				}
			}
		}
	}
	return pawnMove;
}

std::vector<Coordinates> Knight::WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) {
	std::vector<Coordinates> knightMove;
	Halper halper;
	if (!halper.AreChacking(figur, c, c)) {
		if(figur[c.x][c.y]->piece.color != figur[c.x + 1][c.y + 2]->piece.color && c.x + 1 < 8 && c.y + 2 < 8){
			if (!halper.AreChacking(figur, c, { c.x + 1,c.y + 2 })) {
				knightMove.push_back({ c.x + 1,c.y + 2 });
			}
		}
		if (figur[c.x][c.y]->piece.color != figur[c.x + 1][c.y - 2]->piece.color && c.x + 1 < 8 && c.y - 2 >= 0) {
			if (!halper.AreChacking(figur, c, { c.x + 1,c.y - 2 })) {
				knightMove.push_back({ c.x + 1,c.y - 2 });
			}
		}
		if (figur[c.x][c.y]->piece.color != figur[c.x - 1][c.y + 2]->piece.color && c.x - 1 >= 0 && c.y + 2 < 8) {
			if (!halper.AreChacking(figur, c, { c.x - 1,c.y + 2 })) {
				knightMove.push_back({ c.x - 1,c.y + 2 });
			}
		}
		if (figur[c.x][c.y]->piece.color != figur[c.x - 1][c.y - 2]->piece.color && c.x - 1 >= 0 && c.y - 2 >= 0) {
			if (!halper.AreChacking(figur, c, { c.x - 1,c.y - 2 })) {
				knightMove.push_back({ c.x - 1,c.y - 2 });
			}
		}
		if (figur[c.x][c.y]->piece.color != figur[c.x + 2][c.y + 1]->piece.color && c.x + 2 < 8 && c.y + 1 < 8) {
			if (!halper.AreChacking(figur, c, { c.x + 2,c.y + 1 })) {
				knightMove.push_back({ c.x + 2,c.y + 1 });
			}
		}
		if (figur[c.x][c.y]->piece.color != figur[c.x + 2][c.y - 1]->piece.color && c.x + 2 < 8 && c.y - 1 >= 0) {
			if (!halper.AreChacking(figur, c, { c.x + 2,c.y - 1 })) {
				knightMove.push_back({ c.x + 2,c.y - 1 });
			}
		}
		if (figur[c.x][c.y]->piece.color != figur[c.x - 2][c.y + 1]->piece.color && c.x - 2 >= 0 && c.y + 1 < 8) {
			if (!halper.AreChacking(figur, c, { c.x - 1,c.y + 1 })) {
				knightMove.push_back({ c.x - 1,c.y + 1 });
			}
		}
		if (figur[c.x][c.y]->piece.color != figur[c.x - 2][c.y - 1]->piece.color && c.x - 2 >= 0 && c.y - 1 >= 0) {
			if (!halper.AreChacking(figur, c, { c.x - 2,c.y - 1 })) {
				knightMove.push_back({ c.x - 2,c.y - 1 });
			}
		}
	}
	return knightMove;
}

std::vector<Coordinates> Bishop::WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) {
	std::vector<Coordinates> bishopMove;
	Halper halper;
	if (!halper.AreChacking(figur, c, c)) {
		for (int i = c.x + 1, j = c.y + 1; i < 8 && j < 8; i++, j++) {
			if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
				if(!halper.AreChacking(figur, c, { i,j })){
					if (figur[c.x][c.y]->piece.color != Color::None) {
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
				if (!halper.AreChacking(figur, c, { i,j })) {
					if (figur[c.x][c.y]->piece.color != Color::None) {
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
				if (!halper.AreChacking(figur, c, { i,j })) {
					if (figur[c.x][c.y]->piece.color != Color::None) {
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
				if (!halper.AreChacking(figur, c, { i,j })) {
					if (figur[c.x][c.y]->piece.color != Color::None) {
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
	Halper halper;
	if (!halper.AreChacking(figur, c, c)) {
		for (int i = c.x + 1, j = c.y; i < 8; i++) {
			if (figur[c.x][c.y]->piece.color != figur[i][j]->piece.color) {
				if (!halper.AreChacking(figur, c, { i,j })) {
					if (figur[c.x][c.y]->piece.color != Color::None) {
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
				if (!halper.AreChacking(figur, c, { i,j })) {
					if (figur[c.x][c.y]->piece.color != Color::None) {
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
			if (!halper.AreChacking(figur, c, { i,j })) {
				if (figur[c.x][c.y]->piece.color != Color::None) {
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
			if (!halper.AreChacking(figur, c, { i,j })) {
				if (figur[c.x][c.y]->piece.color != Color::None) {
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
	return kingMove;
}
