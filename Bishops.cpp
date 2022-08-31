#include "Bishops.h"
#include <vector>
void Bishops::MoveBishop(Coordinates coordinates, Coordinates new_coordinates) {
	if (halper.CanBishopMove(coordinates, new_coordinates)) {
		if (figur[coordinates.x][coordinates.y].color == game_color) {
			if (figur[new_coordinates.x][new_coordinates.y].name == None) {
				figur[new_coordinates.x][new_coordinates.y] = { game_color,Bishop };
				figur[coordinates.x][coordinates.y] = { NULL,None };
				if (halper.AreChacking(game_color)) {
					figur[coordinates.x][coordinates.y] = { game_color,Bishop };
					figur[new_coordinates.x][new_coordinates.y] = { NULL,None };
				}
			}
			else {
				Piece figurH = figur[new_coordinates.x][new_coordinates.y];
				if (figur[new_coordinates.x][new_coordinates.y].color != game_color) {
					figur[new_coordinates.x][new_coordinates.y] = { game_color,Bishop };
					figur[coordinates.x][coordinates.y] = { NULL,None };
					if (halper.AreChacking(game_color)) {
						figur[coordinates.x][coordinates.y] = { game_color,Bishop };
						figur[new_coordinates.x][new_coordinates.y] = figurH;
					}
				}
			}
		}
	}
}