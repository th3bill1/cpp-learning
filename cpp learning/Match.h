#pragma once

#include <string>
#include <ostream>

struct Match {

    std::string location;
    int team1_goals;
    int team2_goals;

    Match(std::string location, int team1_goals, int teams2_goals) : location(location), team1_goals(team1_goals),
        team2_goals(teams2_goals) {}

    friend std::ostream& operator<<(std::ostream& os, const Match& match) {
        os << match.team1_goals << " - " << match.team2_goals << " (" << match.location << ")";
        return os;
    }

    bool operator==(const Match& rhs) const {
        return location == rhs.location && team1_goals == rhs.team1_goals && team2_goals == rhs.team2_goals;
    }

    bool operator<(const Match& rhs);
};