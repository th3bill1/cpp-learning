#pragma once

#include <iostream>
#include <initializer_list>
#include <set>
#include <vector>
#include "CollectionUtilities.h"

class UtilitiesTester {
public:

    static void test_find() {
        std::initializer_list<int> init = { 1, 2, 3, 4, 5 };

        std::set<int> S{ init };

        std::cout << "Set: ";
        for (auto el : S) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        auto result = CollectionUtilities::find(S.begin(), S.end(), 4);

        std::cout << "find 4: " << *result << std::endl;
    }

    static void test_all_of() {
        std::initializer_list<double> init = { 1, 2, 3, 4, 5 };
        auto predicate1 = [](double value) {return value > 0;};
        auto predicate2 = [](double value) {return value > 2.5;};

        bool result1 = CollectionUtilities::all_of(init.begin(), init.end(), predicate1);
        bool result2 = CollectionUtilities::all_of(init.begin(), init.end(), predicate2);

        std::cout << "All of x > 2.5: " << result2 << std::endl << "All of x > 0: " << result1;
    }
};