#include <iostream>

using namespace std;

struct node
{
	int info;
	node* left;
	node* right;
};

typedef node* tree;

node* createNode(int n)
{
	node* p = new node;
	p->info = n;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void createTree(tree& t)
{
	t = NULL;
}

void addNode(tree& t, node* p)
{
	if (t == NULL)
		t = p;
	else
	{
		if (p->info < t->info)
			addNode(t->left, p);
		else if (p->info > t->info)
			addNode(t->right, p);
	}
}

void LNR(tree t, int k, int kp)
{
	if (t == NULL)
		return;
	if (kp == k)
		cout << t->info << " ";
	else
	{
		LNR(t->left, k, kp + 1);
		LNR(t->right, k, kp + 1);
	}
}

int main()
{
	tree t;
	createTree(t);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		addNode(t, createNode(x));
	}
	int low, high;
	cin >> low >> high;

	if (low > high)
	{
		int x = low;
		low = high;
		high = x;
	}

	for (int i = low; i <= high; i++)
	{
		LNR(t, i, 0);
		cout << endl;
	}

	return 0;
}