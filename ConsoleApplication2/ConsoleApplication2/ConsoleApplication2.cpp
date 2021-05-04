// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;
typedef Node* TREE;
void CreateTree(TREE& tree)
{
	tree = NULL;
}

void AddNode(TREE& tree, int a)
{
	if (tree == NULL)
	{
		Node* p = new Node;
		p->data = a;
		p->left = NULL;
		p->right = NULL;
		tree = p;
	}
	else {
		if (a > tree->data)AddNode(tree->right, a);
		else if (a < tree->data) AddNode(tree->left, a);
	}
}

void Nhap(TREE& tree)
{
	int a;
	//cout << "Nhap data : ";
	cin >> a;
	AddNode(tree, a);

}

void Xet(TREE& tree,int a)
{
	if (tree == NULL) return;
	Xet(tree->left,a+1);
	cout << tree->data << " ";
	Xet(tree->right,a+1);

}
int sp(TREE& tree)
{
	int a = 1;
	int b = 1;
	if (tree->left == NULL) a = 0;
	if (tree->right == NULL) b = 0;
	return a + b;
}
void Xet(TREE& tree)
{
	if (tree == NULL) return ;
	Xet(tree->left);
	cout << sp(tree);
	Xet(tree->right);
}

int max(int a, int b)
{
	if (a >= b) return a;
	return b;
}
int chieucao(TREE& tree)
{
	int a, b;
	if (tree == NULL) return 0;
	a=chieucao(tree->left);
	b=chieucao(tree->right);
	return 1 + max(a, b);
}
void xoalonnhat(TREE& tree)
{
	if (tree->right == NULL) {
		if (tree->left != NULL) {
			Node* p = new Node;
			p = tree;
			tree = tree->left;
			delete p;
		}
		else tree = NULL;
		return;
	}
	xoalonnhat(tree->right);
}
int main()
{
	int sl,a,b,max,min;
	TREE tree;
	CreateTree(tree);
	cin >> sl ;
	for(int i=0;i<sl;i++)
		Nhap(tree);
	Xet(tree);
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
