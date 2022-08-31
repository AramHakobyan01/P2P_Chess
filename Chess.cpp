#include <iostream>
#include "Board.h"
using namespace std;

int main() {
	//Halper halper;
	Board logic;
	//ConstructPieceList a;
	//a.output();
	bool color = true;
	int x1, x2, y1, y2;
	string board[8][8] = { {"00","01","02","03","04","05","06","07"},
		{"10","11","12","13","14","15","16","17"},
		{"20","21","22","23","24","25","26","27"},
		{"30","31","32","33","34","35","36","37"},
		{"40","41","42","43","44","45","46","47"},
		{"50","51","52","53","54","55","56","57"},
		{"60","61","62","63","64","65","66","67"},
		{"70","71","72","73","74","75","76","77"},
	};
	while (1) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << board[i][j];
				// a = figur[i].begin();
				switch (figur[i][j].name)
				{
				case Pawn:
					cout << "p";
					break;
				case Knight:
					cout << "k";
					break;
				case Bishop:
					cout << "b";
					break;
				case Rook:
					cout << "r";
					break;
				case Queen:
					cout << "Q";
					break;
				case King:
					cout << "K";
					break;
				}
				//a++;
				cout << "  ";

			}
			cout << endl;
		}
		cout << "guyny" << color << endl;
		cin >> x1 >> y1 >> x2 >> y2;
		logic.Start({ x1,y1 }, { x2 ,y2 }, color);
		color = !color;
	}
	return 0;
}