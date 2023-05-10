#pragma once

#include <ostream>
#include "Character.h"

class Spell;

class Warlock : public Character {

protected:
    Spell** spells;
    int spell_slots;
    int prepared_spells;
    void Serialize(std::ostream& os) const;

public:
    Warlock() = delete;
    Warlock(const Warlock& warlock) ;
    Warlock& operator=(const Warlock& warlock) = delete;

    Warlock(const std::string& name, int max_health_points, int spell_slots);

    void Attack(Character& character);
    void Rest(int hours);

public:

    Character* Clone();
    
};
