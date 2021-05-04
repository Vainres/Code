// Diem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int sl;
	cin >> sl;
	int* ds = new int[sl];
	for (int i = 0;i < sl;i++) cin >> ds[i];
	
	int* dspoint = new int[sl];
	dspoint[0] = ds[0];

	for (int i = 1;i < sl;i++)
	{
		int max = dspoint[i - 1];
		for (int j = i-2;j > i - 6;j--)
		{
			if (j < 0) break;
			if (max < dspoint[j]) max = dspoint[j];
		}
		dspoint[i] = max+ds[i];
	}
	
	vector <int> print;
	int c = sl - 1;
	int k = dspoint[c];
	print.push_back(c);
	for (int i = sl - 1;i >= 0;i--)
	{
		if (dspoint[i] == k - ds[c])
		{
			print.push_back(i);
			k = dspoint[i];
			c = i;
		}
	}
	for (int i = print.size() - 1;i >= 0;i--) cout << print[i]+1 << " ";
	cout << endl<<dspoint[sl - 1];
}
// 13 23 -9 -5 -6 -7 45 -9 -88 -7 -4 -1 -2 -6
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
