// TienViet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;
int n;
void Nhap(int a[])
{
	
	for (int i = 0;i < n;i++)
	{
		cout << "Nhap phan tu thu " << i + 1<<":";
		cin >> a[i];
	}
}
void Xuat(int a[])
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		if ((i + 1) % 10 == 0) cout << endl;
	}
	cout << endl;
}
void Timlonnho(int a[])
{
	int f = a[0];
	int c = a[0];
	for (int i = 1;i < n;i++)
	{
		if (a[i] > f) f = a[i];
	}
	for (int i = 1;i < n;i++)
	{
		if (a[i] < c) c = a[i];
	}

}

int Tong(int a[])
{
	int S = 0;
	for (int i = 0;i < n;i++) S += a[i];
	return S;
}

double TrungbinhCong(int S) { return S*1.0 / n; }

double TrungbinhNhan(int a[])
{
	long double S=1;
	for (int i = 0;i < n;i++) S *= a[i];
	return pow(S, 1.0 / n);
}

void Timkiem(int a[])
{
	int x,dem=0;
	cout << "Nhap x can tim :";
	cin >> x;
	for (int i = 0;i < n;i++)
	{
		if (a[i]==x)
		{
			cout << "x o vi tri :" << i+1 << endl;
			dem++;
		}
	}
	if (dem == 0) cout << "Deo co x";
}

void SapxepTang(int a[])
{
	for (int i = 0;i < n;i++)
	{
		int f = a[i];
		for (int k = i;k < n;k++)
		{
			if (f > a[k])
			{
				f = a[i];
				a[i] = a[k];
				a[k] = f;
			}
		}
	}
}

void SapxepGiam(int a[])
{
	for (int i = 0;i < n;i++)
	{
		int f = a[i];
		for (int k = i;k < n;k++)
		{
			if (f < a[k])
			{
				f = a[i];
				a[i] = a[k];
				a[k] = f;
			}
		}
	}
}
void XuatNguoc(int a[])
{
	for (int i = n - 1;i >= 0;i--) cout << a[i] << " ";
	cout << endl;
}

void ThemPhantu(int a[])
{
	cout << "Them phan tu " << endl;
	int x, k;
	v:cout << "Nhap x :";
	cin >> x;
	cout << "Nhap vi tri k :";
	cin >> k;
	if (k > n)
	{
		cout << "Nhap ngu lz an cc";
		goto v;
	}
	for (int i = n;i >=k;i--) a[i + 1] = a[i];
	a[k] = x;
	n++;
}

void XoaPhantu(int a[])
{
	cout << "Xoa phan tu" << endl;
	int x, k;
	v:cout << "Nhap vi tri k :";
	cin >> k;
	if (k > n)
	{
		cout << "Nhap ngu lz an cc";
		goto v;
	}
	for (int i = k;i < n;i++) a[i] = a[i+1];
	n--;
}

void DemphantuDuong(int a[])
{
	int dem = 0, S = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] > 0)
		{
			dem++;
			S += a[i];
		}
	}
	cout << "So phan tu duong :" << dem << endl;
	cout << "Tong phan tu duong :" << S << endl;
}

int Min(int a[])
{
	int f = a[0];
	for (int i = 1;i < n;i++) if (f > a[i]&&a[i]>0) f = a[i];
	return f;
}
int main()
{
	int a[100];
    cout << "Hello World!\n";
	cout << "Nhap n :";
	cin >> n;
	Nhap(a);
	Xuat(a);
	cout << "Phan tu duong nho nhat :" << Min(a)<<endl;
	cout << "Tong cua mang :" << Tong(a) << endl;
	cout << "Trung binh cong :" << TrungbinhCong(Tong(a)) << endl;
	cout << "Trung binh Nhan :" << TrungbinhNhan(a) << endl;
	Timkiem(a);
	cout << "Sap xep Tang :";
	SapxepTang(a);
	Xuat(a);
	cout << "Sap xep Giam :";
	SapxepGiam(a);
	Xuat(a);
	cout << "Xuat nguoc :";
	XuatNguoc(a);
	ThemPhantu(a);
	Xuat(a);
	XoaPhantu(a);
	Xuat(a);
	DemphantuDuong(a);
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

