#pragma once

#include "Spell.h"

class ArcaneMissilesSpell : public Spell {
    static const int DAMAGE = 1;
    static const int MISSILES_COUNT = 3;

public:
    virtual void Cast(Character& caster, Character& target);
protected:
    virtual void Serialize(std::ostream& os) const;
};
