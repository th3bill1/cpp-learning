#include "pattern.h"
#include "card.h"

pattern::pattern(int sx, element el) : sx(sx), el(el)
{
}

void pattern::paint(card& c) const
{
	if (sx < 0 || sx >= c.size())
	{
		return;
	}
	for (size_t j = 0; j < c.size(); j++)
	{
		c(sx, j) = this->el;
	}
	c.egg();
}
