#include <iostream>
#include "dice_tower.h"

void DiceTower::insert(Dice d)
{
	*d;
	if (this->dice[0] == nullptr) this->dice[0] = &d;
	else if (this->dice[1] == nullptr) this->dice[1] = &d;
	else
	{
		if (rand() % 3 == 0)
		{
			this->sum += this->dice[0]->value();
			this->dice[0] = &d;
		}
		else if (rand() % 3 == 0)
		{
			this->sum += this->dice[1]->value();
			this->dice[1] = &d;
		}
		else this->sum += d.value();
	}
}

int DiceTower::result()
{
	return this->sum;
}

void DiceTower::clear()
{
	this->sum = 0;
}

void DiceTower::reset()
{
	this->clear();
	this->dice[0] = nullptr;
	this->dice[1] = nullptr;
}
