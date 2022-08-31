#include "Board.h"
#include "Piece.h"
#include "Halper.h"
#include "Pawns.h"
#include "Bishops.h"
#include "Queens.h"
#include "Kings.h"
#include "Knights.h"
#include "Rooks.h"
std::vector<Piece> figur[8];
bool game_color;
void Board::Start(Coordinates coordinates, Coordinates new_coordinates, bool color) {
	game_color = color;
	Halper halper;
	Pawns pawns;
	Knights knights;
	Bishops bishops;
	Rooks rooks;
	Queens queens;
	Kings kings;
	if (new_coordinates.x < 8 && new_coordinates.x >= 0) {
		if (new_coordinates.y < 8 && new_coordinates.y >= 0) {
			if (figur[coordinates.x][coordinates.y].name == Pawn) {
				pawns.MovePawn(coordinates, new_coordinates);
			}
			if (figur[coordinates.x][coordinates.y].name == Knight) {
				knights.MoveKnight(coordinates, new_coordinates);
			}
			if (figur[coordinates.x][coordinates.y].name == Bishop) {
				bishops.MoveBishop(coordinates, new_coordinates);
			}
			if (figur[coordinates.x][coordinates.y].name == Rook) {
				rooks.MoveRook(coordinates, new_coordinates);
			}
			if (figur[coordinates.x][coordinates.y].name == Queen) {
				queens.MoveQueen(coordinates, new_coordinates);
			}
			if (figur[coordinates.x][coordinates.y].name == King) {
				kings.MoveKing(coordinates, new_coordinates);
			}
		}
	}
}