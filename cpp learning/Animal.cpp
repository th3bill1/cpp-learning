#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

Animal::Animal(const std::string& s) : Organism(s)
{
}

void Animal::info()
{
	cout << "An animal: ";
	Organism::info();
}

string Animal::sound()
{
	return "ssssss";
}
