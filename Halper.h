#ifndef HALPER
#define HALPER

#include <vector>

#include "Figur.h"

class Halper
{
public:
	Halper(){}
	bool AreChacking(std::vector<std::vector<Figur*>> figur, Coordinates c, Coordinates new_c);
};
#endif HALPER