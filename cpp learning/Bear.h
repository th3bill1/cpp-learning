#pragma once
#include "Animal.h"
class Bear : public Animal
{
public:
	Bear();
	string sound(bool is_aggressive);
	string sound();
};

