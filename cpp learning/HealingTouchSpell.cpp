#include "HealingTouchSpell.h"
#include "Character.h"

void HealingTouchSpell::Cast(Character & caster, Character & target)
{
	caster.GetHealed(HEALING);
}

void HealingTouchSpell::Serialize(std::ostream& os) const
{
	os << "Healing Touch";
}