#include "Organism.h"
#include <iostream>

using namespace std;

int Organism::pop = 0;
int Organism::id_count = 0;

Organism::Organism(string s)
{
	this->name = s;
	pop++;
	id_count++;
	this->id = id_count;
}

Organism::~Organism()
{
	pop--;
}

int Organism::population() const
{
	return pop;
}

string Organism::info() const
{
	return name + " id:" + to_string(id) + " population: " + to_string(population()) + "";
}

ostream& operator<<(ostream& os, const Organism& o) 
{
	os << o.info();
	return os;
}
