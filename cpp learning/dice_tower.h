#ifndef _DICE_TOWER_H
#define _DICE_TOWER_H

#include "dice.h"

class DiceTower
{
	Dice* dice[2] = {nullptr, nullptr};
	int sum = 0;
public:
	void insert(Dice d);
	int result();
	void clear();
	void reset();
};

#endif
