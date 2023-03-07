class Date
{
	int day;
	int month;
	int year;

	bool format;

	bool ifLeep() const;

public:
	bool& SetFormat();
	Date(int d = 9, int m = 3);
	Date(const char*);
	int GetDay();
	int GetMonth();
	int GetYear();
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	void NextDay();
	void PrevDay();
	void SelectedDay(int n = 7);
	bool ifEqual(Date);

	friend ostream& operator<<(ostream&, Date);
	friend istream& operator>>(istream&, Date&);
	friend bool ifLess(Date, Date);
	friend int NuberOfDays(Date, Date);
};
