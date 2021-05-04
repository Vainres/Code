// BALO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct time
{
	int batdau;
	int ketthuc;
};
int main()
{
	int sl;
	cin >> sl;
	time* ds = new time[sl];
	for (int i = 0;i < sl;i ++ ) cin >> ds[i].batdau >> ds[i].ketthuc;
	int* dskai = new int[24];
	for(int i=0;i<24;i++) dskai[i] = 0;
	for (int i = 1;i < 24;i++)
	{
		int max = dskai[i - 1];
		int dem = 0;
		for (int j = 0;j < sl;j++)
		{

			if (ds[j].ketthuc == i)
			{
				if (dskai[ds[j].batdau] + 1 > max) { max = dskai[ds[j].batdau] + 1;dem++; }
			}
		}
		cout << max<<" "<<i<<endl;
		if (dem == 0) dskai[i] = dskai[i - 1];
		else dskai[i] = max;
	}
	cout << dskai[23];

}
/*
11
7 11
2 4
1 3
2 3
4 9
14 20
5 8
6 9
10 12
3 5
8 9
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
