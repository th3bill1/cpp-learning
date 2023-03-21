#pragma once

#include "Tram.h"

const int MAX_TRAMS = 20;

class Depot {

	Tram* atbase[MAX_TRAMS];
	int num;
	char depot_id[32];

public:
	Depot();

	void operator+=(Depot t);
	void send_first();

};
