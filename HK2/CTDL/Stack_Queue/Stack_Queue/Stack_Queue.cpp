// Stack_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node* pNext;
};
struct Stack
{
	Node* Head;
	Node* Tail;
};
Node* CreateNode(int a)
{
	Node* p = new Node;
	p->info = a;
	p->pNext = NULL;
	return p;
}
void CreateStack(Stack& s)
{
	s.Head = NULL;
	s.Tail = NULL;
}

void Push(Stack& s, Node* p)
{
	if (s.Head == NULL) s.Head = s.Tail = p;
	else
	{
		p->pNext = s.Head;
		s.Head = p;
	}
}

Node* Pop(Stack& s)
{
	Node* p = new Node;
	p = s.Head;
	if (s.Head != NULL)
	{	
		s.Head = s.Head->pNext;
		if (p->pNext == NULL) s.Tail = NULL;
	}
	return p;
}
void Savenum(Stack& s)
{
	CreateStack(s);
	char c;
	do
	{
		c = getchar();
		if (c >= '0' && c <= '9') Push(s, CreateNode(c - 48));
	} while (c!=10);
}

Stack Performance(Stack s, int n)
{
	Node* p;
	Stack B;
	CreateStack(B);
	p = s.Head;
	int k=0,f=1;
	for (p = Pop(s);p != NULL; p = Pop(s))
	{
		k = k + p->info * f;
		f *= 10;
	}
	while (k!=0)
	{
		Push(B, CreateNode(k % n));
			k /= n;
	}
	return B;
}
void Print(Stack B)
{
	Node* p = new Node;
	p = B.Head;
	char a[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	for (;p != NULL;p = p->pNext)
	{
		cout << a[p->info];
	}
}
int main()
{
	Stack A;
	int heso[3] = { 2,8,16 };
    cout << "Nhap so:";
	Savenum(A);
	for (int i = 0;i < 3;i++) 
	{
		Print(Performance(A, heso[i]));
		cout << endl;
	}

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
