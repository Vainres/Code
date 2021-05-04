// cuochopB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct cuochop
{
	int batdau,ketthuc,quantrong;
	//cuochop(int a):batdau(a) {}
};

void Swapp(cuochop& a, cuochop& b)
{
	cuochop p=a;
	a.batdau = b.batdau;
	a.ketthuc = b.ketthuc;
	a.quantrong = b.quantrong;
	b.batdau = p.batdau;
	b.ketthuc = p.ketthuc;
	b.quantrong = p.quantrong;
}
int main()
{
	int sl;
	cin >> sl;
	cuochop* a=new cuochop[sl];
	for (int i = 0;i < sl;i++) cin >> a[i].batdau >> a[i].ketthuc >> a[i].quantrong;
	for (int i = 0;i < sl;i++)
	{
		int min = i;
		for (int j = i + 1;j < sl;j++)
		{
			if (a[min].ketthuc > a[j].ketthuc) min = j;
		}
		Swapp(a[i], a[min]);
	}
	//for (int i = 0;i < sl;i++) cout << a[i].ketthuc <<" ";
	int* dsquantrong = new int[sl];
	for (int i = 0;i < sl;i++)
	{
		int maxquantrong = 0;
		for (int j = i - 1;j >= 0;j--)
		{
			if (a[j].ketthuc <= a[i].batdau)
			{
				if (dsquantrong[j] > maxquantrong) maxquantrong = dsquantrong[j];
			}
		}
		dsquantrong[i] = a[i].quantrong + maxquantrong;
	}
	cout << endl;
	int k = dsquantrong[sl - 1];
	for (int i = sl-1;i >=0;i--)
	{
		if (dsquantrong[i] == k)
		{
			cout << a[i].batdau << " " << a[i].ketthuc << " " << a[i].quantrong <<" "<<dsquantrong[i]<< endl;
			k -= a[i].quantrong;
		}
	}
}
/*
11
7 11 5
2 4 6
1 3 9
2 3 1
4 9 3
14 20 12
5 8 4
6 9 8
10 12 6
3 5 5
8 9 3
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
