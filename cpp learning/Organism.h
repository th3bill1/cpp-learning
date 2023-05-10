#pragma once
#include <string>

using namespace std;

class Organism
{
private:
	string name;
	int id;
public:
	Organism(string s);
	~Organism();
	static int pop;
	static int id_count;
	int population() const;
	virtual string info() const;
	friend ostream& operator<<(std::ostream&, const Organism&);
};

