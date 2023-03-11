#include<iostream>
void Lab1();
void Lab2();
void Lab3();
void Lab4_d();

using namespace std;

void PreLabInfo(int lab_num)
{
	string lab_heading = "---------------------------------------------------\n";
	cout << endl << lab_heading;

	if (lab_num > 10) cout << "\t\tLAB " << lab_num/10 << " - drive";
	else cout << "\t\t\tLAB " << lab_num;
	cout << endl << lab_heading << endl;
}

bool LabChoosing(int lab_num)
{
	switch (lab_num)
	{
	case 1: 
		PreLabInfo(lab_num);
		Lab1();
		return false;
	case 2: 
		PreLabInfo(lab_num);
		Lab2();
		return false;
	case 3: 
		PreLabInfo(lab_num);
		Lab3();
		return false;
	case 40: 
		PreLabInfo(lab_num);
		Lab4_d();
		return false;
	default:
		cout << "There is no such lab!" << endl << endl;
		return true;
	}
}
