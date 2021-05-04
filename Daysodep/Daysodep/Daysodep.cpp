// Daysodep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int sl, dem=0;
	unsigned long long S = 1;
	cin >> sl;
	for (int i = 2;i < sl;i++)
	{
		int demm = 0;
		for (int j = 2;j < i / 2;j++)
		{
			if (i % j == 0) demm++;
		}
		if (demm == 0) dem++;
	}

	for (int i = dem;i > 0;i--) { S=S*i%1000000007; }
	for (int i = sl - dem;i > 0;i--) {
		S=S*i%1000000007;
	}
	cout << S;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
