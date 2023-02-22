class CMPLX
{
private:
	void SwapCMPLX(int, int);
public:
	double Re;
	double Im;
public:
	void ReadC();
	double AbsC();
	void Print();
	void Init(double, double);
	void AddCA(CMPLX*, CMPLX*, int);
	CMPLX AddC(CMPLX);
	void PrintCarr(int);
	double* ArrOfAbs(int);
	void PrintTabOfAbs(int);
	void SortArray(int);
};
