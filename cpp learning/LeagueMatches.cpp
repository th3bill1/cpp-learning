#include "LeagueMatches.h"
#include "CollectionUtilities.h"

LeagueMatches::LeagueMatches(std::initializer_list<Match> matches) : matches(matches)
{
}

void LeagueMatches::clear()
{
	matches.clear();
}

void LeagueMatches::insert_after(const Match& match, int min_difference)
{
	auto begin = matches.begin();
	int i = 0;
	try
	{
		for (int i = 0; i < matches.size(); i++)
		{
			Match m = *begin;
			if (abs(m.team1_goals - m.team2_goals) >= min_difference)
			{
				advance(begin, 1);
				matches.insert(begin, match);
				i = 1;
				break;
			}
			advance(begin, 1);
		}
		if (i == 0) throw(std::logic_error("Logic error dude"));
	}
	catch (std::logic_error){}
}

void LeagueMatches::remove_last_first_n(int n)
{
	auto begin_n = matches.begin();
	advance(begin_n, n);
	matches.erase(matches.begin(),begin_n);
	auto end = matches.end();
	advance(end, -1);
	auto end_n = matches.end();
	advance(end_n, -n);
	matches.erase(end, end_n);
}

void LeagueMatches::merge(LeagueMatches& m)
{
	auto begin_m = m.matches.begin();
	int a = m.matches.size();
	for (int i = 0; i < a; i++)
	{
		matches.push_back(*begin_m);
		advance(begin_m, 1);
	}
}

void LeagueMatches::sort_matches()
{
	matches.sort();
}

void LeagueMatches::sort_matches(MatchComparator::OrderBy order)
{
	matches.sort(MatchComparator(order));
}

void LeagueMatches::change_location(Match match, std::string new_location)
{
	auto iterator = CollectionUtilities::find(matches.begin(), matches.end(), match);
	try
	{
		if (iterator != matches.end())
		{
			Match m = *iterator;
			m.location = new_location;
			*iterator = m;
		}
		else throw(std::out_of_range("OUT"));
	}
	catch(std::out_of_range){}
}

std::ostream& operator<<(std::ostream& out, const LeagueMatches& users)
{
	auto list = users.matches.begin();
	for (int i = 0; i < users.matches.size(); i++)
	{
		out << *list << std::endl;
		advance(list, 1);
	}
	return out;
}
