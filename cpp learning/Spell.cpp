#include "Spell.h"

std::ostream& operator<<(std::ostream& os, const Spell& spell)
{
    spell.Serialize(os);
    return os;
}

void Serialize(std::ostream& os)
{
    os << "Spell";
}

void Cast(Character& caster, Character& target)
{

}