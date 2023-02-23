#include<iostream>
void Lab1(void);

using namespace std;

void PreLabInfo(int lab_num)
{
	string lab_heading = "---------------------------------------------------\n";
	cout << endl << lab_heading;
	cout << "\t\t\tLAB " << lab_num << endl;
	cout << lab_heading << endl;
}

bool LabChoosing(int lab_num)
{
	switch (lab_num)
	{
	case 1: 
		PreLabInfo(lab_num);
		Lab1();
		return false;
	default:
		cout << "There is no such lab!" << endl << endl;
		return true;
	}
}