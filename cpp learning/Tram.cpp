#include "Tram.h"

using namespace std;

int Tram::no_in_use = 0;
int Tram::max_id = 0;

void Tram::returnDepot(char* c)
{
	for (int i = 0; i < min(NAME_SIZE, (int)strlen(c)); i++)
	{
		this->depot_name[i] = c[i];
	}
}

Tram::Tram(const char* c) : tram_id(++max_id), status(state::off), line_no(-1)
{
	this->depot_name[0] = '\0';
	for (int i = 0; i < min(NAME_SIZE,(int)strlen(c)); i++)
	{
		this->depot_name[i] = c[i];
	}
}

int Tram::getID()
{
	return this->tram_id;
}

char Tram::getState()
{
	return this->status;
}

void Tram::prepare(int no)
{
	this->status = state::ready;
	this->line_no = no;
}

void Tram::run()
{
	if (this->tram_id % 2 == 0) this->status = state::work;
	else this->status = state::failure;
	no_in_use++;
}

int Tram::getInUse()
{
	return no_in_use;
}

void check(Tram t)
{
	if (t.getState() == state::failure) t.returnDepot((char*)"Praga");
}

ostream& operator<<(ostream& os, Tram t)
{
	cout << "Tram " << t.tram_id;
	if (t.status == 'o') cout << " off";
	if (t.status == 'r') cout << " ready";
	if (t.status == 'w') cout << " working";
	if (t.status == 'f') cout << " failure";
	cout << " on line " << t.line_no;
	return os;
}
