#pragma once

#include <iostream>
using namespace std;

const int NAME_SIZE = 16;

enum state { off = 'o', ready = 'r', work = 'w', failure = 'f'};

class Tram {
	static int no_in_use;
	static int max_id;
	char depot_name[NAME_SIZE];
	int	line_no;
	const int tram_id;
	state status;

public:

	Tram(const char*);
	void returnDepot(char*);
	static int getInUse();
	int getID();
	char getState();
	void prepare(int);
	void run();

	friend ostream& operator<<(ostream& os, Tram t);	
};
 void check(Tram);