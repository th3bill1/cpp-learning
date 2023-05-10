#include "Warrior.h"

Warrior::Warrior(const std::string& name, int max_health_points, int shield_durability) : Character(name, max_health_points), shield_durability(shield_durability)
{
}

void Warrior::Attack(Character& character)
{
	if (dynamic_cast<Warrior*>(&character) != nullptr)
	{
		Warrior* enemy = dynamic_cast<Warrior*>(&character);
		while (enemy->shield_durability > 0) Character::Attack(character);
	}
	Character::Attack(character);
}

void Warrior::Rest(int hours)
{
	max_health_points++;
	Character::Rest(hours);
}

void Warrior::TakeDamage(int damage)
{
	if (shield_durability > 0) shield_durability--;
	else Character::TakeDamage(damage);
}

void Warrior::GetHealed(int heal)
{
	Character::GetHealed(heal);
}

void Warrior::Serialize(std::ostream& os) const
{
	os << name << " (HP: " << current_health_points << "/" << max_health_points << ")" << " - class: Warrior (" << shield_durability << ")";
}
