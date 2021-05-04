
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
				if(i!=j) cout << i + 1 << " " << j + 1 << endl;
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