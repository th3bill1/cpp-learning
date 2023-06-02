#pragma once

#include "Match.h"

class MatchComparator {
public:
    enum class OrderBy {
        TEAM1_LOCATION_ASCENDING,
        TEAM2_LOCATION_DESCENDING,
        SCORE_DIFF_ASCENDING,
        SCORE_DIFF_DESCENDING,
    };
    MatchComparator(OrderBy order) : order(order) {};
    bool operator()(const Match& lhs, const Match& rhs);
private:
    OrderBy order;
};
