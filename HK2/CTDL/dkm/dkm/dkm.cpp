#include <iostream>
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
void AddHead(List& l, Node* p)
{
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(List& l, Node* p)
{
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
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
List Merge(List A, List B, List C)
{
	Node* pA;
	pA = A.pHead;
	Node* pB;
	pB = B.pHead;
	while (pA != NULL && pB != NULL)
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
	while (pA != NULL)
	{
		AddHead(C, pA);
	}
	while (pB!=NULL)
	{
		AddHead(C, pB);
	}
	return C;
}

List Separate(List l, List C)
{
	PrintList(l);
	if (l.pHead == l.pTail) return l;
	Node* p = l.pHead;
	List A, B;
	CreateList(A);
	CreateList(B);
	while (p != NULL)
	{
		Node* a = CreateNode(p->info);
		AddTail(A, a);
		p = p->pNext;
		if (p == NULL) break;
		Node* b = CreateNode(p->info);
		AddTail(B, b);
		p = p->pNext;
	}
	
	PrintList(C);
	return Merge(Separate(A, C), Separate(B, C), C);;
}



int main()
{
	int sl;
	List A, C;
	CreateList(A);
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
		AddTail(A, p);
	}
	PrintList(Separate(A, C));
}
