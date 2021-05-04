#include<iostream>
#include<string>
using namespace std;
struct Sinhvien
{
	int MSSV;
	string Hoten;
	int Namsinh;
	int Gioitinh;
	float DiemTB;
};
typedef struct Node
{
	Sinhvien data;
	Node* next;
	Node* pre;
}Node;
typedef struct list
{
	Node* pHead;
	Node* pTail;
}list;
void Create(list& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void add_fist(list& l)
{
	int MS, Nam, GT;
	float Diem;
	string ten;
	bool k = false;
	Node* p = new Node;
	v:if (p == NULL)exit(1);
	do {

		cout << "MASO: "; cin >> MS;cin.ignore();
		cout << "HOTEN: "; getline(cin, ten);

		cout << "NAMSINH: "; cin >> Nam;
		cout << "GIOI TINH: "; cin >> GT;
		cout << "DIEM TB: "; cin >> Diem;
		cout << endl << endl;
		if ((GT == 1 || GT == 0) && (Diem >= 0 && Diem <= 10))
			k = true;
		else {
			cout << "NHAP SAI !! VUI LONG NHAP LAI..." << endl;
			goto v;
		}

	} while (k == false);
	p->data.MSSV = MS;
	p->data.Hoten = ten;
	p->data.Namsinh = Nam;
	p->data.Gioitinh = GT;
	p->data.DiemTB = Diem;
	p->next = NULL;
	p->pre = NULL;
	Node* h = new Node;
	if (h == NULL)exit(1);
	h = l.pHead;
	while (h)
	{
		if (MS == h->data.MSSV)
		{
			cout << "!!!! BAN DA NHAP SAI-PHUONG THUC NAY SE BI HUY\nVUI LONG THUC HIEN LAI ";
			exit(0);
		}
		h = h->next;
	}
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pHead->pre = p;
		p->next = l.pHead;
		l.pHead = p;
	}


}
void in(list l)
{
	cout << endl;
	Node* p = l.pHead;
	while (p != NULL)
	{
		cout << "Ma so: " << p->data.MSSV << endl;
		cout << "Ho va Ten: " << p->data.Hoten << endl;
		cout << "Nam sinh: " << p->data.Namsinh << endl;
		cout << "Gioi Tinh: ";
		if (p->data.Gioitinh == 1)
			cout << "NAM";
		else cout << "NU";
		cout << endl;
		cout << "Diem TB: " << p->data.DiemTB << endl;
		p = p->next;
	}
}
void SapXepMS(list& l)
{
	for (Node* p = l.pHead; p != NULL; p = p->next)
	{
		for (Node* k = p->next; k != NULL; k = k->next)
		{

			if (p->data.MSSV > k->data.MSSV)
			{
				Sinhvien Data;
				Data = p->data;
				p->data = k->data;
				k->data = Data;
			}
		}
	}
}
void SapXepDTB(list& l)
{
	for (Node* p = l.pHead; p != NULL; p = p->next)
	{
		for (Node* k = p->next; k != NULL; k = k->next)
		{

			if (p->data.DiemTB < k->data.DiemTB)
			{
				Sinhvien Data;
				Data = p->data;
				p->data = k->data;
				k->data = Data;
			}
		}
	}
}
int main()
{
	int dem;
	list l;
	Create(l);
	int x;
	cout << "HAY NHAP SO SV:";
	cin >> x;
	for (int i = 0;i < x;i++)
		add_fist(l);//them phan tu vao cuoi list
	cout << "LIST SV VUA NHAP:\n";
	in(l);
	cout << "SAP XEP THEO MA SO:\n";
	SapXepMS(l);
	in(l);
	cout << "SAP XEP THEO DIEM:\n";
	SapXepDTB(l);
	in(l);


}