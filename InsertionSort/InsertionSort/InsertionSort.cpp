
#include <iostream>
using namespace std;
void InsertionSort(int a[],int siz)
{
	
	
	for (int i = 1;i < siz;i++)
	{
		int c=i;
		for (int j = i - 1;j > -1;j--)
		{
			if (a[j] < a[i]) c = j;
		}
		int f = a[i];
		for (int k = i;k >c;k--) a[k] = a[k - 1];
		a[c] = f;
		cout << "Vi tri chen cua a[" << i << "] la " << c<<endl;
		for (int i = 0;i < siz;i++)cout << a[i] << " ";
		cout << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	if (n != 0) {
		int* a = new int[n];
		for (int i = 0;i < n;i++)cin >> a[i];
		cout << "Mang truoc khi sap xep la: ";
		for (int i = 0;i < n;i++)cout << a[i] << " ";
		cout << endl;
		InsertionSort(a, n);
		cout << "Mang sau khi sap xep la: ";
		for (int i = 0;i < n;i++)cout << a[i] << " ";
	}
	else cout << "Mang rong.";
	return 0;
}
