#include "Warlock.h"
#include "Spell.h"
#include "ArcaneMissilesSpell.h"
#include "HealingTouchSpell.h"

#include <iostream>

Warlock::Warlock(const std::string& name, int max_health_points, int spell_slots) : Character(name,max_health_points), spell_slots(spell_slots)
{
	spells = new Spell*[spell_slots];
	for (int i = 0; i < spell_slots; i++)
	{
		spells[i] = nullptr;
	}
	prepared_spells = 0;
}

void Warlock::Attack(Character& character)
{
	if (prepared_spells > 0)
	{
		spells[--prepared_spells]->Cast(*this, character);
		spells[prepared_spells] = nullptr;
	}
	else Character::Attack(character);
}

void Warlock::Rest(int hours)
{
	Character::Rest(hours);
	if (prepared_spells < spell_slots)
	{
		if (hours % 2 == 0)
		{
			spells[prepared_spells] = new ArcaneMissilesSpell();
		}
		else spells[prepared_spells] = new HealingTouchSpell();
		prepared_spells++;
	}
}

Character* Warlock::Clone()
{
	Warlock* new_w = new Warlock(name, max_health_points, spell_slots);
	for (int i = 0; i < spell_slots; i++)
	{
		if ((dynamic_cast<HealingTouchSpell*>(spells[i]) != nullptr))
		{
			new_w->spells[i] = new HealingTouchSpell();
			new_w->prepared_spells++;
		}
		else if ((dynamic_cast<ArcaneMissilesSpell*>(spells[i]) != nullptr))
		{
			new_w->spells[i] = new ArcaneMissilesSpell();
			new_w->prepared_spells++;
		}
		else new_w->spells[i] = nullptr;
	}
	return new_w;
}

void Warlock::Serialize(std::ostream& os) const
{
	os << name << " (HP: " << current_health_points << "/" << max_health_points << ")" << " - class: Warlock, prepared spells: ";
	for (int i = 0; i < prepared_spells; i++)
	{
		os << *spells[i] << " ";
	}
}
