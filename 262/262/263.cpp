// 262.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void quickSort(int Data[], int l, int r)
{
	if (l <= r)
	{
		int key = Data[(l + r) / 2];
		int i = l;
		int j = r;
		while (i <= j)
		{
			while (Data[i] > key)
				i++;
			while (Data[j] < key)
				j--;

			if (i <= j)
			{
				swap(Data[i], Data[j]);
				i++;
				j--;
			}
		}
		if (l < j)
			quickSort(Data, l, j);
		if (r > i)
			quickSort(Data, i, r);
	}
}
void quickSort2(int Data[], int l, int r)
{
	if (l <= r)
	{
		int key = Data[(l + r) / 2];
		int i = l;
		int j = r;
		while (i <= j)
		{
			while (Data[i] > key)
				i++;
			while (Data[j] < key)
				j--;

			if (i <= j)
			{
				cout << i+1 << " " << j+1 << endl;
				swap(Data[i], Data[j]);
				i++;
				j--;
				
			}
		}
		if (l < j)
			quickSort2(Data, l, j);
		if (r > i)
			quickSort2(Data, i, r);
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0;i < n;i++)	cin >> a[i];
	for (int i = 0;i < n;i++) b[i] = a[i];
	cout << "Day truoc khi sap xep: ";
	for (int i = 0;i < n;i++) cout << a[i] << " ";
	quickSort(a, 0, n - 1);
	cout << endl;
	cout << "Day sau khi sap xep: ";
	for (int i = 0;i < n;i++) cout << a[i] << " ";
	cout << endl;
	cout << "Cac hoan vi duoc thuc hien trong Quick Sort:" << endl;
	quickSort2(b, 0, n - 1);



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
