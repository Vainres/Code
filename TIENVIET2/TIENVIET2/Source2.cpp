// TIENVIET2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
struct book_st
{
	char ten[30];
	char theloai[30];
	int giatien;
};
void XY(char a[30], char b[30])
{
	for (int i = 0; i < 30; i++)
	{
		a[i] = b[i];
	}
}
void XZ(char a[30], string b)
{
	for (int i = 0; i < b.length(); i++)
	{
		a[i] = b[i];
	}
}
void Nhap(book_st a[],char b)
{
	cin.ignore();
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Nhap quyen sach " << i + 1 << ":" << endl;
		cout << "Ten: "; 
		cin.getline(a[i].ten, 30);
		cout << "The loai: "; 
		cin.getline(a[i].theloai, 30);
		cout << "Gia tien: "; 
		cin >> a[i].giatien;
		cin.ignore();
	}
}
void Thongketheloai(book_st a[])
{
	int dem = 1;
	for (int i = 1;i < 3;i++)
	{
		
		if (strcmp(a[i - 1].theloai, a[i].theloai) != 0)
		{
			cout << a[i - 1].theloai << " co " << dem << endl;
			dem = 0;
		}
		dem++;
	}
	cout << a[2].theloai << " co " << dem << endl;
}
void Thongke(book_st a[],char b,int i)
{
		int k = 0;
		cout << "00" << i + 1<<"||";
		while (a[i].ten[k]!= b)
		{
			cout << a[i].ten[k];
			k++;
		}
		cout << setw(30 - k) << "||";
		k=0;
		while (a[i].theloai[k]!= b)
		{
			cout << a[i].theloai[k];
			k++;
		}
		cout << setw(30 - k) << "||"<<a[i].giatien << endl;
}
void Timkiem(book_st a[],char b)
{
	cin.ignore();
	char c[30];
	bool kt = false;
	cout << "Nhap the loai :";
	cin.getline(c, 30);
	for (int i = 0;i < 3;i++)
	{
		if (strcmp(c, a[i].theloai) == 0)
		{
			if(kt==false) cout << "STT||Ten                         ||The loai                    ||Gia tien" << endl;
			Thongke(a, b, i);
				kt=true;
		}
	}
	if(kt==false) cout << "Khong co the loai\n";
	cin.ignore();
}
void Sapxep(book_st a[],char b)
{
	for (int i = 0; i < 3 - 1; i++)
		for (int j = i + 1; j < 3; j++)
			if (strcmp(a[j].theloai, a[i].theloai) == 1)
			{
				book_st p = a[i];
				a[i] = a[j];
				a[j] = p;
			}
	cout << "STT||Ten                         ||The loai                    ||Gia tien" << endl;
	for (int i = 0;i < 3;i++)
	{
		Thongke(a, b, i);
	}
	Thongketheloai(a);
}
int Menu(book_st a[],char b)
{
	while (true)
	{
		int f;
		cout << "1.Nhap du lieu cua tung quyen sach.\n";
		cout << "2.Sap xep,thong ke va hien thi thong tin chi tiet cua tung quyen sach theo the loai (Z-A).\n";
		cout << "3.Tim quyen sach theo the loai.\n";
		cout << "4.Ghi vao tap tin nhi phan book.dat.\n";
		cout << "5.Thoat.\n";
		cin >> f;
		if (f == 1) Nhap(a,b);
		if (f == 2) Sapxep(a, b);
		if (f == 3) Timkiem(a, b);
		cin.ignore();
		if (f == 4)
		{
			fstream infile;
			infile.open("book.dat", ios::out);
			string c = "STT||Ten                         ||The loai                    ||Gia tien";
			infile << c << endl;
			
			for (int i = 0;i < 3;i++)
			{
				int k = 0;
				infile << "00" << i + 1 << "||";
				while (a[i].ten[k] != b)
				{
					infile << a[i].ten[k];
					k++;
				}
				infile << setw(30 - k) << "||";
				k = 0;
				while (a[i].theloai[k] != b)
				{
					infile << a[i].theloai[k];
					k++;
				}
				infile << setw(30 - k) << "||" << a[i].giatien << endl;
			}
		}
		if (f == 5) return 0;
	}
}
int main()
{
	book_st *booklist = new book_st[3];
	char b = booklist[1].ten[3];
	Menu(booklist, b);

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
