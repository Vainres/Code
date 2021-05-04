#include <iostream>

struct node
{
	int info;
	node* next;
};

struct stack
{
	node* head;
	node* tail;
};

node* createNode(int n)
{
	node* p = new node;
	p->info = n;
	p->next = NULL;
	return p;
}

void createStack(stack& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void push(stack& l, node* p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

node* pop(stack& l)
{
	node* p = l.head;

	if (l.head != NULL)
	{
		l.head = l.head->next;
		if (l.head == NULL)
			l.tail == NULL;
	}

	return p;
}

void cinStack(stack& l)
{
	createStack(l);
	char n;
	do
	{
		n = getchar();
		if ((n >= '0') && (n <= '9'))
			push(l, createNode(n - 48));
	} while (n != 10);
}

void printStack(stack l, char* A)
{
	if (l.head == NULL) std::cout << "noNode!";
	for (node* p = l.head; p != NULL; p = p->next)
		std::cout << A[p->info];
	std::cout << std::endl;
}

stack brow(stack l, int coso)
{
	stack answer; createStack(answer);
	int np = 0, adress = 1;
	for (node* p = pop(l); p != NULL; p = pop(l))
	{
		np = np + p->info * adress;
		adress *= 10;
	}
	while (np != 0)
	{
		push(answer, createNode(np % coso));
		np = np / coso;
	}
	return answer;
}

int main()
{
	stack n;
	std::cout << "Cet N: ";
	cinStack(n);
	int coso[3] = { 2, 8, 16 };
	char A[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	for (int i = 0; i < 3; i++)
	{
		int p = coso[i];
		std::string s = (p / 16 == 0) ? (" : ") : (": ");
		std::cout << "He " << p << s;
		printStack(brow(n, p), A);
	}

	return 0;
}