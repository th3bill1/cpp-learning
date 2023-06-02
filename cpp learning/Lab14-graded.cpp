#include <iostream>
#include <vector>
#include "CollectionUtilities.h"
#include "UtilitiesTester.h"
#include "Match.h"
#include "MatchComparator.h"
#include "LeagueMatches.h"

bool f(int i) {
    return i >= 5;
}

void Lab14()
{
    std::cout << "******************** PART 1 ********************\n\n";

    std::initializer_list<Match> matches_init{
            {"Madrid", 1, 0},
            {"Warsaw", 4, 2},
            {"Rome", 1, 1},
            {"Paris", 1, 7},
            {"Manchester", 3, 2},
    };

    LeagueMatches matches{matches_init};
    std::cout << matches << std::endl;

    LeagueMatches empty{matches_init};
    empty.clear();
    std::cout << empty << std::endl;

    std::cout << "******************** PART 2 ********************\n\n";

    matches.insert_after({"Berlin", 1, 1}, 5);
    matches.insert_after({"London", 0, 0}, 0);

    std::cout << matches << std::endl;

    try {
        matches.insert_after({"Test", 1, 1}, 999);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl << std::endl;
    }

    matches.remove_last_first_n(0);
    matches.remove_last_first_n(1);
    std::cout << matches << std::endl;

    std::initializer_list<Match> dummies{
            {"Dummy", 1, 5},
            {"Dummy", 5, 1},
            {"Dummy", 3, 3},
    };
    LeagueMatches d(dummies);

    matches.merge(d);
    std::cout << matches << std::endl;

    std::cout << "******************** PART 3 ********************\n\n";

    matches.sort_matches();
    std::cout << "Sorted (LOCATION_SCORE_DIFF_ASCENDING):" << std::endl;
    std::cout << matches << std::endl;

    std::cout << "******************** PART 4 ********************\n\n";

    matches.sort_matches(MatchComparator::OrderBy::TEAM2_LOCATION_DESCENDING);
    std::cout << "Sorted (TEAM2_LOCATION_DESCENDING):" << std::endl;
    std::cout << matches << std::endl;

    matches.sort_matches(MatchComparator::OrderBy::SCORE_DIFF_ASCENDING);
    std::cout << "Sorted (SCORE_DIFF_ASCENDING):" << std::endl;
    std::cout << matches << std::endl;

    std::cout << "******************** PART 5 ********************\n\n";

    std::cout << "Provided example: " << std::endl;
    UtilitiesTester::test_find();

    std::cout << std::endl;
    matches.change_location({ "Dummy", 1, 5 }, "Hamburg");
    try {
        matches.change_location({ "nonexistent", 123, 123 }, "new_location");
    }
    catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << matches << std::endl;

    std::cout << "******************** PART 6 ********************\n\n";

    UtilitiesTester::test_all_of();

    std::cout << "\n******************** PART 7 ********************\n\n";

    /*std::vector<int> v = {5, 2, 4, 5, 4, 7, 8, 10};

    std::cout << "Vector with values {5, 2, 4, 5, 4, 7, 8, 10}" << std::endl;
    auto cutoff = CollectionUtilities::order_if(v.begin(), v.end(), f);
    std::cout << "order if (val >= 5) all values: ";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "order if (val >= 5) filtered: ";
    for (auto it = v.begin(); it != cutoff; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;*/
}