#pragma once

#include "Spell.h"

class HealingTouchSpell : public Spell {
    static const int HEALING = 8;

public:
    virtual void Cast(Character& caster, Character& target);
protected:
    virtual void Serialize(std::ostream& os) const;
};
