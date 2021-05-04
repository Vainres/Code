
#include <iostream>
#include <fstream>

#define maxCh 30
#define bookCount 3
#define forList(i) for(int i = 0; i < bookCount; i++)

	using namespace std;

void clrscr() // Xoa man hinh va dung man hinh lai cho den khi Enter
{
	cout << endl << "------------------------------ ";
	cout << endl << "nhan Enter de tiep tuc  ";
	cin.ignore();
	system("cls");
}

struct book_st
{
	char ten[maxCh] = "", theloai[maxCh] = "";
	int giatien = 0;
};

void printMenu()
{
	cout << " _M_E_N_U_______________________________________________________________________________ " << endl;
	cout << "| 1.  Nhap du lieu cua tung quyen sach.                                                   |" << endl;
	cout << "| 2.  Sap xep, thong ke va hien thi thong tin chi tiet cua tung quyen sach theo the loai. |" << endl;
	cout << "| 3.  Tim quyen sach theo the loai.                                                       |" << endl;
	cout << "| 4.  Ghi vao tap tin nhi phan book.dat                                                   |" << endl;
	cout << "| 5.  Thoat.                                                                              |" << endl;
	cout << "|___________________________________________________________________________________ktcn__|" << endl << endl;
}

void sort(book_st bookList[])
{
	for (int i = 0; i < bookCount - 1; i++)
		for (int j = i + 1; j < bookCount; j++)
			if (strcmp(bookList[j].ten, bookList[i].ten) == 1)
			{
				book_st p = bookList[i];
				bookList[i] = bookList[j];
				bookList[j] = p;
			}
}

void setline(ostream& out, int n) // in ky tu " " can chinh data
{
	for (int i = 0; i < maxCh - n; i++)
		out << " ";
}

ostream& operator << (ostream& out, const book_st& book) // toan tu xuat bookList(cout, out(ghi vao tep))
{
	out << "||" << book.ten;
	setline(out, strlen(book.ten));
	out << "||" << book.theloai;
	setline(out, strlen(book.theloai));
	out << "||" << book.giatien;
	return out;
}

ostream& operator << (ostream& out, book_st bookList[])
{
	out << "SST";
	out << "||" << "Ten"; setline(cout, 3);
	out << "||" << "The loai"; setline(cout, 8);
	out << "||Gia tien" << endl;
	forList(i)
		out << "00" << i + 1 << bookList[i] << endl;
	return out;
}

void search(book_st bookList[], char s[])
{
	bool kt = true;
	forList(i)
		if (strcmp(bookList[i].theloai, s) == 0)
		{
			cout << "00" << i + 1 << bookList[i] << endl;
			kt = false;
		}
	if (kt) cout << "Khong co quyen sach thuoc the loai nay";
}

int main()
{
	book_st bookList[bookCount];
	int action;
	do
	{
		// Nhap hanh dong (action)
		printMenu();
		cout << " Nhap action (1, 2, 3, 4, 5): ";
		cin >> action;
		clrscr();

		// Xu ly hanh dong
		if (action == 1)
		{
			forList(i)
			{
				cout << "Nhap quyen sach " << i + 1 << ":" << endl;
				cout << "Ten: "; cin.getline(bookList[i].ten, maxCh);
				cout << "The loai: "; cin.getline(bookList[i].theloai, maxCh);
				cout << "Gia tien: "; cin >> bookList[i].giatien;
				cout << endl;
				cin.ignore();
			}
			system("cls");
		}
		else if (action == 2)
		{
			sort(bookList);
			cout << bookList;
			clrscr();
		}
		else if (action == 3)
		{
			char theloaiSearch[maxCh];
			cout << "Nhap the loai: ";
			cin.getline(theloaiSearch, maxCh);
			search(bookList, theloaiSearch);
			clrscr();
		}
		else if (action == 4)
		{
			ofstream out;
			out.open("book.dat", ios::out);
			out << bookList;
			out.close();
			cout << "Successfull!" << endl;
			clrscr();
		}
	} while (action != 5);

	return 0;
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
