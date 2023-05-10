#pragma once
#include "Organism.h"
class Plant : public Organism
{

public:
	Plant(const std::string&);
	virtual string info() const;
};

