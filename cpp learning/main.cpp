#include <iostream>

using namespace std;

bool LabChoosing(int);
int main(void)
{
	bool is_active = true;
	while (is_active)
	{
		int lab_number;
		cout << "Put the number of Lab you want to see (#0 for labs from the drive, where # is the number of lab): ";
		cin >> lab_number;
		cout << endl;
		is_active = LabChoosing(lab_number);
	}
	return 0;
}