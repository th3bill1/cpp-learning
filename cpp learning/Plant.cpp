#include "Plant.h"
#include <iostream>

using namespace std;

Plant::Plant(const std::string& s) : Organism(s) {}

string Plant::info() const
{
	return "A plant: " + Organism::info();
}
