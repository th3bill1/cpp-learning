#ifndef _DICE_H
#define _DICE_H

#include <random>
#include <iostream>

using namespace std;

static const unsigned int SEED = 14321; //intentionally set to constant, for the same "random" results
static std::random_device rd;
static std::mt19937 rnd_generator(SEED);
unsigned int randomNumberFrom1ToX(unsigned int x);

class Dice {
public:
    enum class Color {
        red, yellow, orange, blue, green
    };
private:
    // use it to remember the number of the sides of the last created dice
    static unsigned int last_max_number;
    // current value of the dice
    unsigned int current_number;
    const int max_number;
    Color color;

public:
    unsigned int value() const { return current_number; }
    Dice(Color _color, int _max_number = last_max_number, int _current_number = 0);
    friend ostream& operator<<(ostream& os,Dice d);
    friend Dice& operator*(Dice& d);
    friend Dice operator-(Dice d1, Dice d2);
    friend Dice operator++(Dice d1);
};

#endif
