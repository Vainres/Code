#include <iostream>
#include<conio.h>
int f = 0,s,gt,bai6=0,bai9=0,xx;
using namespace std;
typedef struct tagNode
{
	int info;
	struct tagNode* pNext;
}Node;
typedef struct tagList
{
	struct tagNode* pHead;
	struct tagNode* pTail;
}List;
void CreateList(List& I)
{
	I.pHead = NULL;
	I.pTail = NULL;

}
Node* CreateNode(int x)
{
	Node* p = new Node;
	if (p == NULL) exit(1);
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddHead(List& I, Node* p)
{
	if (I.pHead == NULL)
	{
		I.pHead = p;
		I.pTail = I.pHead;
	}
	else
	{
		p->pNext = I.pHead;
		I.pHead = p;
	}
}
int PrintList(List I, int nut) {
	Node* p;   p = I.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
	return 0;
}
int PrintListReverse(List I, int nut) {
	Node* p;   p = I.pTail;
	while (p != NULL)
	{
		cout << p->info << " ";
		
		if (f == nut) s = p->info;
		if (p->info == gt) bai6=1;
		p = p->pNext;
		f++;
	}
	cout << endl;
	return 0;
}
void Dem(List I)
{
	Node* phu;
	Node* sp;
	Node* cc;
	phu = I.pHead;
	sp = I.pHead->pNext;
	cc = sp->pNext;
	I.pHead->pNext = NULL;
	while (cc->pNext!= NULL)
	{
		sp->pNext = phu;
		phu = sp;
		sp = cc;
		cc = sp->pNext;
	}
	sp->pNext = phu;
	cc->pNext = sp;
	I.pTail = cc;
}
void Bai9(List I) {
	Node* p;   p = I.pHead;
	Node* spp=p;
	while (p != NULL)
	{
		if (xx == p->info)
		{
			bai9 = 1;
			spp->pNext = p->pNext;
			delete p;
			p = spp->pNext;
		}
		spp = p;
		p = p->pNext;
	}
	cout << endl;
}
void bai12(List& l) {
	Node* p;   while (l.pHead != NULL);
}
int main()
{
	int sl,nut;
	cout << "Nhap so nut : " ;
	cin >> sl;
	cout << "Nhap nut can tim gia tri : ";
	cin >> nut;
	cout << "Nhap gia tri can tim : ";
	cin >> gt;
	cout << "Nhap gia tri can xoa : ";
	cin >> xx;
	List I;
	CreateList(I);
	for (int i = 0;i < sl;i++)
	{
		int x;
		cout << "Nhap data :";
		cin >> x;
		Node* p = CreateNode(x);
		if (p->info == 0) break;
		AddHead(I,p);
	}
	cout << "Bai 5 :Danh sach dao nguoc :";
	PrintList(I, nut);cout << endl;
	Dem(I);
	cout << "Bai 1 :Xuat danh sach :";
	PrintListReverse(I, nut);cout << endl;
	cout << "Bai 3 :Dem so phan tu :" << f << endl;
	cout << "Bai 4 :Gia tri thu n can tim :" << s << endl;
	cout << "Bai 6 : " << bai6 << endl;
	//Bai9(I);cout << "Bai 9 :Xoa gia tri : " << bai9 << endl;

	return 0;
}