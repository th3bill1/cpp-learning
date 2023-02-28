class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int, int);
	void write();
	void read();
	int GetNum();
	int GetDen();
	void SetNum(int);
	void SetDen(int);
	void Shorten();
};
Fraction add(Fraction, Fraction);
ostream& operator<<(ostream&, Fraction);
istream& operator>>(istream&, Fraction&);

int gcd(int, int);