#include "Bear.h"

Bear::Bear() : Animal("Bear")
{
}

string Bear::sound(bool is_aggressive)
{
	if (is_aggressive == true) return "WRRRR";
	return "grrrr";
}

string Bear::sound()
{
	return Animal::sound();
}
