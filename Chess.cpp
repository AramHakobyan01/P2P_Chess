#include "Board.h"

#include <iostream>
#include <vector>

int main() {
	Board b;
	int x;
	int y;
	while (1) {
		std::cin >> x >> y;
		b.Start({ x,y });
	}
	return 0;
}