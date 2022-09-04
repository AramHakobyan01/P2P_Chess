#ifndef _Halper_
#define _Halper_
#include "Figur.h"
#include <vector>
class Halper
{
public:
	Halper(){}
	bool AreChacking(std::vector<std::vector<Figur*>> figur, Coordinates c, Coordinates new_c);
};
#endif _Halper_