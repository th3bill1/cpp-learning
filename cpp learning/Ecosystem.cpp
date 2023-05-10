#include "Ecosystem.h"
#include <iostream>

int Ecosystem::isAnimalOrPlant(const std::string& s, int pos) const
{
    string animal = "animal";
    string plant = "plant";
    if (pos + 5 < s.length() && s[pos] == animal[0] && s[pos + 1] == animal[1] && s[pos + 2] == animal[2] && s[pos + 3] == animal[3] && s[pos + 4] == animal[4] && s[pos + 5] == animal[5]) {

        return pos + 6;
    }
    if (pos + 4 < s.length() && s[pos] == plant[0] && s[pos + 1] == plant[1] && s[pos + 2] == plant[2] && s[pos + 3] == plant[3] && s[pos + 4] == plant[4]) {
        return pos + 5;
    }
    return -1;
}

int Ecosystem::isSegment(const std::string& s, int pos) const
{
    int length = s.length();
    int j = pos;
    while (j < length && s[j] != ',') j++;
    if (j == pos) {
        return -1;
    }
    int _index = isAnimalOrPlant(s, j + 1);
    if (_index == -1 || _index > length || (_index < length && s[_index] != ':')) {
        return -1;
    }
    return _index;
}

void Ecosystem::clear()
{
    if (organisms != nullptr) {
        for (auto i = 0; i < count; i++) {
            delete organisms[i];
        }
        delete[] organisms;
        count = 0;
        organisms = nullptr;
    }
}

bool Ecosystem::validate(const std::string& s) const
{
    int i = 0;
    while (i < s.length()) {
        i = isSegment(s, i);
        if (i == -1 || i == s.length() - 1) {
            return false;
        }
        i++;
    }
    return true;
}


bool Ecosystem::initialize(const std::string& input)
{
    if (input.length() == 0) {
        return true;
    }
    if (!validate(input)) {
        return false;
    }

    int _index = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ':') {
            _index++;
        }
    }
    clear();
    count = _index + 1;
    organisms = new Organism * [count];

    int i = 0;
    int organism = 0;
    while (i < input.length()) {
        int _index = isSegment(input, i);
        if (input[_index - 1] == 'l') { 
            organisms[organism] = new Animal(input.substr(i, _index - i - 7));
        }
        else {
            organisms[organism] = new Plant(input.substr(i, _index - i - 6));
        }
        organism++;
        i = _index + 1;
    }
    return true;
}

unsigned int Ecosystem::countPlants() const
{
    if (organisms == nullptr) {
        return 0;
    }
    int animals_count = 0;
    for (int i = 0; i < count; i++) {
        if (dynamic_cast<Plant*>(organisms[i]) != nullptr) {
            animals_count++;
        }
    }
    return animals_count;
}

Ecosystem::~Ecosystem()
{
    if (organisms != nullptr) {
        for (auto i = 0; i < count; i++) {
            delete organisms[i];
        }
        delete[] organisms;
        count = 0;
        organisms = nullptr;
    }
}
