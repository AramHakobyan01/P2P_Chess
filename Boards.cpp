#include "Board.h"
#include "Piece.h"
#include "Halper.h"
std::vector<Piece> figur[8];
bool game_color;
void Board::Start(Coordinates coord, Coordinates new_coord, bool color) {
	game_color = color;
	if (new_coord.x < 8 && new_coord.x >= 0) {
		if (new_coord.y < 8 && new_coord.y >= 0) {
			figur[coord.x][coord.y]->Move();
		}
	}
}