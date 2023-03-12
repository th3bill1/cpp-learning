#include <string>
#ifndef FLOAT_NUMBER_HEADER
#define FLOAT_NUMBER_HEADER
using namespace std;
static constexpr int MAX_DECIMAL_VALUE = 1000;

class FloatNumber
{
	int integerValue;
	int decimalValue;

public:
	/* ADD DECLARATION OF FLOATNUMBER'S CONSTRUCTORS HERE */
	FloatNumber(int i = 0, int d = 0);
	FloatNumber(float);
	FloatNumber(string);
	void WriteToConsole();
	void ReadFromConsole();

	/* ADD DECLARATION OF FLOATNUMBER'S METHODS HERE */


	/* YOU DON'T HAVE TO DECLARE YOURSELF THIS METHOD - JUST IMPLEMENT IT IN FLOATNUMBER.CPP FILE */
	bool Equals(const FloatNumber& other) const;

	/* YOU DON'T HAVE TO DECLARE YOURSELF THIS OPERATOR - JUST IMPLEMENT IT IN FLOATNUMBER.CPP FILE */
	friend FloatNumber operator + (const FloatNumber& floatA, const FloatNumber& floatB);
};

#endif /* FLOAT_NUMBER_HEADER */
