// quicksort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;
int Quicksort(int a[], int l, int r)
{
	int x = a[(r + l) / 2];
	int i = l;
	int j= r;
	while (i <= r)
	{
		while (a[i] < x) i++;
		while (a[r] > x) j--;
		if (i <=j)
		{
			swap(a[i],a[j]);
			i++;
			r--;
		}
	}
	a[(r+l)/2] = a[r];
	a[r] = x;
	return r;
}

void divine(int a[], int l, int r)
{
	for (int i = 0;i < 8;i++) cout << a[i]<< " " ;
	cout << endl;
	if (l < r)
	{
		int k = Quicksort(a, l, r);
		divine(a, l, k-1);
		divine(a, k + 1, r);
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0;i < n;i++)	cin >> a[i];
	divine(a, 0, n - 1);
	for (int i = 0;i < n;i++) cout << a[i] << " ";
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
