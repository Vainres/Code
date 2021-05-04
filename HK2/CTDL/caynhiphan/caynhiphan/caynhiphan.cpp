// caynhiphan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* pLeft;
	struct node* pRight;
};

typedef struct node NODE;
typedef NODE* TREE;

void khoitao(TREE& t)
{
	t = NULL;
}

void AddNode(TREE& t, int x)
{
	if (t == NULL)
	{
		NODE* p=new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (x > t->data) AddNode(t->pRight, x);
		else if (x < t->data) AddNode(t->pLeft, x);
	}
}

void Nhap(TREE &t)
{
	int x;
	cout << "Nhap data ";
	cin >> x;
	AddNode(t, x);
}

void Xuat(TREE t)
{
	if (t == NULL) return;
	Xuat(t->pLeft);
	cout << t->data << " ";
	Xuat(t->pRight);
	
}
int dem = 0;
bool Demla(TREE t)
{
	
	if (t != NULL)
	{
		bool a=Demla(t->pLeft);
		bool b=Demla(t->pRight);
		if (a == false && b == false) dem++;
	}
	else return false;
	return true;
}
int Dem(TREE t)
{

	if (t != NULL)
	{
		int a = Dem(t->pLeft);
		int b = Dem(t->pRight);
		int c=b+a;
		if (c==1) dem++;
	}
	else return 0;
	return 1;
}
void Dempt(TREE t,int a,int b)
{

	if (t != NULL)
	{
		Dempt(t->pLeft,a,b+1);
		Dempt(t->pRight,a,b+1);
		if (b == a) cout<<t->data<<endl;
	}
}

int main()
{
	TREE t;
	khoitao(t);
	while (true)
	{
		int x;
		cout << "1.Nhap Node" << endl;
		cout << "2.Xuat" << endl;
		cin >> x;
		if (x == 1) Nhap(t);
		if (x == 2)
		{
			Xuat(t);
			Dem(t);
			Dempt(t, 1, 4);
			cout << dem;
			return 0;
		}
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
