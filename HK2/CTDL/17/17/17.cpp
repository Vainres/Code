#include <iostream>
#include<conio.h>
int f = 0, s, gt, bai6 = 0, bai9 = 0, xx;
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
		I.pTail->pNext = p;
		I.pTail = p;
	}
}
int PrintList(List I) 
{
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
		if (p->info == gt) bai6 = 1;
		p = p->pNext;
		f++;
	}
	cout << endl;
	return 0;
}
void Bai17(List A, List B,List C)
{
	Node* pA;
	pA = A.pHead;
	Node* pB;
	pB = B.pHead;
	while (pA != NULL&&pB!=NULL)
	{
		if (pA->info <= pB->info)
		{
			AddHead(C, pA);
			pA = pA->pNext;
		}
		else
		{
			AddHead(C, pB);
			pB = pB->pNext;
		}
	}
	if (pA!=NULL)
	{
		C.pTail->pNext = pA;
		C.pTail = A.pTail;
	}
	else
	{
		C.pTail->pNext = pB;
		C.pTail = B.pTail;
	}
}
int main()
{
	int sl,slB;

	List I, B, C;
	CreateList(I);
	CreateList(B);
	CreateList(C);
	cout << "Nhap so nut A : ";
	cin >> sl;
	for (int i = 0;i < sl;i++)
	{
		int x;
		cout << "Nhap data :";
		cin >> x;
		Node* p = CreateNode(x);
		if (p->info == 0) break;
		AddHead(I, p);
	}
	cout << "Nhap so nut B: ";
	cin >> slB;
	for (int i = 0;i < slB;i++)
	{
		int x;
		cout << "Nhap data :";
		cin >> x;
		Node* p = CreateNode(x);
		if (p->info == 0) break;
		AddHead(B, p);
	}
	Bai17(I, B, C);
	PrintList(I);
	return 0;
}
