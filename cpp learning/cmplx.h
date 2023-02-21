class CMPLX
{
public:
	double Re;
	double Im;
public:
	void ReadC();
	double AbsC();
	void Print();
	void Init(double, double);
	void AddCA(CMPLX*, CMPLX*, CMPLX*, int);
};
