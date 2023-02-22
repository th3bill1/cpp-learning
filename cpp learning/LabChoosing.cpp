#include<iostream>
void Lab1(void);

using namespace std;

void LabChoosing(int lab_num)
{
	string lab_heading = "\n---------------------------------------------------\n";
	cout << lab_heading;
	cout << "\t\t\tLAB "<<lab_num;
	cout << lab_heading << "\n";
	switch (lab_num)
		case 1: Lab1();
}