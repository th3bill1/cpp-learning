#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	Animal(const std::string&);
	void info();
	string sound();
};

