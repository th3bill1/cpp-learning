#include "Depot.h"

Depot::Depot(const char* c)
{
	int max_index = min(NAME_SIZE, (int)strlen(c));
	for (int i = 0; i < max_index; i++)
	{
		this->depot_id[i] = c[i];
	}
	this->depot_id[max_index] = '\0';
	this->num = 0;
	this->atbase[0] = nullptr;
}

void Depot::send_first()
{
	if (this->num >= 1)
	{
		//cout << endl << this->atbase[this->num - 1];
		this->atbase[--this->num] = nullptr;
	}
	else cout << "Sorry, no trams avaliable";
}

int Depot::atBase()
{
	return this->num;
}

void operator+=(Depot& d, Tram t)
{
	d.atbase[d.num] = &t;
	d.num++;
}

ostream& operator<<(ostream& o, Depot d)
{
	for (int i = 0; i < d.num; i++)
	{
		o << "Tram " << i << ": " << *d.atbase[i] << endl;
	}
	return o;
}
