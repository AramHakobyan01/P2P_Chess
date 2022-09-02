#pragma once
#include "Piece.h"
#include <vector>
#include "Figur.h"
class Board 
{
public:
	std::vector<std::vector<Figur*>> figur;
	bool game_color;
	Board() {
		if (figur.empty()) {
			for (int j = 0; j < 8; j++) {
				for (int i = 0; i < 8; i++) {
					switch (j)
					{
					case 0:
						switch (i)
						{
						case 0:
							figur[j][i] = new Rook();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::White,PieceName::Rook };
							break;
						case 1:
							figur[j][i] = new Knight();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::White,PieceName::Knight };
							break;
						case 2:
							figur[j][i] = new Bishop();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::White,PieceName::Bishop };
							break;
						case 3:
							figur[j][i] = new King();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::White,PieceName::King };
							break;
						case 4:
							figur[j][i] = new Queen();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::White,PieceName::Queen };
							break;
						case 5:
							figur[j][i] = new Bishop();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::White,PieceName::Bishop };
							break;
						case 6:
							figur[j][i] = new Knight();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::White,PieceName::Knight };
							break;
						case 7:
							figur[j][i] = new Rook();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::White,PieceName::Rook };
							break;
						}
						break;
					case 1:
						figur[j][i] = new Pawn();
						figur[j][i]->coord = { j,i };
						figur[j][i]->piece = { Color::White,PieceName::Pawn };
						break;
					case 6:
						figur[j][i] = new Pawn();
						figur[j][i]->coord = { j,i };
						figur[j][i]->piece = { Color::Black,PieceName::Pawn };
						break;
					case 7:
						switch (i)
						{
						case 0:
							figur[j][i] = new Rook();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::Black,PieceName::Rook };
							break;
						case 1:
							figur[j][i] = new Knight();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::Black,PieceName::Knight };
							break;
						case 2:
							figur[j][i] = new Bishop();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::Black,PieceName::Bishop };
							break;
						case 3:
							figur[j][i] = new King();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::Black,PieceName::King };
							break;
						case 4:
							figur[j][i] = new Queen();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::Black,PieceName::Queen };
							break;
						case 5:
							figur[j][i] = new Bishop();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::Black,PieceName::Bishop };
							break;
						case 6:
							figur[j][i] = new Knight();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::Black,PieceName::Knight };
							break;
						case 7:
							figur[j][i] = new Rook();
							figur[j][i]->coord = { j,i };
							figur[j][i]->piece = { Color::Black,PieceName::Rook };
							break;
						}
						break;
					default:
						figur[j][i]->coord = { j,i };
						figur[j][i]->piece = { Color::None,PieceName::None };
						break;
					}
				}
			}
		}
	}
	void Start(Coordinates coordinates, Coordinates new_coordinates, bool color);
	~Board(){}
};