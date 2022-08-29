#pragma once
#include <vector>
#include <iostream>
#include "Board.h"
extern vector<Figur> none;
extern vector<Figur> White;
extern vector<Figur> Black;
extern Board figur[8];
class ConstructPieceList{
	
public:
	ConstructPieceList(){
		//if (none.empty())
		//	none.push_back({ {NULL,None},{NULL} });
		if (figur->piece.empty()) {
			for (int j = 0; j < 8; j++) {
				for (int i = 0; i < 8; i++) {
					switch (i)
					{
					case 0:
						switch (j)
						{
						case 0:
							figur[i].piece.push_back({ {true,Rook},{j,i} });
							break;
						case 1:
							figur[i].piece.push_back({ {true,Knight},{j,i} });
							break;
						case 2:
							figur[i].piece.push_back({ {true,Bishop},{j,i} });
							break;
						case 3:
							figur[i].piece.push_back({ {true,King},{j,i} });
							break;
						case 4:
							figur[i].piece.push_back({ {true,King},{j,i} });
							break;
						case 5:
							figur[i].piece.push_back({ {true,Bishop},{j,i} });
							break;
						case 6:
							figur[i].piece.push_back({ {true,Knight},{j,i} });
							break;
						case 7:
							figur[i].piece.push_back({ {true,Rook},{j,i} });
							break;
						}
					case 1:
						figur[i].piece.push_back({ {true,Pawn}, {j,i} });
						break;
					case 6:
						figur[i].piece.push_back({ {true,Pawn}, {j,i} });
						break;
					case 7:
						switch (j)
						{
						case 0:
							figur[i].piece.push_back({ {false,Rook},{j,i} });
							break;
						case 1:
							figur[i].piece.push_back({ {false,Knight},{j,i} });
							break;
						case 2:
							figur[i].piece.push_back({ {false,Bishop},{j,i} });
							break;
						case 3:
							figur[i].piece.push_back({ {false,King},{j,i} });
							break;
						case 4:
							figur[i].piece.push_back({ {false,King},{j,i} });
							break;
						case 5:
							figur[i].piece.push_back({ {false,Bishop},{j,i} });
							break;
						case 6:
							figur[i].piece.push_back({ {false,Knight},{j,i} });
							break;
						case 7:
							figur[i].piece.push_back({ {false,Rook},{j,i} });
							break;
						}
					default:
						figur[i].piece.push_back({ {NULL,None},{NULL} });
						break;
					}
				}
			}
		//	for (int i = 1, j = 1; i < 8; i++) {
		//		figur.piece.push_back({ { true,Pawn }, { j,i } });
		//	}
		//	for (int i = 1, j = 0, l = 0; l < 2; l++, i += 5) {
		//		White.push_back({ {true,Knight},{j,i} });
		//	}
		//	for (int i = 2, j = 0, l = 0; l < 2; l++, i += 3) {
		//		White.push_back({ {true,Bishop},{j,i} });
		//	}
		//	for (int i = 0, j = 0, l = 0; l < 2; l++, i += 7) {
		//		White.push_back({ {true,Rook},{j,i} });
		//	}
		//	White.push_back({ {true,Queen},{0,4} });
		//	White.push_back({ {true,King},{0,3} });
		//}
		//if (Black.empty()) {
		//	for (int i = 0, j = 6; i < 8; i++) {
		//		Black.push_back({ {false,Pawn},{j,i} });
		//	}
		//	for (int i = 1, j = 7, l = 0; l < 2; l++, i += 5) {
		//		Black.push_back({ {false,Knight},{j,i} });
		//	}
		//	for (int i = 2, j = 7, l = 0; l < 2; l++, i += 3) {
		//		Black.push_back({ {false,Bishop},{j,i} });
		//	}
		//	for (int i = 0, j = 7, l = 0; l < 2; l++, i += 7) {
		//		Black.push_back({ {false,Rook},{j,i} });
		//	}
		//	Black.push_back({ {false,Queen},{7,4} });
		//	Black.push_back({ {false,King},{7,3} });
		//}
		}
	}
	void output() {
		for (auto a = Black.begin(); a != Black.end(); a++) {
			cout << (*a).coordinates.x << (*a).coordinates.y << endl;
			cout << &(*a) << endl;
		}
	}
	void Erase(auto figur) {
		if (!(*figur).piece.color) {
			Black.erase(figur);
		}
		else {
			White.erase(figur);
		}
	}
	void NotErase(auto figur) {
		if ((*figur).piece.color) {
			Black.push_back(*figur);
		}
		else {
			White.push_back(*figur);
		}
	}
	~ConstructPieceList() {}
};