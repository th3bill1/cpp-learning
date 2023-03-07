#include <iostream>
using namespace std;
#include <iomanip>
#include "date.h"

const int M = 12;	//number of months
static int dl[M] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
static string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
bool IsLeep(int);

bool& Date::SetFormat()
{
	return this->format;
}

ostream& operator<<(ostream& os, Date d)
{
	if (d.format == false) cout << d.day << '.' << d.month << '.' << d.year;
	else cout << months[d.month - 1] << ' ' << d.day << ',' << d.year;
	return os;
}

Date::Date(int a, int b)
{
	this->day = a;
	this->month = b;
	this->year = 2023;
	this->format = false;
}

Date::Date(const char* s)
{
	char day[3];
	memcpy(day, s, 2);
	day[2] = '\n';
	this->day = atoi(day);
	memcpy(day, s+3, 2);
	this->month = atoi(day);
	char year[5];
	memcpy(year, s + 6, 4);
	year[4] = '\n';
	this->year = atoi(year);
}

int Date::GetDay()
{
	return this->day;
}

int Date::GetMonth()
{
	return this->month;
}

int Date::GetYear()
{
	return this->year;
}

void Date::SetDay(int a)
{
	this->day = a;
}

void Date::SetMonth(int a)
{
	this->month = a;
}

void Date::SetYear(int a)
{
	this->year = a;
}

istream& operator>>(istream& in, Date& d)
{
	int year;
	cout << "Enter year: ";
	in >> year;
	if (!(year > 2000 && year <= 2100))
	{
		cout << "Wrong format!";
	}
	if (!IsLeep(d.year))
	{
		cout << "Enter month: ";
		in >> d.month;
		cout << "Enter day: ";
		in >> d.day;
	}
	else
	{

	}
	return in;
}

void Date::NextDay()
{
	this->day++;
}

void Date::PrevDay()
{
	this->day--;
}

void Date::SelectedDay(int n)
{
	this->day += n;
}

bool Date::ifEqual(Date n)
{
	if (this->day == n.day && this->month == n.month && this->year == n.year) return true;
	return false;
}

bool ifLess(Date n, Date m)
{
	if (m.year < n.year || (m.year == n.year && m.month < n.month) || (m.year == n.year && m.month == n.month && m.day < n.day)) return false;
	return true;
}

int NuberOfDays(Date m, Date n)
{
	if (m.ifEqual(n)) return 0;
	else return abs(m.day - n.day);
}

bool IsLeep(int a)
{
	if (a % 4 == 0) return true;
	return false;
}