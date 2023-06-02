#include "Match.h"

bool Match::operator<(const Match& rhs)
{
    if (location.compare(rhs.location) < 0) return true;
    else if (location.compare(rhs.location) == 0 && abs(team1_goals - team2_goals) < abs(rhs.team1_goals - rhs.team2_goals)) return true;
    return false;
}
