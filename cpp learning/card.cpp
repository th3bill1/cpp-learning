#include <iostream>
using namespace std;
#include "card.h"
#include "pattern.h"

void card::init(int _m, element el, element* tab)
{
	this->t = new (nothrow) element[_m * _m];
	if (this->t == nullptr)
	{
		this->m = 0;
	}
	else
	{
		if (tab == nullptr)
		{
			for (int i = 0; i < _m * _m; i++)
			{
				this->t[i] = el;
			}
		}
		else
		{
			for (int i = 0; i < _m * _m; i++)
			{
				this->t[i] = tab[i];
			}
		}
		this->m = _m;
	}
}

card::card(int m, element el)
{
	this->init(m, el, nullptr);
}

card::card(const card& k)
{
	this->init(k.m, NULL, k.t);
}

card& card::operator=(const card& c)
{
	if (this->t != c.t)
	{
		delete this->t;
		this->init(c.m, NULL, c.t);	
	}
	return *this;
}

int card::size() const
{
	return this->m;
}

element card::operator()(int i, int j) const
{
	return this->t[i*this->m+j];
}

element& card::operator()(int i, int j)
{
	return this->t[i * this->m + j];
}

card& card::operator+=(const pattern& g)
{
	g.paint(*this);
	return *this;
}

void card::egg(element el)
{
	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->m; i++)
		{
			if (pow(i - (m / 2), 2) + pow(j - (m / 2), 2) < m / 2 - 1)
			{
				this->t[i*this->m+j] = el;
			}
		}
	}
}

ostream& operator<<(ostream& out, const card& k)
{
	for (int i = 0; i < k.m; i++)
	{
		for (int j = 0; j < k.m; j++)
		{
			out << k.t[i * k.m + j];
		}
		out << endl;
	}
	return out;
}
