// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node* Left;
	Node* Right;
	//Node() : Node(0) {}
	Node(int n) : info(n), Left(NULL), Right(NULL) {}
};

typedef Node* tree;

void AddNode(tree& t, int x)
{
	if (t == NULL)
		t = new Node(x);
	else
	{
		if (t->info > x)
			AddNode(t->Left, x);
		else if (t->info < x)
			AddNode(t->Right, x);
	}
}

void Print(tree& t)
{
	if (t == NULL) return;
	Print(t->Left);
	cout << t->info;
	Print(t->Right);
}

int main()
{
	//long long a = -5555555555555555555;
	//cout << cout.width(50) << right << a << endl;;
	tree t(NULL);
	//Node k(5);
	//if (k.Left == NULL) cout << "ss";
	//cout << k.info;
	int sl;
	cin >> sl;
	for (int i = 0;i < sl;i++)
	{
		int x;
		cin >> x;
		AddNode(t, x);
	}
	Print(t);
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
