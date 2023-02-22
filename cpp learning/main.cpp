#include <iostream>

using namespace std;

void LabChoosing(int);
int main(void)
{
	int lab_number;
	cout << "put the number of Lab you want to see: ";
	cin >> lab_number;
	cout << "\n";
	LabChoosing(lab_number);
	return 0;
}