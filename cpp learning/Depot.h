#pragma once
#include <iostream>
#include "Tram.h"

const int MAX_TRAMS = 20;

using namespace std;

class Depot {

	Tram* atbase[MAX_TRAMS];
	int num;
	char depot_id[32];

public:
	Depot(const char*);

	void send_first();
	int atBase();

	friend void operator+=(Depot&, Tram);
	friend ostream& operator<<(ostream&, Depot);
};
