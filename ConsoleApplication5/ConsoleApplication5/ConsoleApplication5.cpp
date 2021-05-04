// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<math.h>
#include<string>
using namespace std;
struct HOCSINH
{
	string HOTEN;
	float TOAN;
	float VAN;
	float DTB = 0;
};
void NHAP(HOCSINH HS[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap ho va ten: ";
		cin >> HS[i].HOTEN;
		cout << " Nhap diem toan: ";
		cin >> HS[i].TOAN;
		cout << " Nhap diem van: ";
		cin >> HS[i].VAN;
		HS[i].DTB = (HS[i].TOAN + HS[i].VAN) / 2;
	}
}
void XUAT(HOCSINH HS[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Ho va ten hoc sinh thu" << " " << i+1 << "  :" << HS[i].HOTEN << endl;
		cout << " Diem toan: " << HS[i].TOAN << endl;
		cout << " Diem van: " << HS[i].VAN << endl;
	}
}
void XUATTHONGTIN(HOCSINH HS, int n)
{
	cout << " Ho va ten la: " << HS.HOTEN << endl;
	cout << " Diem toan: " << HS.TOAN << endl;
	cout << " Diem van: " << HS.VAN << endl;
}
HOCSINH DIEMMAX(HOCSINH HS[], int n)
{
	int t = 0;
	float max = (HS[1].TOAN + HS[1].VAN) / 2;
	for (int i = 1; i < n; i++)
	{
		if (HS[i].DTB > max)
		{
			max = HS[i].DTB;
			t = i;
		}
	}
	return HS[t];
}
HOCSINH DIEMMIN(HOCSINH HS[], int n)
{
	int t = 0;
	float max = (HS[0].TOAN + HS[0].VAN) / 2;
	for (int i = 1; i < n; i++)
	{
		if (HS[i].DTB < max)
		{
			max = HS[i].DTB;
			t = i;
		}
	}
	return HS[t];
}
int main()
{
	HOCSINH a[100], b, c;
	int n;
	cout << "Nhap so hoc sinh: ";
	cin >> n;
	NHAP(a, n);
	XUAT(a, n);
	cout << "Thong tin hoc sinh co diem trung binh cao nhat la: " << endl;
	b = DIEMMAX(a, n);
	XUATTHONGTIN(b, n);
	cout << "Thong tin hoc sinh co diem trung binh thap nhat la: " << endl;
	c = DIEMMIN(a, n);
	XUATTHONGTIN(c, n);
	return 0;
}


/*
3
luan1
7
8
luan2
7
7
luan3
1
2
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
