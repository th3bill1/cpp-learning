#include "MatchComparator.h"

bool MatchComparator::operator()(const Match& lhs, const Match& rhs)
{
    switch (this->order)
    {
    case OrderBy::TEAM1_LOCATION_ASCENDING:
        if (lhs.team1_goals < rhs.team1_goals) return true;
        else if (lhs.team1_goals == rhs.team1_goals && lhs.location.compare(rhs.location) < 0) return true;
        else return false;
    case OrderBy::TEAM2_LOCATION_DESCENDING:
        if (lhs.team2_goals > rhs.team2_goals) return true;
        else if (lhs.team2_goals == rhs.team2_goals && lhs.location.compare(rhs.location) > 0) return true;
        else return false;
    case OrderBy::SCORE_DIFF_ASCENDING:
        if (abs(lhs.team1_goals - lhs.team2_goals) < abs(rhs.team1_goals - rhs.team2_goals)) return true;
        else return false;
    case OrderBy::SCORE_DIFF_DESCENDING:
        if (abs(lhs.team1_goals - lhs.team2_goals) > abs(rhs.team1_goals - rhs.team2_goals)) return true;
        else return false;

    }
    
}
