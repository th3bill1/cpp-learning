#include<iostream>
void Lab1();
void Lab2();
void Lab3();
void Lab3_d();
void Lab4_d();
void Lab4();
void Lab5();
void Lab6();
void Lab7();
void Lab8();
void Lab9();
void Lab10();
void Lab11();
void Lab13();
void Lab14();

using namespace std;

void PreLabInfo(int lab_num)
{
	string lab_heading = "---------------------------------------------------\n";
	cout << endl << lab_heading;

	if (lab_num % 10 == 0) cout << "\t\tLAB " << lab_num/10 << " - drive";
	if (lab_num % 2 ==0 && lab_num!=2 && lab_num % 10 != 0) cout << "\t\tLAB " << lab_num << " - graded";
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
	case 4: 
		PreLabInfo(lab_num);
		Lab4();
		return false;
	case 5: 
		PreLabInfo(lab_num);
		Lab5();
		return false;
	case 6: 
		PreLabInfo(lab_num);
		Lab6();
		return false;
	case 7:
		PreLabInfo(lab_num);
		Lab7();
		return false;
	case 8:
		PreLabInfo(lab_num);
		Lab8();
		return false;
	case 9:
		PreLabInfo(lab_num);
		Lab9();
		return false;
	case 10:
		PreLabInfo(lab_num);
		Lab10();
		return false;
	case 11:
		PreLabInfo(lab_num);
		Lab11();
		return false;
	case 13:
		PreLabInfo(lab_num);
		Lab13();
		return false;
	case 14:
		PreLabInfo(lab_num);
		Lab14();
		return false;
	case 30: 
		PreLabInfo(lab_num);
		Lab3_d();
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
