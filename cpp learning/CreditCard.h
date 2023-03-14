using namespace std;
class CreditCard
{
private:
	char card_number[17];
	int exp_month;
	int exp_year;
	int balance;
	char last_item[30];

public:
	CreditCard(const char* card_number, const char* exp_date, int balance = 100);
	CreditCard(const char* card_number, CreditCard, int balance = 100);

	friend ostream& operator<<(ostream& out, CreditCard& c);
	friend istream& operator>>(istream& in, CreditCard& c);
	friend bool operator<(CreditCard&, CreditCard&);
	friend bool operator>=(CreditCard&, CreditCard&);
	void operator+=(int);
	void operator+=(CreditCard&);
	void BuyItem(const char*);
	void BuyItem(int);
};