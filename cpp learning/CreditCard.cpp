#include <iostream>
#include "CreditCard.h"
#include <string.h>
#include <cctype>
#include <cstdlib>
using namespace std;

CreditCard::CreditCard(const char* card_number, const char* exp_date, int balance)
{
	int i = 0;
	int j = 0;
	while (i < 16)
	{
		if (isdigit(card_number[j]))
		{
			this->card_number[i] = card_number[j];
			i++;
		}
		j++;
	}
	this->card_number[16] = '\0';
	this->balance = balance;
	char month[3];
	month[2] = '\0';
	month[0] = exp_date[0];
	month[1] = exp_date[1];
	this->exp_month = atoi(month);
	char year[5];
	year[4] = '\0';
	year[0] = exp_date[3];
	year[1] = exp_date[4];
	year[2] = exp_date[5];
	year[3] = exp_date[6];
	this->exp_year = atoi(year);

	this->last_item[0] = ' ';
	this->last_item[1] = '\0';
}

CreditCard::CreditCard(const char* card_number, CreditCard c, int balance)
{
	int i = 0;
	int j = 0;
	while (i < 16)
	{
		if (isdigit(card_number[j]))
		{
			this->card_number[i] = card_number[j];
			i++;
		}
		j++;
	}
	this->card_number[16] = '\0';
	this->exp_month = c.exp_month;
	this->exp_year = c.exp_year;
	this->last_item[29] = '\0';
	for (int i = 0; i < strlen(c.last_item); i++)
	{
		this->last_item[i] = c.last_item[i];
	}
	this->last_item[strlen(c.last_item)] = '\0';
	this->balance = balance;
}

void CreditCard::operator+=(int i)
{
	this->exp_month += i;
	if (this->exp_month > 12)
	{
		int i = this->exp_month / 12;
		this->exp_month -= 12 * i;
		this->exp_year += i;
	}
}

void CreditCard::operator+=(CreditCard& c)
{
	if (c >= *this)
	{
		this->exp_month = c.exp_month;
		this->exp_year = c.exp_year;
	}
}

void CreditCard::BuyItem(const char* c)
{
	this->balance -= strlen(c);
	for (int i = 0; i < strlen(c); i++)
	{
		this->last_item[i] = c[i];
	}
	this->last_item[strlen(c)] = '\0';
}

void CreditCard::BuyItem(int i)
{
	for (int j = 0; j < i; j++)
	{
		this->BuyItem(this->last_item);
	}
}

ostream& operator<<(ostream& out, CreditCard& card)
{
	out << card.card_number << " - " << card.exp_month << "/" << card.exp_year << endl << "Balance: " << card.balance << endl << "Last bought item: " << card.last_item;
	return out;
}

istream& operator>>(istream& in, CreditCard& card)
{
	int n,m;
	cout << "Put month:";
	in >> n;
	cout << "Put year: ";
	in >> m;
	if (m > card.exp_year || (m == card.exp_year && n > card.exp_month))
	{
		card.exp_month = n;
		card.exp_year = m;
	}
	return in;
}

bool operator<(CreditCard& c1, CreditCard& c2)
{
	if (c1.exp_year < c2.exp_year) return true;
	if (c1.exp_year == c2.exp_year && c1.exp_month < c2.exp_month) return true;
	return false;
}

bool operator>=(CreditCard& c1, CreditCard& c2)
{
	if (c1.exp_year > c2.exp_year) return true;
	if (c1.exp_year == c2.exp_year)
	{
		if (c1.exp_month >= c2.exp_month) return true;
	}
	return false;
}

bool operator+=(CreditCard&, CreditCard&)
{
	return false;
}
