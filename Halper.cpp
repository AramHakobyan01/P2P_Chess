#include "Halper.h"
bool Halper::CanPawnMove(Coordinates coordinates, Coordinates new_coordinates) {
	if (coordinates.y == new_coordinates.y) {
		if (figur[coordinates.x][coordinates.y].color == true) {
			if (coordinates.x - new_coordinates.x == -1) {
				return true;
			}
			else if (coordinates.x - new_coordinates.x == -2) {
				
				if (coordinates.x == 1) {
					return true;
				}
			}
		}
		else {
			
			if (coordinates.x - new_coordinates.x == 1) {
				return true;
			}
			else if (coordinates.x - new_coordinates.x == 2) {
				if (coordinates.x == 6) {
					return true;
				}
			}
		}
	}
	return false;
}
bool Halper::CanPawnEat(Coordinates coordinates, Coordinates new_coordinates) {
	if (figur[new_coordinates.x][new_coordinates.y].name != None) {
		if (coordinates.x - new_coordinates.x == -1) {
			if (figur[coordinates.x][coordinates.y].color == true) {
				if (abs(coordinates.y - new_coordinates.y) == 1) {
					return true;
				}
			}
		}
		else if (coordinates.x - new_coordinates.x == 1) {
			if (figur[coordinates.x][coordinates.y].color == false) {
				if (abs(coordinates.y - new_coordinates.y) == 1) {
					return true;
				}
			}
		}
	}
	return false;
}
bool Halper::CanKnightMove(Coordinates coordinates, Coordinates new_coordinates) {
	if (abs(coordinates.x - new_coordinates.x) == 1) {
		if (abs(coordinates.y - new_coordinates.y) == 2)
			return true;
	}
	else if (abs(coordinates.x - new_coordinates.x) == 2) {
		if (abs(coordinates.y - new_coordinates.y) == 1)
			return true;
	}
	return false;
}
bool Halper::CanBishopMove(Coordinates coordinates, Coordinates new_coordinates) {
	if (abs(coordinates.x - new_coordinates.x) == abs(coordinates.y - new_coordinates.y)) {
		int count = 0;

		if (coordinates.x > new_coordinates.x) {
			if (coordinates.y > new_coordinates.y) {
				for (int i = coordinates.x - 1, j = coordinates.y - 1; i > new_coordinates.x; i--, j--) {
					if (figur[i][j].name != None) {
						count++;
						break;
					}
				}
			}
			else {
				for (int i = coordinates.x - 1, j = coordinates.y + 1; i > new_coordinates.x; i--, j++) {
					if (figur[i][j].name != None) {
						count++;
						break;
					}
				}
			}
		}
		else {
			if (coordinates.y > new_coordinates.y) {
				for (int i = coordinates.x + 1, j = coordinates.y - 1; i < new_coordinates.x; i++, j--) {
					if (figur[i][j].name != None) {
						count++;
						break;
					}
				}
			}
			else {
				for (int i = coordinates.x + 1, j = coordinates.y + 1; i < new_coordinates.x; i++, j++) {
					if (figur[i][j].name != None) {
						count++;
						break;
					}
				}
			}
		}
		if (count == 0)
			return true;
	}
	return false;
}
bool Halper::CanRookMove(Coordinates coordinates, Coordinates new_coordinates) {
	int count = 0;
	if (coordinates.y == new_coordinates.y) {
		if (coordinates.x > new_coordinates.x) {
			for (int i = coordinates.x - 1, j = coordinates.y; i > new_coordinates.x; i--) {
				if (figur[i][j].name != None) {
					count++;
					break;
				}
			}
		}
		else {
			for (int i = coordinates.x + 1, j = coordinates.y; i < new_coordinates.x; i++) {
				if (figur[i][j].name != None) {
					count++;
					break;
				}
			}
		}
	}
	else {
		if (coordinates.y > new_coordinates.y) {
			for (int i = coordinates.x, j = coordinates.y - 1; j > new_coordinates.y; j--) {
				if (figur[i][j].name != None) {
					count++;
					break;
				}
			}
		}
		else {
			for (int i = coordinates.x, j = coordinates.y + 1; j < new_coordinates.x; j++) {
				if (figur[i][j].name != None) {
					count++;
					break;
				}
			}
		}
	}
	if (count == 0)
		return true;
	else
		return false;
}
bool Halper::CanQueenMove(Coordinates coordinates, Coordinates new_coordinates) {
	if (CanBishopMove(coordinates, new_coordinates) || CanRookMove(coordinates, new_coordinates)) {
		return true;
	}
	else {
		return false;
	}
}
bool Halper::CanKingMove(Coordinates coordinates, Coordinates new_coordinates) {
	if (abs(coordinates.x - new_coordinates.x) == 1 && coordinates.y == new_coordinates.y) {
		return true;
	}
	else if (abs(coordinates.y - new_coordinates.y) == 1 && coordinates.x == new_coordinates.x) {
		return true;
	}
	else if (abs(coordinates.x - new_coordinates.x) == 1 && abs(coordinates.y - new_coordinates.y) == 1) {
		return true;
	}
	return false;
}
bool Halper::Check(Coordinates coordinates, Coordinates new_coordinates) {
	for (int i = new_coordinates.x + 1, j = new_coordinates.y; i < 8; i++) {
		Piece piece = figur[i][j];
		if (piece.name == Queen || piece.name == Rook) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
			else
				break;
		}
		else if (piece.name != None) {
			break;
		}
	}
	for (int i = new_coordinates.x - 1, j = new_coordinates.y; i >= 0; i--) {
		Piece piece = figur[i][j];
		if (piece.name == Queen || piece.name == Rook) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
			else
				break;
		}
		else if (piece.name != None) {
			break;
		}
	}
	for (int i = new_coordinates.x, j = new_coordinates.y + 1; j < 8; j++) {
		Piece piece = figur[i][j];
		if (piece.name == Queen || piece.name == Rook) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
			else
				break;
		}
		else if (piece.name != None) {
			break;
		}
	}
	for (int i = new_coordinates.x, j = new_coordinates.y - 1; j >= 0; j--) {
		Piece piece = figur[i][j];
		if (piece.name == Queen || piece.name == Rook) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
			else
				break;
		}
		else if (piece.name != None) {
			break;
		}
	}
	for (int i = new_coordinates.x - 1, j = new_coordinates.y - 1; j >= 0 && i >= 0; j--, i--) {
		Piece piece = figur[i][j];
		if (piece.name == Queen || piece.name == Bishop) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
			else
				break;
		}
		else if (piece.name != None) {
			break;
		}
	}
	for (int i = new_coordinates.x + 1, j = new_coordinates.y + 1; j < 8 && i < 8; j++, i++) {
		Piece piece = figur[i][j];
		if (piece.name == Queen || piece.name == Bishop) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
			else
				break;
		}
		else if (piece.name != None) {
			break;
		}
	}
	for (int i = new_coordinates.x + 1, j = new_coordinates.y - 1; j >= 0 && i < 8; j--, i++) {
		Piece piece = figur[i][j];
		if (piece.name == Queen || piece.name == Bishop) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
			else
				break;
		}
		else if (piece.name != None) {
			break;
		}
	}
	for (int i = new_coordinates.x - 1, j = new_coordinates.y + 1; i >= 0 && j < 8; j++, i--) {
		Piece piece = figur[i][j];
		if (piece.name == Queen || piece.name == Bishop) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) { 
				return true;
			}
			else
				break;
		}
		else if (piece.name != None) {
			break;
		}
	}
	if (new_coordinates.x + 2 < 8 && new_coordinates.x - 2 >= 0 && new_coordinates.y + 2 < 8 && new_coordinates.y - 2 >= 0) {
		Piece piece = figur[new_coordinates.x + 2][new_coordinates.y + 1];
		if (piece.name == Knight) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
		}
		piece = figur[new_coordinates.x + 2][new_coordinates.y - 1];
		if (piece.name == Knight) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
		}
		piece = figur[new_coordinates.x + 1][new_coordinates.y + 2];
		if (piece.name == Knight) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
		}
		piece = figur[new_coordinates.x + 1][new_coordinates.y - 2];
		if (piece.name == Knight) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
		}
		piece = figur[new_coordinates.x - 1][new_coordinates.y + 2];
		if (piece.name == Knight) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
		}
		piece = figur[new_coordinates.x - 1][new_coordinates.y - 2];
		if (piece.name == Knight) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
		}
		piece = figur[new_coordinates.x - 2][new_coordinates.y - 1];
		if (piece.name == Knight) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
		}
		piece = figur[new_coordinates.x - 2][new_coordinates.y + 1];
		if (piece.name == Knight) {
			if (piece.color != figur[coordinates.x][coordinates.y].color) {
				return true;
			}
		}
	}
	return false;
}
bool Halper::AreChacking(bool game_color) {
//	if (game_color) {
//		auto king = figur[0].begin();
//		for (; king != figur[0].end(); king++) {
//			if ((*king).piece.name == King) {
//				return Check(king, (*king).coordinates);
//			}
//		}
//	}
//	else {
//		auto king = figur[7].begin();
//		for (; king != figur[7].end(); king++) {
//			if ((*king).piece.name == King) {
//				return Check(king, (*king).coordinates);
//			}
//		}
//	}
	return false;

}
//vector<Coordinates> Halper::WhereCanMove(Coordinates coordinates, bool game_color) {
//	vector<Coordinates> move;
//	vector<Figur>::iterator figur = CheckCoordinates(coordinates);
//	vector<Figur>::iterator count;
//	switch ((*figur).piece.name)
//	{
//	case Pawn:
//		if (!AreChacking(game_color)) {
//			*figur = { {game_color,Pawn},{coordinates.x,coordinates.y + 1} };
//			if (!AreChacking(game_color)) {
//				*figur = { {game_color,Pawn},{coordinates.x,coordinates.y } };
//				if (game_color) {
//					for (int i = coordinates.x + 1, j = coordinates.y; i < coordinates.x + 3; i++) {
//						if (CanPawnMove(figur, { i,j }))
//							move.push_back({ i,j });
//					}
//					if (!(*CheckCoordinates({ coordinates.x + 1,coordinates.y + 1 })).piece.color) {
//						move.push_back({ coordinates.x + 1,coordinates.y + 1 });
//					}
//					else if (!(*CheckCoordinates({ coordinates.x + 1,coordinates.y - 1 })).piece.color) {
//						move.push_back({ coordinates.x + 1,coordinates.y - 1 });
//					}
//				}
//				else {
//					for (int i = coordinates.x - 1, j = coordinates.y; i > coordinates.x - 3; i--) {
//						if (CanPawnMove(figur, { i,j }))
//							move.push_back({ i,j });
//					}
//					if ((*CheckCoordinates({ coordinates.x - 1,coordinates.y + 1 })).piece.color) {
//						move.push_back({ coordinates.x - 1,coordinates.y + 1 });
//					}
//					else if ((*CheckCoordinates({ coordinates.x - 1,coordinates.y - 1 })).piece.color) {
//						move.push_back({ coordinates.x - 1,coordinates.y - 1 });
//					}
//				}
//			}
//		}
//		break;
//	case Knight:
//		count = CheckCoordinates({ coordinates.x + 2,coordinates.y + 1 });
//		if ((*count).piece.name == None) {
//			*figur = { {game_color,Knight},{coordinates.x + 2,coordinates.y + 1} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x + 2,coordinates.y + 1 });
//			}
//		}
//		else {
//			Erase(count);
//			*figur = { {game_color,Knight},{coordinates.x + 2,coordinates.y + 1} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x + 2,coordinates.y + 1 });
//			}
//			NotErase(count);
//		}
//		count = CheckCoordinates({ coordinates.x + 2,coordinates.y - 1 });
//		if ((*count).piece.name == None) {
//			*figur = { {game_color,Knight},{coordinates.x + 2,coordinates.y - 1} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x + 2,coordinates.y - 1 });
//			}
//		}
//		else {
//			Erase(count);
//			*figur = { {game_color,Knight},{coordinates.x + 2,coordinates.y - 1} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x + 2,coordinates.y - 1 });
//			}
//			NotErase(count);
//		}
//		count = CheckCoordinates({ coordinates.x + 1,coordinates.y + 2 });
//		if ((*count).piece.name == None) {
//			*figur = { {game_color,Knight},{coordinates.x + 1,coordinates.y + 2} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x + 1,coordinates.y + 2 });
//			}
//		}
//		else {
//			Erase(count);
//			*figur = { {game_color,Knight},{coordinates.x + 1,coordinates.y + 2} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x + 1,coordinates.y + 2 });
//			}
//			NotErase(count);
//		}
//		count = CheckCoordinates({ coordinates.x + 1,coordinates.y - 2 });
//		if ((*count).piece.name == None) {
//			*figur = { {game_color,Knight},{coordinates.x + 1,coordinates.y - 2} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x + 1,coordinates.y - 2 });
//			}
//		}
//		else {
//			Erase(count);
//			*figur = { {game_color,Knight},{coordinates.x + 1,coordinates.y - 2} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x + 1,coordinates.y - 2 });
//			}
//			NotErase(count);
//		}
//		count = CheckCoordinates({ coordinates.x - 1,coordinates.y - 2 });
//		if ((*count).piece.name == None) {
//			*figur = { {game_color,Knight},{coordinates.x - 1,coordinates.y - 2} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x - 1,coordinates.y - 2 });
//			}
//		}
//		else {
//			Erase(count);
//			*figur = { {game_color,Knight},{coordinates.x - 1,coordinates.y - 2} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x - 1,coordinates.y - 2 });
//			}
//			NotErase(count);
//		}
//		count = CheckCoordinates({ coordinates.x - 1,coordinates.y + 2 });
//		if ((*count).piece.name == None) {
//			*figur = { {game_color,Knight},{coordinates.x - 1,coordinates.y + 2} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x - 1,coordinates.y + 2 });
//			}
//		}
//		else {
//			Erase(count);
//			*figur = { {game_color,Knight},{coordinates.x - 1,coordinates.y + 2} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x - 1,coordinates.y + 2 });
//			}
//			NotErase(count);
//		}
//		count = CheckCoordinates({ coordinates.x - 2,coordinates.y - 1 });
//		if ((*count).piece.name == None) {
//			*figur = { {game_color,Knight},{coordinates.x - 2,coordinates.y - 1} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x - 2,coordinates.y - 1 });
//			}
//		}
//		else {
//			Erase(count);
//			*figur = { {game_color,Knight},{coordinates.x - 2,coordinates.y - 1} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x - 2,coordinates.y - 1 });
//			}
//			NotErase(count);
//		}
//		count = CheckCoordinates({ coordinates.x - 2,coordinates.y + 1 });
//		if ((*count).piece.name == None) {
//			*figur = { {game_color,Knight},{coordinates.x - 2,coordinates.y + 1} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x - 2,coordinates.y + 1 });
//			}
//		}
//		else {
//			Erase(count);
//			*figur = { {game_color,Knight},{coordinates.x - 2,coordinates.y + 1} };
//			if (!AreChacking(game_color)) {
//				move.push_back({ coordinates.x - 2,coordinates.y + 1 });
//			}
//			NotErase(count);
//		}
//		*figur = { {game_color,Knight},{coordinates.x ,coordinates.y } };
//		break;
//	case Bishop:
//		for (int i = coordinates.x + 1, j = coordinates.y + 1; i < 8; i++, j++) {
//			if (CanBishopMove(figur, { i,j })) {
//				*figur = { {game_color,Bishop},{i,j} };
//				if (!AreChacking(game_color)) {
//					move.push_back({ i,j });
//				}
//				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//			}
//			else {
//				count = CheckCoordinates({ i,j });
//				if ((*count).piece.color == (*figur).piece.color) {
//					break;
//				}
//				else {
//					Erase(count);
//					*figur = { {game_color,Bishop},{i,j} };
//					if (!AreChacking(game_color)) {
//						move.push_back({ i,j });
//					}
//					NotErase(count);
//					*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//				}
//			}
//		}
//		for (int i = coordinates.x + 1, j = coordinates.y - 1; i < 8; i++, j--) {
//			if (CanBishopMove(figur, { i,j })) {
//				*figur = { {game_color,Bishop},{i,j} };
//				if (!AreChacking(game_color)) {
//					move.push_back({ i,j });
//				}
//				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//			}
//			else {
//				count = CheckCoordinates({ i,j });
//				if ((*count).piece.color == (*figur).piece.color) {
//					break;
//				}
//				else {
//					Erase(count);
//					*figur = { {game_color,Bishop},{i,j} };
//					if (!AreChacking(game_color)) {
//						move.push_back({ i,j });
//					}
//					NotErase(count);
//					*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//				}
//			}
//		}
//		for (int i = coordinates.x - 1, j = coordinates.y + 1; j < 8; i--, j++) {
//			if (CanBishopMove(figur, { i,j })) {
//				*figur = { {game_color,Bishop},{i,j} };
//				if (!AreChacking(game_color)) {
//					move.push_back({ i,j });
//				}
//				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//			}
//			else {
//				count = CheckCoordinates({ i,j });
//				if ((*count).piece.color == (*figur).piece.color) {
//					break;
//				}
//				else {
//					Erase(count);
//					*figur = { {game_color,Bishop},{i,j} };
//					if (!AreChacking(game_color)) {
//						move.push_back({ i,j });
//					}
//					NotErase(count);
//					*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//				}
//			}
//		}
//		for (int i = coordinates.x - 1, j = coordinates.y - 1; i >= 0; i--, j--) {
//			if (CanBishopMove(figur, { i,j })) {
//				*figur = { {game_color,Bishop},{i,j} };
//				if (!AreChacking(game_color)) {
//					move.push_back({ i,j });
//				}
//				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//			}
//			else {
//				count = CheckCoordinates({ i,j });
//				if ((*count).piece.color == (*figur).piece.color) {
//					break;
//				}
//				else {
//					Erase(count);
//					*figur = { {game_color,Bishop},{i,j} };
//					if (!AreChacking(game_color)) {
//						move.push_back({ i,j });
//					}
//					NotErase(count);
//					*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//				}
//			}
//		}
//		break;
//	case Rook:
//		for (int i = coordinates.x + 1, j = coordinates.y; i < 8; i++) {
//			if (CanRookMove(figur, { i,j })) {
//				*figur = { {game_color,Rook},{i,j} };
//				if (!AreChacking(game_color)) {
//					move.push_back({ i,j });
//				}
//				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//			}
//			else {
//				count = CheckCoordinates({ i,j });
//				if ((*count).piece.color == (*figur).piece.color) {
//					break;
//				}
//				else {
//					Erase(count);
//					*figur = { {game_color,Rook},{i,j} };
//					if (!AreChacking(game_color)) {
//						move.push_back({ i,j });
//					}
//					NotErase(count);
//					*figur = { {game_color,Rook},{coordinates.x ,coordinates.y } };
//				}
//			}
//		}
//		for (int i = coordinates.x - 1, j = coordinates.y; i >= 0; i--) {
//			if (CanRookMove(figur, { i,j })) {
//				*figur = { {game_color,Rook},{i,j} };
//				if (!AreChacking(game_color)) {
//					move.push_back({ i,j });
//				}
//				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//			}
//			else {
//				count = CheckCoordinates({ i,j });
//				if ((*count).piece.color == (*figur).piece.color) {
//					break;
//				}
//				else {
//					Erase(count);
//					*figur = { {game_color,Rook},{i,j} };
//					if (!AreChacking(game_color)) {
//						move.push_back({ i,j });
//					}
//					NotErase(count);
//					*figur = { {game_color,Rook},{coordinates.x ,coordinates.y } };
//				}
//			}
//		}
//		for (int i = coordinates.x, j = coordinates.y + 1; j < 8; j++) {
//			if (CanRookMove(figur, { i,j })) {
//				*figur = { {game_color,Rook},{i,j} };
//				if (!AreChacking(game_color)) {
//					move.push_back({ i,j });
//				}
//				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//			}
//			else {
//				count = CheckCoordinates({ i,j });
//				if ((*count).piece.color == (*figur).piece.color) {
//					break;
//				}
//				else {
//					Erase(count);
//					*figur = { {game_color,Rook},{i,j} };
//					if (!AreChacking(game_color)) {
//						move.push_back({ i,j });
//					}
//					NotErase(count);
//					*figur = { {game_color,Rook},{coordinates.x ,coordinates.y } };
//				}
//			}
//		}
//		for (int i = coordinates.x, j = coordinates.y - 1; j >= 0; j--) {
//			if (CanRookMove(figur, { i,j })) {
//				*figur = { {game_color,Rook},{i,j} };
//				if (!AreChacking(game_color)) {
//					move.push_back({ i,j });
//				}
//				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
//			}
//			else {
//				count = CheckCoordinates({ i,j });
//				if ((*count).piece.color == (*figur).piece.color) {
//					break;
//				}
//				else {
//					Erase(count);
//					*figur = { {game_color,Rook},{i,j} };
//					if (!AreChacking(game_color)) {
//						move.push_back({ i,j });
//					}
//					NotErase(count);
//					*figur = { {game_color,Rook},{coordinates.x ,coordinates.y } };
//				}
//			}
//		}
//	case Queen:
//	case King:
//	default:
//		break;
//	}
//	return move;
//}