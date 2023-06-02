#pragma once

#include <list>
#include "Match.h"
#include "MatchComparator.h"

class LeagueMatches {
private:
    std::list<Match> matches;

public:
    // PART 1
    LeagueMatches(std::initializer_list<Match> matches);
    void clear();
    friend std::ostream& operator<<(std::ostream& out, const LeagueMatches& users);

    //PART 2
    void insert_after(const Match& match, int min_difference);
    void remove_last_first_n(int n);
    void merge(LeagueMatches& matches);

    // PART 3
    void sort_matches();

    // PART 4
    void sort_matches(MatchComparator::OrderBy order);

    // PART 5
    void change_location(Match match, std::string new_location);
};
