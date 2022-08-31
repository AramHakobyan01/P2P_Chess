#include "Pawns.h"
#include <iostream>
void Pawns::MovePawn(Coordinates coordinates, Coordinates new_coordinates) {
	if (halper.CanPawnMove(coordinates, new_coordinates)) {
		if (figur[coordinates.x][coordinates.y].color == game_color) {
			figur[new_coordinates.x][new_coordinates.y] = {game_color,Pawn};
			figur[coordinates.x][coordinates.y] = { NULL,None };
			if (halper.AreChacking(game_color)) {
				figur[coordinates.x][coordinates.y] = { game_color,Pawn };
				figur[new_coordinates.x][new_coordinates.y] = { NULL,None };
			}
		}
	}else if (halper.CanPawnEat(coordinates, new_coordinates)) {
		if (figur[coordinates.x][coordinates.y].color == game_color) {
			Piece figurH = figur[coordinates.x][coordinates.y];
			if (figur[new_coordinates.x][new_coordinates.y].color != game_color) {
				figur[new_coordinates.x][new_coordinates.y] = { game_color,Pawn };
				figur[coordinates.x][coordinates.y] = { NULL,None };
				if (halper.AreChacking(game_color)) {
					figur[coordinates.x][coordinates.y] = { game_color,Pawn };
					figur[new_coordinates.x][new_coordinates.y] = figurH;
				}
			}
		}
	}
}
