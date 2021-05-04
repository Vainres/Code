// qhddaytang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
struct Chuoi
{
	int so;
	int dainhat=1;
};
using namespace std;
int main()
{
	string a;
	cin >> a;
	Chuoi* chuoi = new Chuoi[a.length()];
	for (int i = 0;i < a.length();i++)
	{
		chuoi[i].so = a[i] - 48;
	}
	for (int i = 0;i < a.length();i++)
	{
		for (int j = i;j > 0;j--)
		{
			if (chuoi[j].so <= chuoi[i].so && chuoi[j].dainhat >= chuoi[i].dainhat) chuoi[i].dainhat = chuoi[j].dainhat + 1;
		}

	}
	Chuoi b;
	b.dainhat = 1;
	b.so = 0;
	for (int i = 0;i < a.length();i++) if (chuoi[i].dainhat > b.dainhat) { b.dainhat = chuoi[i].dainhat;b.so = i; }
	vector <int> ds;
	ds.push_back(chuoi[b.so].so);

	for (int i = b.so;i >=0;i--)
	{
		if (chuoi[i].dainhat == b.dainhat - 1 && chuoi[i].so <= chuoi[b.so].so)
		{
			ds.push_back(chuoi[i].so);
			b.dainhat--;
			b.so = i;
		}
	}
	for (int i = ds.size() - 1;i >= 0;i--) cout << ds[i];



}
// 12536989162649136
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
