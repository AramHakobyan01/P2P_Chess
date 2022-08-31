#include "Kings.h"
void Kings::MoveKing(Coordinates coordinates, Coordinates new_coordinates) {
	if (figur[coordinates.x][coordinates.y].color == game_color) {
		if (figur[new_coordinates.x][new_coordinates.y].name == None) {
			if (halper.CanKingMove(coordinates, new_coordinates)) {
				if (!halper.Check(coordinates, new_coordinates)) {
					figur[new_coordinates.x][new_coordinates.y] = { game_color,King };
					figur[coordinates.x][coordinates.y] = { NULL,None };
				}
			}
			else if (CanKingCastling(coordinates, new_coordinates)) {
				if (game_color) {
					if (coordinates.y - new_coordinates.y == 2) {
						figur[0][0] = {NULL,None};
						figur[0][2] = { game_color,Rook };
						figur[new_coordinates.x][new_coordinates.y] = { game_color,King };
						figur[coordinates.x][coordinates.y] = { NULL,None };
					}
					else if (coordinates.y - new_coordinates.y == -2) {
						figur[0][7] = { NULL,None };
						figur[0][4] = { game_color,Rook };
						figur[new_coordinates.x][new_coordinates.y] = { game_color,King };
						figur[coordinates.x][coordinates.y] = { NULL,None };
					}
				}
				else {
					if (coordinates.y - new_coordinates.y == 2) {
						figur[7][0] = { NULL,None };
						figur[7][2] = { game_color,Rook };
						figur[new_coordinates.x][new_coordinates.y] = { game_color,King };
						figur[coordinates.x][coordinates.y] = { NULL,None };
					}
					else if (coordinates.y - new_coordinates.y == -2) {
						figur[7][7] = { NULL,None };
						figur[7][4] = { game_color,Rook };
						figur[new_coordinates.x][new_coordinates.y] = { game_color,King };
						figur[coordinates.x][coordinates.y] = { NULL,None };
					}
				}
			}
		}
		else {
			Piece figurH = figur[new_coordinates.x][new_coordinates.y];
			if (halper.CanKingMove(coordinates, new_coordinates)) {
				if (figurH.color != game_color) {
					if (!halper.Check(coordinates, new_coordinates)) {
						figur[new_coordinates.x][new_coordinates.y] = { game_color,King };
						figur[coordinates.x][coordinates.y] = { NULL,None };
					}
				}
			}
		}
	}
}
bool Kings::CanKingCastling(Coordinates coordinates, Coordinates new_coordinates) {
	if (coordinates.x == 0 && coordinates.y == 3) {
		if (coordinates.y - new_coordinates.y == 2) {
			if (figur[0][0].name == Rook) {
				if (figur[0][1].name == None && figur[0][2].name == None) {
					for (int i = 0; i < 3; i++) {
						if (halper.Check(coordinates, { coordinates.x,coordinates.y + i })) {
							return false;
						}
					}
					return true;
				}
			}
		}
		else if (coordinates.y - new_coordinates.y == -2) {
			if (figur[0][7].name == Rook) {
				if (figur[0][4].name == None && figur[0][5].name == None && figur[0][6].name == None) {
					for (int i = 0; i < 3; i++) {
						if (halper.Check(coordinates, { coordinates.x,coordinates.y + i })) {
							return false;
						}
					}
					return true;
				}
			}
		}
	}
	else if (coordinates.x == 7 && coordinates.y == 3) {
		if (coordinates.y - new_coordinates.y == 2) {
			if (figur[7][0].name == Rook) {
				if (figur[7][1].name == None && figur[7][2].name == None) {
					for (int i = 0; i < 3; i++) {
						if (halper.Check(coordinates, { coordinates.x,coordinates.y + i })) {
							return false;
						}
					}
					return true;
				}
			}
		}
		else if (coordinates.y - new_coordinates.y == -2) {
			if (figur[7][7].name == Rook) {
				if (figur[7][4].name == None && figur[7][5].name == None && figur[7][6].name == None) {
					for (int i = 0; i < 3; i++) {
						if (halper.Check(coordinates, { coordinates.x,coordinates.y + i })) {
							return false;
						}
					}
					return true;
				}
			}
		}
	}
	return false;
}
