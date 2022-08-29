#include "Logic.h"
#include "Halper.h"

void Logic::Start(Coordinates coordinates, Coordinates new_coordinates, bool color) {
	Logic::game_color = color;
	if (new_coordinates.x < 8 && new_coordinates.x >= 0) {
		if (new_coordinates.y < 8 && new_coordinates.y >= 0) {
			if ((*halper.CheckCoordinates(coordinates)).piece.name == Pawn) {
				MovePawn(coordinates, new_coordinates);
			}
			if ((*halper.CheckCoordinates(coordinates)).piece.name == Knight) {
				MoveKnight(coordinates, new_coordinates);
			}
			if ((*halper.CheckCoordinates(coordinates)).piece.name == Bishop) {
				MoveBishop(coordinates, new_coordinates);
			}
			if ((*halper.CheckCoordinates(coordinates)).piece.name == Rook) {
				MoveRook(coordinates, new_coordinates);
			}
			if ((*halper.CheckCoordinates(coordinates)).piece.name == Queen) {
				MoveQueen(coordinates, new_coordinates);
			}
			if ((*halper.CheckCoordinates(coordinates)).piece.name == King) {
				MoveKing(coordinates, new_coordinates);
			}
		}
	}
}
void Logic::MovePawn(Coordinates coordinates, Coordinates new_coordinates) {
	cout << game_color;
	vector<Figur>::iterator pawn = halper.CheckCoordinates(coordinates);
	if (halper.CanPawnMove(pawn, new_coordinates)) {
		if ((*pawn).piece.color == game_color) {
			cout << "true     " << endl;
			*pawn = { {game_color,Pawn},{new_coordinates.x,new_coordinates.y} };
			if (halper.AreChacking(game_color)) {
				*pawn = { {game_color,Pawn},{coordinates.x,coordinates.y} };
			}
			cout << (*pawn).coordinates.x << (*pawn).coordinates.y << endl;
		}
	}
	if (halper.CanPawnEat(pawn, new_coordinates)) {
		if ((*pawn).piece.color == game_color) {
			vector<Figur>::iterator figur = halper.CheckCoordinates(new_coordinates);
			if ((*figur).piece.color != game_color) {
				Erase(figur);
				*pawn = { {game_color,Pawn},{new_coordinates.x,new_coordinates.y} };
				if (halper.AreChacking(game_color)) {
					*pawn = { {game_color,Pawn},{coordinates.x,coordinates.y} };
					NotErase(figur);
				}
			}
		}
	}
}
void Logic::MoveKnight(Coordinates coordinates, Coordinates new_coordinates) {
	vector<Figur>::iterator knight = halper.CheckCoordinates(coordinates);
	if (halper.CanKnightMove(knight, new_coordinates)) {
		if ((*knight).piece.color == game_color) {
			if ((*halper.CheckCoordinates(new_coordinates)).piece.name == None) {
				*knight = { {game_color,Knight},{new_coordinates.x,new_coordinates.y} };
				if (halper.AreChacking(game_color)) {
					*knight = { {game_color,Knight},{coordinates.x,coordinates.y} };
				}
				cout << (*knight).coordinates.x << (*knight).coordinates.y << endl;
			}
			else {
				vector<Figur>::iterator figur = halper.CheckCoordinates(new_coordinates);
				if ((*figur).piece.color != game_color) {
					Erase(figur);
					*knight = { {game_color,Knight},{new_coordinates.x,new_coordinates.y} };
					if (halper.AreChacking(game_color)) {
						*knight = { {game_color,Knight},{coordinates.x,coordinates.y} };
						NotErase(figur);
					}
				}
			}
		}
	}
}
void Logic::MoveBishop(Coordinates coordinates, Coordinates new_coordinates) {
	vector<Figur>::iterator bishop = halper.CheckCoordinates(coordinates);
	if (halper.CanBishopMove(bishop, new_coordinates)) {
		if ((*bishop).piece.color == game_color) {
			if ((*halper.CheckCoordinates(new_coordinates)).piece.name == None) {
				*bishop = { {game_color,Bishop},{new_coordinates.x,new_coordinates.y} };
				if (halper.AreChacking(game_color)) {
					*bishop = { {game_color,Bishop},{coordinates.x,coordinates.y} };
				}
				cout << (*bishop).coordinates.x << (*bishop).coordinates.y << endl;
			}
			else {
				vector<Figur>::iterator figur = halper.CheckCoordinates(new_coordinates);
				if ((*figur).piece.color != game_color) {
					Erase(figur);
					*bishop = { {game_color,Bishop},{new_coordinates.x,new_coordinates.y} };
					if (halper.AreChacking(game_color)) {
						*bishop = { {game_color,Bishop},{coordinates.x,coordinates.y} };
						NotErase(figur);
					}
				}
			}
		}
	}
}
void Logic::MoveRook(Coordinates coordinates, Coordinates new_coordinates) {
	vector<Figur>::iterator rook = halper.CheckCoordinates(coordinates);
	if (halper.CanRookMove(rook, new_coordinates)) {
		if ((*rook).piece.color == game_color) {
			if ((*halper.CheckCoordinates(new_coordinates)).piece.name == None) {
				*rook = { {game_color,Rook},{new_coordinates.x,new_coordinates.y} };
				if (halper.AreChacking(game_color)) {
					*rook = { {game_color,Rook},{coordinates.x,coordinates.y} };
				}
			}
			else {
				vector<Figur>::iterator figur = halper.CheckCoordinates(new_coordinates);
				if ((*figur).piece.color != game_color) {
					Erase(figur);
					*rook = { {game_color,Rook},{new_coordinates.x,new_coordinates.y} };
					if (halper.AreChacking(game_color)) {
						*rook = { {game_color,Rook},{coordinates.x,coordinates.y} };
						NotErase(figur);
					}
				}
			}
		}
	}
}
void Logic::MoveQueen(Coordinates coordinates, Coordinates new_coordinates) {
	vector<Figur>::iterator queen = halper.CheckCoordinates(coordinates);
	if (halper.CanQueenMove(queen, new_coordinates)) {
		if ((*queen).piece.color == game_color) {
			if ((*halper.CheckCoordinates(new_coordinates)).piece.name == None) {
				*queen = { {game_color,Rook},{new_coordinates.x,new_coordinates.y} };
				if (halper.AreChacking(game_color)) {
					*queen = { {game_color,Queen},{coordinates.x,coordinates.y} };;
				}
			}
			else {
				vector<Figur>::iterator figur = halper.CheckCoordinates(new_coordinates);
				if ((*figur).piece.color != game_color) {
					Erase(figur);
					*queen = { {game_color,Queen},{new_coordinates.x,new_coordinates.y} };
					if (halper.AreChacking(game_color)) {
						*queen = { {game_color,Queen},{coordinates.x,coordinates.y} };
						NotErase(figur);
					}
				}
			}
		}
	}
}
void Logic::MoveKing(Coordinates coordinates, Coordinates new_coordinates) {
	vector<Figur>::iterator king = halper.CheckCoordinates(coordinates);
	if ((*king).piece.color == game_color) {
		if ((*halper.CheckCoordinates(new_coordinates)).piece.name == None) {
			if (halper.CanKingMove(king, new_coordinates)) {
				if (!halper.Check(king, new_coordinates))
					*king = { {game_color,King},{new_coordinates.x,new_coordinates.y} };
			}
			else if (CanKingCastling(king, new_coordinates)) {
				if (game_color) {
					if ((*king).coordinates.y - new_coordinates.y == 2) {
						vector<Figur>::iterator rook = halper.CheckCoordinates({ 0,0 });
						*rook = { {game_color,Rook},{0,2} };
						*king = { {game_color,King},{new_coordinates.x,new_coordinates.y} };
					}
					else if ((*king).coordinates.y - new_coordinates.y == -2) {
						vector<Figur>::iterator rook = halper.CheckCoordinates({ 0,7 });
						*rook = { {game_color,Rook},{0,4} };
						*king = { {game_color,King},{new_coordinates.x,new_coordinates.y} };
					}
				}
				else {
					if ((*king).coordinates.y - new_coordinates.y == 2) {
						vector<Figur>::iterator rook = halper.CheckCoordinates({ 7,0 });
						*rook = { {game_color,Rook},{7,2} };
						*king = { {game_color,King},{new_coordinates.x,new_coordinates.y} };
					}
					else if ((*king).coordinates.y - new_coordinates.y == -2) {
						vector<Figur>::iterator rook = halper.CheckCoordinates({ 7,7 });
						*rook = { {game_color,Rook},{7,4} };
						*king = { {game_color,King},{new_coordinates.x,new_coordinates.y} };
					}
				}
			}
		}
		else {
			vector<Figur>::iterator figur = halper.CheckCoordinates(new_coordinates);
			if (halper.CanKingMove(king, new_coordinates)) {
				if ((*figur).piece.color != game_color) {
					if (!halper.Check(king, new_coordinates)) {
						Erase(figur);
						*king = { {game_color,King},{new_coordinates.x,new_coordinates.y} };
					}
				}
			}
		}
	}
}
bool Logic::CanKingCastling(vector<Figur>::iterator king, Coordinates new_coordinates) {
	if ((*king).coordinates.x == 0 && (*king).coordinates.y == 3) {
		if ((*king).coordinates.y - new_coordinates.y == 2) {
			if ((*halper.CheckCoordinates({ 0,0 })).piece.name == Rook) {
				if ((*halper.CheckCoordinates({ 0,1 })).piece.name == None && (*halper.CheckCoordinates({ 0,2 })).piece.name == None) {
					for (int i = 0; i < 3; i++) {
						if (halper.Check(king, { (*king).coordinates.x,(*king).coordinates.y + i })) {
							return false;
						}
					}
					return true;
				}
			}
		}
		else if ((*king).coordinates.y - new_coordinates.y == -2) {
			if ((*halper.CheckCoordinates({ 0,7 })).piece.name == Rook) {
				if ((*halper.CheckCoordinates({ 0,4 })).piece.name == None && (*halper.CheckCoordinates({ 0,5 })).piece.name == None && (*halper.CheckCoordinates({ 0,6 })).piece.name == None) {
					for (int i = 0; i < 3; i++) {
						if (halper.Check(king, { (*king).coordinates.x,(*king).coordinates.y + i })) {
							return false;
						}
					}
					return true;
				}
			}
		}
	}
	else if ((*king).coordinates.x == 7 && (*king).coordinates.y == 3) {
		if ((*king).coordinates.y - new_coordinates.y == 2) {
			if ((*halper.CheckCoordinates({ 7,0 })).piece.name == Rook) {
				if ((*halper.CheckCoordinates({ 7,1 })).piece.name == None && (*halper.CheckCoordinates({ 7,2 })).piece.name == None) {
					for (int i = 0; i < 3; i++) {
						if (halper.Check(king, { (*king).coordinates.x,(*king).coordinates.y + i })) {
							return false;
						}
					}
					return true;
				}
			}
		}
		else if ((*king).coordinates.y - new_coordinates.y == -2) {
			if ((*halper.CheckCoordinates({ 7,7 })).piece.name == Rook) {
				if ((*halper.CheckCoordinates({ 7,4 })).piece.name == None && (*halper.CheckCoordinates({ 7,5 })).piece.name == None && (*halper.CheckCoordinates({ 7,6 })).piece.name == None) {
					for (int i = 0; i < 3; i++) {
						if (halper.Check(king, { (*king).coordinates.x,(*king).coordinates.y + i })) {
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