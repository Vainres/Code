#include<iostream>
#include<stdio.h>

struct node
{
	int info;
	node* next;
};

struct list
{
	node* head;
	node* tail;
};

void createList(list& l)
{
	l.head = NULL;
	l.tail = NULL;
};

node* createNode(int n)
{
	if (n < 0) n = -n;
	node* p = new node;
	p->info = n;
	p->next = NULL;
	return p;
}

void addHead(list& l, node* p)
{
	if (l.head == NULL) l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

void addTail(list& l, node* p)
{
	if (l.head == NULL) l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void removeHead(list& l)
{
	node* p = l.head;
	l.head = l.head->next;
	delete p;
	if (l.head == NULL) l.tail = NULL;
}

void printList(list l)
{

	node* p = l.head;
	while (p != NULL)
	{
		std::cout << p->info;
		p = p->next;
	}
	std::cout << std::endl;
}

void cinNum(list& l)
{
	createList(l);
	char n;
	do
	{
		n = getchar();
		if ((n >= '0') && (n <= '9'))
			addHead(l, createNode(n - 48));
	} while (n != 10);

}

void simpleList(list& l)
{
	node* p = l.head;
	while ((p->next != NULL) && (p->info == 0))
	{
		p = p->next;
		removeHead(l);
	}
}

list reverseList(list l)
{
	list answer; createList(answer);
	node* p = l.head;
	while (p != NULL)
	{
		addHead(answer, createNode(p->info));
		p = p->next;
	}
	return answer;
}

list add(list a, list b)
{
	list answer; createList(answer);
	int mind = 0;
	node* pA = a.head, * pB = b.head;
	while ((pA != NULL) || (pB != NULL))
	{
		int nA = 0, nB = 0;
		if (pA != NULL)
		{
			nA = pA->info;
			pA = pA->next;
		}
		if (pB != NULL)
		{
			nB = pB->info;
			pB = pB->next;
		}
		int n = nA + nB + mind;
		addTail(answer, createNode(n % 10));
		mind = n / 10;
	}

	return answer;
}

list sud(list a, list b)
{
	list answer; createList(answer);
	int mind = 0;
	node* pA = a.head, * pB = b.head;
	while ((pA != NULL) || (pB != NULL))
	{
		int nA = 0, nB = 0;
		if (pA != NULL)
		{
			nA = pA->info;
			pA = pA->next;
		}
		if (pB != NULL)
		{
			nB = pB->info;
			pB = pB->next;
		}
		nB += mind;
		if (nA < nB)
		{
			nA += 10;
			mind = 1;
		}
		addHead(answer, createNode(nA - nB));
	}
	simpleList(answer);

	return answer;
}

list multiNode(list a, int nB)
{
	list answer; createList(answer);
	int mind = 0;
	node* pA = a.head;
	while (pA != NULL)
	{
		int nA;
		nA = pA->info;
		pA = pA->next;
		int n = nA * nB + mind;
		addHead(answer, createNode(n % 10));
		mind = n / 10;
	}
	simpleList(answer);

	return reverseList(answer);
}

list multi(list a, list b)
{
	list answer; createList(answer);
	node* pB = b.head;
	while (pB != NULL)
	{
		answer = add(answer, multiNode(a, pB->info));
		addHead(a, createNode(0));
		pB = pB->next;
	}

	return answer;
}

int main()
{
	//khoi tao 2 so lon
	list num1, num2;
	std::cout << "Num 1(so lon): "; cinNum(num1);
	std::cout << "Num 2(so nho): "; cinNum(num2);

	//khoi tao phep tinh
	std::string action;
	std::cout << "Action(add, sud, multi): ";
	std::cin >> action;

	//Tinh va in answer;
	if (action == "add")  printList(reverseList(add(num1, num2)));
	if (action == "sud")  printList(sud(num1, num2));
	if (action == "multi")printList(reverseList(multi(num1, num2)));

	return 0;
}