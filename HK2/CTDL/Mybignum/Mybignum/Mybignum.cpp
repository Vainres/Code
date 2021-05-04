// Mybignum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int k;
struct Node
{
	int info;
	Node* pNext;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

void CreateList(List& l)
{
	l.pHead = NULL;
	l.pTail=NULL;
}

Node* CreateNode(int n)
{
	Node* p = new Node;
	p->info = n;
	p->pNext = NULL;
	return p;
}

void AddHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTail(List& l, Node* p)
{
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void SaveNum(List& l)
{
	CreateList(l);
	char n;
	do
	{
		n = getchar();
		if ((n >= '0') && (n <= '9')) AddHead(l, CreateNode(n - 48));
	} while (n!=10);

}

void ADD(List& A, List& B)
{
	Node* pA;
	Node* pB;
	pA = A.pHead;
	pB = B.pHead;
	while (pA->pNext != NULL && pB->pNext != NULL)
	{
		int s = 0;
		s = pA->info + pB->info;
		if (s > 9)
		{
			if (pA->pNext != NULL)
			{
				pA->pNext->info++;
				pA->info = s -10;
			}
			
		}
		else pA->info = s;
		pA = pA->pNext;
		pB = pB->pNext;
	}
	if (pB->pNext != NULL) {
		pA->pNext = pB->pNext;
		A.pTail = B.pTail;
	}

	pA->info += pB->info;
	while(pA->info > 9&&pA->pNext!=NULL)
	{
		pA->pNext->info++;
		pA->info -=10;
		pA = pA->pNext;
	}
}

void SUB(List& A, List& B)
{
	Node* pA;
	Node* pB;
	pA = A.pHead;
	pB = B.pHead;
	while (pA->pNext != NULL && pB->pNext != NULL)
	{
		int s = 0;
		s = pA->info - pB->info;
		if (s <0)
		{
			if (pA->pNext != NULL)
			{
				pA->pNext->info--;
				pA->info =pA->info +10-pB->info ;
			}

		}
		else pA->info = s;
		pA = pA->pNext;
		pB = pB->pNext;
	}
	if (pB->pNext != NULL) {
		pA->pNext = pB->pNext;
		A.pTail = B.pTail;
	}

	pA->info -= pB->info;
	while (pA->info < 0 && pA->pNext != NULL)
	{
		pA->pNext->info--;
		pA->info +=10;
		pA = pA->pNext;
	}
}

void Duplicate(List l,List C)
{
	Node* p;
	p = l.pHead;
	
	int a;
	while (p != NULL)
	{
		a = p->info;
		addTail(C,CreateNode(a));
		p = p->pNext;
	}
}
void DaoNguoc(List I)
{
	Node* phu;
	Node* sp;
	Node* cc;
	phu = I.pHead;
	sp = I.pHead->pNext;
	cc = sp->pNext;
	I.pHead->pNext = NULL;
	while (cc->pNext != NULL)
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

int PrintListReverse(List I) {
	Node* p;   p = I.pTail;
	if (p->info != 0) cout << p->info;
	p = p->pNext;
	while (p!= NULL)
	{
		cout << p->info;
		p = p->pNext;
	}
	cout << endl;
	return 0;
}

int PrintList(List I) {
	Node* p;   p = I.pHead;
	while (p != NULL)
	{
		cout << p->info ;
		p = p->pNext;
	}
	cout << endl;
	return 0;
}

int main()
{
	List A, B,C;
	CreateList(C);
	string a;
	cout << "Nhap so A: ";SaveNum(A);	
	cout << "Nhap so B: ";SaveNum(B);
	cout << "Action :"; cin >> a ;
	if (a == "add") ADD(A, B);
	if (a == "sub") SUB(A, B);
	//PrintList(A);
	Duplicate(A,C);
	PrintList(C);
	DaoNguoc(A);
	//PrintListReverse(A);
	
	

}
