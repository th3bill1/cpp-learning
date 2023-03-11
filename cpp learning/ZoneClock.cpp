#include <iostream>
using namespace std;
#include "ZoneClock.h"

int ZoneClock::clock_number = 1;
int ZoneClock::part5 = 0;

ZoneClock::ZoneClock(int hour, int min, clock_period period)
{
	this->hour = hour;
	this->min = min;
	this->period = period;
	if (clock_number % 3 == 0) this->format = false;
	else this->format = true;
	clock_number++;
}

void ZoneClock::add_minute()
{
	this->min++;
	if (this->min == 60)
	{
		this->min = 0;
		this->hour++;
		if (this->hour == 12)
		{
			if (this->period == clock_period::am) this->period = clock_period::pm;
			else if (this->period == clock_period::pm) this->period = clock_period::am;
		}
		if (this->hour == 13) this->hour = 1;
	}
}

void ZoneClock::add_minutes(int minutes)
{
	for (int i = 0; i < minutes; i++) this->add_minute();
}

void ZoneClock::subtract_minute()
{
	this->min--;
	if (this->min == -1)
	{
		this->min = 59;
		this->hour--;
		if (this->hour == 11)
		{
			if (this->period == clock_period::am) this->period = clock_period::pm;
			else if (this->period == clock_period::pm) this->period = clock_period::am;
		}
		if (this->hour == 0) this->hour = 12;
	}
}

void ZoneClock::subtract_minutes(int minutes)
{
	for (int i = 0; i < minutes; i++) this->subtract_minute();
}

void ZoneClock::set_time_zone(const time_zone& tz)
{
	int hours = ((int)tz - (int)this->zone);
	if (hours >= 0) this->add_minutes(hours * 60);
	else this->subtract_minutes(abs(hours) * 60);
	this->zone = tz;
}

std::ostream& operator<<(std::ostream& out, const ZoneClock& c)
{
	int hour = c.hour;
	if (c.period == clock_period::am && c.format == false && c.hour == 12) hour = 0;
	if (c.period == clock_period::pm && c.format == false && c.hour != 12) hour += 12;
	if (hour < 10) out << '0';
	if (c.format == true)
	{
		out << hour << ':';
		if (c.min < 10) out << '0';
		out << c.min;
		if (c.period == clock_period::am) out<< "am";
		else out << "pm";
	}
	else
	{
		out << hour << ':';
		if (c.min < 10) out << '0';
		out << c.min;
	}
	if (ZoneClock::part5 == 1)
	{
		out << " UTC + ";
		if ((c.zone == time_zone::CET)) out << '1';
		else if ((c.zone == time_zone::EET)) out << '2';
		else out << '0';
	}
	out << endl;
	return out;
}

std::istream& operator>>(std::istream& in, ZoneClock& c)
{
	bool is_proper = false;
	int hour, min;
	string period;
	while (!is_proper)
	{
		cout <<"Enter hour:";
		in >> hour;
		cout << "Enter minutes:";
		in >> min;
		cout << "Enter (am/pm):";
		cin >> period;
		if (hour >= 0 && hour <= 12 && min >= 0 && min <= 60 && (period == "am" || period == "pm")) is_proper = true;
		else cout << "Wrong time!!" << endl;
		c.hour = hour;
		c.min = min;
		if (period == "am") c.period = clock_period::am;
		if (period == "pm") c.period = clock_period::pm;
	}
	return in;
}
