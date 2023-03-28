#include "dice.h"

unsigned int Dice::last_max_number = 4;
unsigned int randomNumberFrom1ToX(unsigned int x)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, x);
    return dist(rnd_generator);
}

ostream& operator<<(ostream& os, Dice d)
{
    if (d.color == Dice::Color::red) os << "red";
    if (d.color == Dice::Color::yellow) os << "yellow";
    if (d.color == Dice::Color::orange) os << "orange";
    if (d.color == Dice::Color::blue) os << "blue";
    if (d.color == Dice::Color::green) os << "green";

    os << " K" << d.max_number << " with " << d.current_number << " pips";
    return os;
}

Dice& operator*(Dice& d)
{
    d.current_number = randomNumberFrom1ToX(d.max_number);
    return d;
}

Dice operator-(Dice d1, Dice d2)
{
    Dice::Color c = d2.color;
    if (d1.color == Dice::Color::orange && d2.color == Dice::Color::yellow) c = Dice::Color::red;
    if (d1.color == Dice::Color::orange && d2.color == Dice::Color::red) c = Dice::Color::yellow;
    if (d1.color == Dice::Color::green && d2.color == Dice::Color::blue) c = Dice::Color::yellow;
    if (d1.color == Dice::Color::green && d2.color == Dice::Color::yellow) c = Dice::Color::blue;

    return Dice(c, max(d1.max_number, d2.max_number), max(d1.current_number, d2.current_number));
}

Dice operator++(Dice d1)
{
    d1.current_number++;
    if (d1.current_number > d1.max_number) d1.current_number = 1;
    return d1;
}

Dice::Dice(Color _color, int _max_number, int _current_number) : color(_color), max_number((_max_number!=0) ? _max_number : last_max_number), current_number(_current_number)
{
    if (this->current_number == 0) this->current_number = randomNumberFrom1ToX(this->max_number);
    if (this->current_number < 1) this->current_number = 1;
    if (this->current_number > this->max_number) this->current_number = this->max_number;
    last_max_number = this->max_number + 1;
}
